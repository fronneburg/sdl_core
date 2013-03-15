//
// Copyright (c) 2013 Ford Motor Company
//

#ifndef NSSMARTDEVICELINKRPCV2_UNSUBSCRIBEBUTTON_RESPONSEMARSHALLER_INCLUDE
#define NSSMARTDEVICELINKRPCV2_UNSUBSCRIBEBUTTON_RESPONSEMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/SDLRPCObjects/V2/UnsubscribeButton_response.h"


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

  struct UnsubscribeButton_responseMarshaller
  {
    static bool checkIntegrity(UnsubscribeButton_response& e);
    static bool checkIntegrityConst(const UnsubscribeButton_response& e);
  
    static bool fromString(const std::string& s,UnsubscribeButton_response& e);
    static const std::string toString(const UnsubscribeButton_response& e);
  
    static bool fromJSON(const Json::Value& s,UnsubscribeButton_response& e);
    static Json::Value toJSON(const UnsubscribeButton_response& e);
  };
}

#endif
