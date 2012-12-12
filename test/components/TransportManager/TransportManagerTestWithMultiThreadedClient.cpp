/*
    Tests Transport Manager behavior with single TM client which sents a lot of data from many different threads (more than 200).
    Sent data was sent back from device adapter to TM client and validated
 */
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../../../src/components/TransportManager/src/IDeviceAdapter.hpp"
#include "../../../src/components/TransportManager/src/CTransportManager.hpp"
#include "TransportManager/ITransportManagerDataListener.hpp"
#include "TransportManager/ITransportManagerDeviceListener.hpp"

#include <stddef.h>
#include <stdio.h>
#include <vector>
#include <map>

using ::testing::_;
using ::testing::Invoke;
using ::testing::StrEq;
using ::testing::Property;
using ::testing::Field;
using ::testing::Contains;
using ::testing::AllOf;
using ::testing::ElementsAre;
using ::testing::ContainerEq;
using ::testing::Eq;
using ::testing::InSequence;

using namespace NsAppLink::NsTransportManager;

namespace test { namespace components { namespace TransportManager { namespace TestWithMultiThreadedClient {

    // ---------------- TEST DATA ---------------- //
    namespace Data
    {
        static const tDeviceHandle DeviceHandle = 123;
        static const EDeviceType DeviceType = DeviceBluetooth;
        static const std::string UserFriendlyName("MY USER FRIENDLY NAME");
        static const std::string UniqueDeviceId("MY_UNIQUE_DEVICE_ID");

        static const tConnectionHandle ConnectionHandle = 666;

        static const int BaseSequenceNumber = 1;
        static const int NumberOfThreads    = 113;
        static const int NumberOfFramesPerThread = 53;
        static const int TotalNumberOfFrames = NumberOfThreads * NumberOfFramesPerThread;
        static const int FrameSize = 323;
    }

    // ---------------- TEST CLASSES ---------------- //

    /**
     * @brief Class that represents custom device adapter that will send known data
     *        and check it's methods calls
     **/
    class MockDeviceAdapter : public IDeviceAdapter
    {
    public:
        MockDeviceAdapter(IDeviceAdapterListener & Listener, IHandleGenerator & HandleGenerator)
        : mListener(Listener)
        , mHandleGenerator(HandleGenerator)
        , mLogger(log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("TransportManagerTest")))
        {
        }

        virtual EDeviceType getDeviceType(void ) const
        {
            return DeviceBluetooth;
        }
        MOCK_METHOD1(connectDevice, void (const tDeviceHandle DeviceHandle));
        MOCK_METHOD1(disconnectDevice, void (const tDeviceHandle DeviceHandle));
        MOCK_METHOD0(run, void());
        MOCK_METHOD0(scanForNewDevices, void());
        MOCK_METHOD4(sendFrame, void(tConnectionHandle ConnectionHandle, const uint8_t* Data, size_t DataSize, int UserData));

        void doScanForNewDevices()
        {
            LOG4CPLUS_INFO_EXT(mLogger, "\n-------------- Scanning new devices -----------------");
            SInternalDeviceInfo deviceInfo;
            deviceInfo.mDeviceHandle = Data::DeviceHandle;
            deviceInfo.mUniqueDeviceId = Data::UniqueDeviceId;
            deviceInfo.mUserFriendlyName = Data::UserFriendlyName;

            tInternalDeviceList list;
            list.push_back(deviceInfo);

            LOG4CPLUS_INFO_EXT(mLogger, "\n-------------- Sending device list update -----------------");
            mListener.onDeviceListUpdated(this, list);
        }

        void doConnectDevice(const tDeviceHandle DeviceHandle)
        {
            LOG4CPLUS_INFO_EXT(mLogger, "\n-------------- Connecting device -----------------");
            // Application connect

            SDeviceInfo deviceInfo;
            deviceInfo.mDeviceHandle = Data::DeviceHandle;
            deviceInfo.mUniqueDeviceId = Data::UniqueDeviceId;
            deviceInfo.mUserFriendlyName = Data::UserFriendlyName;

            LOG4CPLUS_INFO_EXT(mLogger, "\n-------------- Sending ApplicationConnected -----------------");
            mListener.onApplicationConnected(this, deviceInfo, Data::ConnectionHandle);
        }

        void doSendFrame(tConnectionHandle ConnectionHandle, const uint8_t* Data, size_t DataSize, int UserData)
        {
            LOG4CPLUS_INFO_EXT(mLogger, "\n-------------- doSendFrame called -----------------");

            LOG4CPLUS_INFO_EXT(mLogger, "\n-------------- Sending frame back to TransportManager. DataSize: " << DataSize << "--------------");

            // Loop back. Each recevied frame is sent back.
            mListener.onFrameReceived(this, ConnectionHandle, Data, DataSize);

            LOG4CPLUS_INFO_EXT(mLogger, "\n-------------- Calling onFrameSendCompleted. UserData: " << UserData << "--------------");

            mListener.onFrameSendCompleted(this, Data::ConnectionHandle, UserData, SendStatusOK);
        }

        void doDisconnectDevice(const tDeviceHandle DeviceHandle)
        {
            LOG4CPLUS_INFO_EXT(mLogger, "\n-------------- doDisconnectDevice -----------------");
            SDeviceInfo deviceInfo;
            deviceInfo.mDeviceHandle = Data::DeviceHandle;
            deviceInfo.mUniqueDeviceId = Data::UniqueDeviceId;
            deviceInfo.mUserFriendlyName = Data::UserFriendlyName;

            LOG4CPLUS_INFO_EXT(mLogger, "\n-------------- sending ApplicationDisconnected -----------------");
            mListener.onApplicationDisconnected(this, deviceInfo, Data::ConnectionHandle);
        }

    protected:
        IDeviceAdapterListener & mListener;
        IHandleGenerator & mHandleGenerator;
        Logger mLogger;
    };

    /**
     * @brief Custom transport manager client that will check data, sent by transport manager
     **/
    class MockTransportManagerClient : public ITransportManagerDataListener
                                     , public ITransportManagerDeviceListener
    {
    public:

        MockTransportManagerClient(ITransportManager & TransportManager)
        : mTransportManager(TransportManager)
        , mDeviceList()
        , mFrameSequenceNumber(-1)
        , mLogger(log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("TransportManagerTest")))
        , mThreads()
        , mSendFrameMap()
        , mFrameReceivedNumberMutex()
        , mFrameSendCompletedMutex()
        , mNumberOfReceivedFrames(0)
        , mNumberOfCompletelySentFrames(0)
        , mSequenceNumber(Data::BaseSequenceNumber)
        , mSequenceNumberMutex()
        {
            pthread_mutex_init(&mFrameReceivedNumberMutex, 0);
            pthread_mutex_init(&mFrameSendCompletedMutex, 0);
            pthread_mutex_init(&mSequenceNumberMutex, 0);
        }

        MOCK_METHOD2(onApplicationConnected, void(const SDeviceInfo& ConnectedDevice, const tConnectionHandle Connection));
        MOCK_METHOD2(onApplicationDisconnected, void(const SDeviceInfo& DisconnectedDevice, const tConnectionHandle Connection));
        MOCK_METHOD1(onDeviceListUpdated, void(const tDeviceList& DeviceList));
        MOCK_METHOD3(onFrameReceived, void(tConnectionHandle ConnectionHandle, const uint8_t* Data, size_t DataSize));
        MOCK_METHOD3(onFrameSendCompleted, void(tConnectionHandle ConnectionHandle, int UserData, ESendStatus SendStatus));

        void doDeviceListUpdated(const tDeviceList& DeviceList)
        {
            LOG4CPLUS_INFO_EXT(mLogger, "\n-------------- doDeviceListUpdated -----------------");
            mDeviceList = DeviceList;

            tDeviceList::const_iterator device;
            for(device = mDeviceList.begin(); device != mDeviceList.end(); ++device)
            {
                mTransportManager.connectDevice(device->mDeviceHandle);
            }
        }

        void doApplicationConnected(const SDeviceInfo& ConnectedDevice, const tConnectionHandle Connection)
        {
            LOG4CPLUS_INFO_EXT(mLogger, "\n-------------- doApplicationConnected -----------------");

            for (int i = 0; i < Data::NumberOfThreads; ++i)
            {
                pthread_t thread;
                pthread_create(&thread, NULL, &threadSendFrames, static_cast<void*>(this));
                mThreads.push_back(thread);
            }
        }

        void doFrameSendCompleted(tConnectionHandle ConnectionHandle, int UserData, ESendStatus SendStatus)
        {
            LOG4CPLUS_INFO_EXT(mLogger, "\n-------------- doFrameSendCompleted -----------------");

            pthread_mutex_lock(&mFrameSendCompletedMutex);

            mNumberOfCompletelySentFrames++;

            uint8_t *pData = mSendFrameMap[UserData];

            delete pData;
            mSendFrameMap.erase(UserData);

            pthread_mutex_unlock(&mFrameSendCompletedMutex);

            LOG4CPLUS_INFO_EXT(mLogger, "\n-------------- Number of completely sent frames: "
                << mNumberOfCompletelySentFrames << " -----------------");
        }

        void doFrameReceived(tConnectionHandle ConnectionHandle, const uint8_t* Data, size_t DataSize)
        {
            LOG4CPLUS_INFO_EXT(mLogger, "\n-------------- doFrameReceived -----------------");

            pthread_mutex_lock(&mFrameReceivedNumberMutex);

            mNumberOfReceivedFrames++;

            pthread_mutex_unlock(&mFrameReceivedNumberMutex);

            LOG4CPLUS_INFO_EXT(mLogger, "\n-------------- Number of received frames: " << mNumberOfReceivedFrames << " -----------------");
        }

        void disconnectAllDevices(void)
        {
            tDeviceList::const_iterator device;

            for(device = mDeviceList.begin(); device != mDeviceList.end(); ++device)
            {
                mTransportManager.disconnectDevice(device->mDeviceHandle);
            }

            ASSERT_EQ(mNumberOfCompletelySentFrames, Data::TotalNumberOfFrames) << "Wrong number of send frame confirmation";
            ASSERT_EQ(mNumberOfReceivedFrames, Data::TotalNumberOfFrames) << "Wrong number of received frames";
        }

        void waitForAllThreads(void)
        {
            int timeOut = 60;   // sec
            bool finished = false;

            while(timeOut)
            {
                pthread_mutex_lock(&mFrameReceivedNumberMutex);
                finished = mNumberOfReceivedFrames == Data::TotalNumberOfFrames;
                pthread_mutex_unlock(&mFrameReceivedNumberMutex);

                if (finished)
                {
                    break;
                }
                else
                {
                    sleep(1);
                    timeOut--;
                }
            }

            ASSERT_NE(timeOut, 0) << "Timeout waiting to receive all the frames";

            for (int i = 0; i < Data::NumberOfThreads; ++i)
            {
                pthread_join(mThreads[i], NULL);
            }
        }

    private:

        static void* threadSendFrames(void* Data)
        {
            MockTransportManagerClient *pTMClient = static_cast<MockTransportManagerClient*>(Data);

            LOG4CPLUS_INFO_EXT(pTMClient->mLogger, "\n-------------- Frame Send Thread Started -----------------");

            for (int i = 0; i < Data::NumberOfFramesPerThread; ++i)
            {
                uint8_t *pFrameData = new uint8_t[Data::FrameSize];
                uint32_t dataSize = Data::FrameSize - 12;   // minus header size

                // make a valid packet
                pFrameData[0] = 0x22;       // version 2
                pFrameData[1] = 0x0F;
                pFrameData[2] = 0x00;
                pFrameData[3] = 0x00;
                pFrameData[4] = (dataSize>>24) & 0xFF;
                pFrameData[5] = (dataSize>>16) & 0xFF;
                pFrameData[6] = (dataSize>> 8) & 0xFF;
                pFrameData[7] = (dataSize>> 0) & 0xFF;

                int sequence = pTMClient->getNextSequenceNumber();

                pTMClient->mTransportManager.sendFrame(Data::ConnectionHandle, pFrameData, Data::FrameSize, sequence);

                pthread_mutex_lock(&pTMClient->mFrameSendCompletedMutex);
                pTMClient->mSendFrameMap[sequence] = pFrameData;
                pthread_mutex_unlock(&pTMClient->mFrameSendCompletedMutex);
            }

            return 0;
        }

    int getNextSequenceNumber(void)
    {
        int nextSeq;

        pthread_mutex_lock(&mSequenceNumberMutex);
        nextSeq = ++mSequenceNumber;
        pthread_mutex_unlock(&mSequenceNumberMutex);

        return nextSeq;
    }

    protected:
        ITransportManager & mTransportManager;
        tDeviceList mDeviceList;
        int mFrameSequenceNumber;
        Logger mLogger;

        std::vector<pthread_t> mThreads;
        std::map<int, uint8_t*> mSendFrameMap;

        int mNumberOfReceivedFrames;
        pthread_mutex_t mFrameReceivedNumberMutex;

        int mNumberOfCompletelySentFrames;
        pthread_mutex_t mFrameSendCompletedMutex;

        int mSequenceNumber;
        pthread_mutex_t mSequenceNumberMutex;
    };

    /**
     * @brief Inherited transport manager class used for some small preparation of class for
     *        testing (disabling another adapters etc.)
     **/
    class TestTransportManager : public CTransportManager
    {
    public:
        TestTransportManager(void )
        : CTransportManager()
        , mLogger(log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("TransportManagerTest")))
        {
        }

        virtual ~TestTransportManager(void )
        {

        }

        virtual void initializeDeviceAdapters()
        {
            // Preparing custom device adapter
            mpDeviceAdapter = new MockDeviceAdapter(*this, *this);

            EXPECT_CALL(*mpDeviceAdapter, run()).Times(1);
            EXPECT_CALL(*mpDeviceAdapter, scanForNewDevices())
                .Times(1)
                .WillOnce(Invoke(mpDeviceAdapter, &MockDeviceAdapter::doScanForNewDevices))
            ;

            EXPECT_CALL(*mpDeviceAdapter, connectDevice(Data::DeviceHandle))
                .Times(1)
                .WillOnce(Invoke(mpDeviceAdapter, &MockDeviceAdapter::doConnectDevice))
            ;

            EXPECT_CALL(*mpDeviceAdapter, sendFrame(Data::ConnectionHandle, _, _, _))
                .Times(Data::TotalNumberOfFrames)
                .WillRepeatedly(Invoke(mpDeviceAdapter, &MockDeviceAdapter::doSendFrame))
            ;

            EXPECT_CALL(*mpDeviceAdapter, disconnectDevice(Data::DeviceHandle))
                .Times(1)
                .WillOnce(Invoke(mpDeviceAdapter, &MockDeviceAdapter::doDisconnectDevice))
            ;

            addDeviceAdapter(mpDeviceAdapter);
            LOG4CPLUS_INFO_EXT(mLogger, "Device adapters initialized");
        }

    protected:
        MockDeviceAdapter *mpDeviceAdapter;
        Logger mLogger;
    };

    // ----------------------- TESTS ----------------------- //

    TEST(test_TestWithMultiThreadedClient, MultiThreadedClientTest)
    {
        Logger logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("TransportManagerTest"));

        LOG4CPLUS_INFO_EXT(logger, "\n*************************** Starting test *****************************");
        // All expectations must be sequenced
        //InSequence dummy;

        // Creating transport manager
        TestTransportManager *pTm = new TestTransportManager();

        // Preparing transport manage client
        MockTransportManagerClient tmClient(*pTm);

        // Expected device list
        SDeviceInfo deviceInfo;
        deviceInfo.mDeviceHandle = Data::DeviceHandle;
        deviceInfo.mUniqueDeviceId = Data::UniqueDeviceId;
        deviceInfo.mUserFriendlyName = Data::UserFriendlyName;
        tDeviceList deviceList;
        deviceList.push_back(deviceInfo);

        EXPECT_CALL(tmClient, onDeviceListUpdated(ContainerEq(deviceList)))
            .Times(1)
            .WillOnce(Invoke(&tmClient, &MockTransportManagerClient::doDeviceListUpdated))
        ;

        EXPECT_CALL(tmClient, onApplicationConnected(deviceInfo, Data::ConnectionHandle))
            .Times(1)
            .WillOnce(Invoke(&tmClient, &MockTransportManagerClient::doApplicationConnected))
        ;

        EXPECT_CALL(tmClient, onFrameReceived(Data::ConnectionHandle, _, Data::FrameSize))
            .Times(Data::TotalNumberOfFrames)
            .WillRepeatedly(Invoke(&tmClient, &MockTransportManagerClient::doFrameReceived))
        ;

        EXPECT_CALL(tmClient, onFrameSendCompleted(Data::ConnectionHandle, _, SendStatusOK))
            .Times(Data::TotalNumberOfFrames)
            .WillRepeatedly(Invoke(&tmClient, &MockTransportManagerClient::doFrameSendCompleted))
        ;

        EXPECT_CALL(tmClient, onApplicationDisconnected(deviceInfo, Data::ConnectionHandle))
            .Times(1)
        ;

        // Running test

        pTm->addDataListener(&tmClient);
        pTm->addDeviceListener(&tmClient);

        LOG4CPLUS_INFO_EXT(logger, "\n*************************** Calling RUN *****************************");
        pTm->run();

        sleep(1);

        LOG4CPLUS_INFO_EXT(logger, "\n*************************** Calling SCAN FOR DEVICES *****************************");
        pTm->scanForNewDevices();

        LOG4CPLUS_INFO_EXT(logger, "\n******************* Waiting for all client thread to finish ********************");
        tmClient.waitForAllThreads();

        LOG4CPLUS_INFO_EXT(logger, "\n******************* Disconnecting all devices ********************");
        tmClient.disconnectAllDevices();

        sleep(1);

        LOG4CPLUS_INFO_EXT(logger, "\n*************************** Deleting TM and shutting down *****************************");

        // Shutdown transport manager
        delete pTm;
        pTm = 0;

    }
}}}} // End of namespaces



int main(int argc, char **argv) {
  PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT("log4cplus.properties"));
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}