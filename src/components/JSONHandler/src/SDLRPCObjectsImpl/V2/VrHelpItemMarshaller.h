//
// Copyright (c) 2013 Ford Motor Company
//

#ifndef NSSMARTDEVICELINKRPCV2_VRHELPITEMMARSHALLER_INCLUDE
#define NSSMARTDEVICELINKRPCV2_VRHELPITEMMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/SDLRPCObjects/V2/VrHelpItem.h"


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

  struct VrHelpItemMarshaller
  {
    static bool checkIntegrity(VrHelpItem& e);
    static bool checkIntegrityConst(const VrHelpItem& e);
  
    static bool fromString(const std::string& s,VrHelpItem& e);
    static const std::string toString(const VrHelpItem& e);
  
    static bool fromJSON(const Json::Value& s,VrHelpItem& e);
    static Json::Value toJSON(const VrHelpItem& e);
  };
}

#endif
