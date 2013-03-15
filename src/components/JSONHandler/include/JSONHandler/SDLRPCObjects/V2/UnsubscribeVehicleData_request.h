//
// Copyright (c) 2013 Ford Motor Company
//

#ifndef NSSMARTDEVICELINKKRPCV2_UNSUBSCRIBEVEHICLEDATA_REQUEST_INCLUDE
#define NSSMARTDEVICELINKKRPCV2_UNSUBSCRIBEVEHICLEDATA_REQUEST_INCLUDE

#include <vector>

#include "VehicleDataType.h"
#include "JSONHandler/SDLRPCMessage.h"


/*
  interface	Ford Sync RAPI
  version	2.0O
  date		2012-11-02
  generated at	Thu Jan 24 06:36:23 2013
  source stamp	Thu Jan 24 06:35:41 2013
  author	RC
*/

namespace NsSmartDeviceLinkRPCV2
{

///  This function is used to unsubscribe the notifications from the subscribeVehicleData function.

  class UnsubscribeVehicleData_request : public NsSmartDeviceLinkRPC::SDLRPCMessage
  {
  public:
  
    UnsubscribeVehicleData_request(const UnsubscribeVehicleData_request& c);
    UnsubscribeVehicleData_request(void);
    
    virtual ~UnsubscribeVehicleData_request(void);
  
    bool checkIntegrity(void);

    const std::vector<VehicleDataType>& get_dataType(void) const;

    bool set_dataType(const std::vector<VehicleDataType>& dataType_);

  private:
  
    friend class UnsubscribeVehicleData_requestMarshaller;


/**
     Refers to the vehicle data elements specified by subscribeVehicleData.
     See VehicleDataType
*/
      std::vector<VehicleDataType> dataType;	//!<   [%s..%s] 
  };

}

#endif
