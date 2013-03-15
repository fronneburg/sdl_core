//
// Copyright (c) 2013 Ford Motor Company
//

#ifndef NSSMARTDEVICELINKKRPCV2_ENCODEDSYNCPDATA_RESPONSE_INCLUDE
#define NSSMARTDEVICELINKKRPCV2_ENCODEDSYNCPDATA_RESPONSE_INCLUDE

#include "JSONHandler/SDLRPCResponse.h"

/*
  interface Ford Sync RAPI
  version   2.0O
  date      2012-11-02
  generated at  Thu Jan 24 06:36:23 2013
  source stamp  Thu Jan 24 06:35:41 2013
  author    RC
*/

namespace NsSmartDeviceLinkRPCV2
{
    class EncodedSyncPData_response : public NsSmartDeviceLinkRPC::SDLRPCResponse
    {
    public:
        EncodedSyncPData_response(const EncodedSyncPData_response& c);
        EncodedSyncPData_response(void);

        virtual ~EncodedSyncPData_response(void);

        EncodedSyncPData_response& operator =(const EncodedSyncPData_response&);

        bool checkIntegrity(void);

    private:
        friend class EncodedSyncPData_responseMarshaller;
    };
}

#endif
