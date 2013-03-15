//
// Copyright (c) 2013 Ford Motor Company
//

#ifndef NSRPC2COMMUNICATION_UI_SETMEDIACLOCKTIMERRESPONSEMARSHALLER_INCLUDE
#define NSRPC2COMMUNICATION_UI_SETMEDIACLOCKTIMERRESPONSEMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../src/../include/JSONHandler/RPC2Objects/NsRPC2Communication/UI/SetMediaClockTimerResponse.h"

namespace NsRPC2Communication
{
  namespace UI
  {

    struct SetMediaClockTimerResponseMarshaller
    {
      static bool checkIntegrity(SetMediaClockTimerResponse& e);
      static bool checkIntegrityConst(const SetMediaClockTimerResponse& e);
    
      static bool fromString(const std::string& s,SetMediaClockTimerResponse& e);
      static const std::string toString(const SetMediaClockTimerResponse& e);
    
      static bool fromJSON(const Json::Value& s,SetMediaClockTimerResponse& e);
      static Json::Value toJSON(const SetMediaClockTimerResponse& e);
    };
  }
}

#endif
