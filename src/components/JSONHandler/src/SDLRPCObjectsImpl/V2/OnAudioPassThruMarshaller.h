//
// Copyright (c) 2013 Ford Motor Company
//

#ifndef NSSMARTDEVICELINKRPCV2_ONAUDIOPASSTHRUMARSHALLER_INCLUDE
#define NSSMARTDEVICELINKRPCV2_ONAUDIOPASSTHRUMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/SDLRPCObjects/V2/OnAudioPassThru.h"


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

  struct OnAudioPassThruMarshaller
  {
    static bool checkIntegrity(OnAudioPassThru& e);
    static bool checkIntegrityConst(const OnAudioPassThru& e);
  
    static bool fromString(const std::string& s,OnAudioPassThru& e);
    static const std::string toString(const OnAudioPassThru& e);
  
    static bool fromJSON(const Json::Value& s,OnAudioPassThru& e);
    static Json::Value toJSON(const OnAudioPassThru& e);
  };
}

#endif
