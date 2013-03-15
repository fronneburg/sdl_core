//
// Copyright (c) 2013 Ford Motor Company
//

#ifndef NSSMARTDEVICELINKRPCV2_TURNMARSHALLER_INCLUDE
#define NSSMARTDEVICELINKRPCV2_TURNMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/SDLRPCObjects/V2/Turn.h"


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

  struct TurnMarshaller
  {
    static bool checkIntegrity(Turn& e);
    static bool checkIntegrityConst(const Turn& e);
  
    static bool fromString(const std::string& s,Turn& e);
    static const std::string toString(const Turn& e);
  
    static bool fromJSON(const Json::Value& s,Turn& e);
    static Json::Value toJSON(const Turn& e);
  };
}

#endif
