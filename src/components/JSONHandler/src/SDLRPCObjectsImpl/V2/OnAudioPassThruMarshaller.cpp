//
// Copyright (c) 2013 Ford Motor Company
//

#include "../include/JSONHandler/SDLRPCObjects/V2/OnAudioPassThru.h"


#include "OnAudioPassThruMarshaller.h"


/*
  interface	Ford Sync RAPI
  version	2.0O
  date		2012-11-02
  generated at	Thu Jan 24 06:36:23 2013
  source stamp	Thu Jan 24 06:35:41 2013
  author	RC
*/

using namespace NsSmartDeviceLinkRPCV2;


bool OnAudioPassThruMarshaller::checkIntegrity(OnAudioPassThru& s)
{
  return checkIntegrityConst(s);
}


bool OnAudioPassThruMarshaller::fromString(const std::string& s,OnAudioPassThru& e)
{
  try
  {
    Json::Reader reader;
    Json::Value json;
    if(!reader.parse(s,json,false))  return false;
    if(!fromJSON(json,e))  return false;
  }
  catch(...)
  {
    return false;
  }
  return true;
}


const std::string OnAudioPassThruMarshaller::toString(const OnAudioPassThru& e)
{
  Json::FastWriter writer;
  return checkIntegrityConst(e) ? writer.write(toJSON(e)) : "";
}


bool OnAudioPassThruMarshaller::checkIntegrityConst(const OnAudioPassThru& s)
{
  return true;
}

Json::Value OnAudioPassThruMarshaller::toJSON(const OnAudioPassThru& e)
{
  Json::Value json(Json::objectValue);
  if(!checkIntegrityConst(e))
    return Json::Value(Json::nullValue);

  return json=Json::Value(Json::nullValue);
}


bool OnAudioPassThruMarshaller::fromJSON(const Json::Value& json,OnAudioPassThru& c)
{
  try
  {
    if(!json.isObject())  return false;


  }
  catch(...)
  {
    return false;
  }
  return checkIntegrity(c);
}

