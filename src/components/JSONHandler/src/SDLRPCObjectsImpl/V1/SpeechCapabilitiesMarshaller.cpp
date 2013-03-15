//
// Copyright (c) 2013 Ford Motor Company
//

#include <cstring>
#include "../include/JSONHandler/SDLRPCObjects/V1/SpeechCapabilities.h"
#include "SpeechCapabilitiesMarshaller.h"
#include "SpeechCapabilitiesMarshaller.inc"


/*
  interface	Ford Sync RAPI
  version	1.2
  date		2011-05-17
  generated at	Thu Jan 24 06:36:21 2013
  source stamp	Thu Jan 24 06:35:34 2013
  author	RC
*/

using namespace NsSmartDeviceLinkRPC;


const SpeechCapabilities::SpeechCapabilitiesInternal SpeechCapabilitiesMarshaller::getIndex(const char* s)
{
  if(!s)
    return SpeechCapabilities::INVALID_ENUM;
  const struct PerfectHashTable* p=SpeechCapabilities_intHash::getPointer(s,strlen(s));
  return p ? static_cast<SpeechCapabilities::SpeechCapabilitiesInternal>(p->idx) : SpeechCapabilities::INVALID_ENUM;
}


bool SpeechCapabilitiesMarshaller::fromJSON(const Json::Value& s,SpeechCapabilities& e)
{
  e.mInternal=SpeechCapabilities::INVALID_ENUM;
  if(!s.isString())
    return false;

  e.mInternal=getIndex(s.asString().c_str());
  return (e.mInternal!=SpeechCapabilities::INVALID_ENUM);
}


Json::Value SpeechCapabilitiesMarshaller::toJSON(const SpeechCapabilities& e)
{
  if(e.mInternal==SpeechCapabilities::INVALID_ENUM) 
    return Json::Value(Json::nullValue);
  const char* s=getName(e.mInternal);
  return s ? Json::Value(s) : Json::Value(Json::nullValue);
}


bool SpeechCapabilitiesMarshaller::fromString(const std::string& s,SpeechCapabilities& e)
{
  e.mInternal=SpeechCapabilities::INVALID_ENUM;
  try
  {
    Json::Reader reader;
    Json::Value json;
    if(!reader.parse(s,json,false))  return false;
    if(fromJSON(json,e))  return true;
  }
  catch(...)
  {
    return false;
  }
  return false;
}

const std::string SpeechCapabilitiesMarshaller::toString(const SpeechCapabilities& e)
{
  Json::FastWriter writer;
  return e.mInternal==SpeechCapabilities::INVALID_ENUM ? "" : writer.write(toJSON(e));

}

const PerfectHashTable SpeechCapabilitiesMarshaller::mHashTable[5]=
{
  {"TEXT",0},
  {"SAPI_PHONEMES",1},
  {"LHPLUS_PHONEMES",2},
  {"PRE_RECORDED",3},
  {"SILENCE",4}
};
