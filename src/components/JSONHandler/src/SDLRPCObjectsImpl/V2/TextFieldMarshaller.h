//
// Copyright (c) 2013 Ford Motor Company
//

#ifndef NSSMARTDEVICELINKRPCV2_TEXTFIELDMARSHALLER_INCLUDE
#define NSSMARTDEVICELINKRPCV2_TEXTFIELDMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/SDLRPCObjects/V2/TextField.h"


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

  struct TextFieldMarshaller
  {
    static bool checkIntegrity(TextField& e);
    static bool checkIntegrityConst(const TextField& e);
  
    static bool fromString(const std::string& s,TextField& e);
    static const std::string toString(const TextField& e);
  
    static bool fromJSON(const Json::Value& s,TextField& e);
    static Json::Value toJSON(const TextField& e);
  };
}

#endif
