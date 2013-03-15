//
// Copyright (c) 2013 Ford Motor Company
//

#ifndef NSSMARTDEVICELINKRPC_PERFORMINTERACTION_RESPONSEMARSHALLER_INCLUDE
#define NSSMARTDEVICELINKRPC_PERFORMINTERACTION_RESPONSEMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/SDLRPCObjects/V1/PerformInteraction_response.h"


/*
  interface	Ford Sync RAPI
  version	1.2
  date		2011-05-17
  generated at	Thu Jan 24 06:36:21 2013
  source stamp	Thu Jan 24 06:35:34 2013
  author	RC
*/

namespace NsSmartDeviceLinkRPC
{

  struct PerformInteraction_responseMarshaller
  {
    static bool checkIntegrity(PerformInteraction_response& e);
    static bool checkIntegrityConst(const PerformInteraction_response& e);
  
    static bool fromString(const std::string& s,PerformInteraction_response& e);
    static const std::string toString(const PerformInteraction_response& e);
  
    static bool fromJSON(const Json::Value& s,PerformInteraction_response& e);
    static Json::Value toJSON(const PerformInteraction_response& e);
  };
}

#endif
