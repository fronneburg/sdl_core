//
// Copyright (c) 2013 Ford Motor Company
//

#ifndef NSSMARTDEVICELINKRPCV2_INTERACTIONMODEMARSHALLER_INCLUDE
#define NSSMARTDEVICELINKRPCV2_INTERACTIONMODEMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "PerfectHashTable.h"

#include "../include/JSONHandler/SDLRPCObjects/V2/InteractionMode.h"


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

//! marshalling class for InteractionMode

  class InteractionModeMarshaller
  {
  public:
  
    static std::string toName(const InteractionMode& e) 	{ return getName(e.mInternal) ?: ""; }
  
    static bool fromName(InteractionMode& e,const std::string& s)
    { 
      return (e.mInternal=getIndex(s.c_str()))!=InteractionMode::INVALID_ENUM;
    }
  
    static bool checkIntegrity(InteractionMode& e)		{ return e.mInternal!=InteractionMode::INVALID_ENUM; } 
    static bool checkIntegrityConst(const InteractionMode& e)	{ return e.mInternal!=InteractionMode::INVALID_ENUM; } 
  
    static bool fromString(const std::string& s,InteractionMode& e);
    static const std::string toString(const InteractionMode& e);
  
    static bool fromJSON(const Json::Value& s,InteractionMode& e);
    static Json::Value toJSON(const InteractionMode& e);
  
    static const char* getName(InteractionMode::InteractionModeInternal e)
    {
       return (e>=0 && e<3) ? mHashTable[e].name : NULL;
    }
  
    static const InteractionMode::InteractionModeInternal getIndex(const char* s);
  
    static const PerfectHashTable mHashTable[3];
  };
  
}

#endif
