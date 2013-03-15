//
// Copyright (c) 2013 Ford Motor Company
//

#include "../include/JSONHandler/SDLRPCObjects/V2/ReadDID_request.h"


#include "ReadDID_requestMarshaller.h"


/*
  interface	Ford Sync RAPI
  version	2.0O
  date		2012-11-02
  generated at	Thu Jan 24 06:36:23 2013
  source stamp	Thu Jan 24 06:35:41 2013
  author	RC
*/

using namespace NsSmartDeviceLinkRPCV2;


bool ReadDID_requestMarshaller::checkIntegrity(ReadDID_request& s)
{
  return checkIntegrityConst(s);
}


bool ReadDID_requestMarshaller::fromString(const std::string& s,ReadDID_request& e)
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


const std::string ReadDID_requestMarshaller::toString(const ReadDID_request& e)
{
  Json::FastWriter writer;
  return checkIntegrityConst(e) ? writer.write(toJSON(e)) : "";
}


bool ReadDID_requestMarshaller::checkIntegrityConst(const ReadDID_request& s)
{
  if(s.ecuName>65535)  return false;
  {
    unsigned int i=s.didLocation.size();
    if(i>1000 || i<0)  return false;
    while(i--)
    {
      if(s.didLocation[i]>65535)  return false;
    }
  }
  return true;
}

Json::Value ReadDID_requestMarshaller::toJSON(const ReadDID_request& e)
{
  Json::Value json(Json::objectValue);
  if(!checkIntegrityConst(e))
    return Json::Value(Json::nullValue);

  json["ecuName"]=Json::Value(e.ecuName);

  json["didLocation"]=Json::Value(Json::arrayValue);
  json["didLocation"].resize(e.didLocation.size());
  for(unsigned int i=0;i<e.didLocation.size();i++)
    json["didLocation"][i]=Json::Value(e.didLocation[i]);

  if(e.encrypted)
    json["encrypted"]=Json::Value(*e.encrypted);

  return json;
}


bool ReadDID_requestMarshaller::fromJSON(const Json::Value& json,ReadDID_request& c)
{
  if(c.encrypted)  delete c.encrypted;
  c.encrypted=0;

  try
  {
    if(!json.isObject())  return false;

    if(!json.isMember("ecuName"))  return false;
    {
      const Json::Value& j=json["ecuName"];
      if(!j.isInt())  return false;
      c.ecuName=j.asInt();
    }
    if(!json.isMember("didLocation"))  return false;
    {
      const Json::Value& j=json["didLocation"];
      if(!j.isArray())  return false;
      c.didLocation.resize(j.size());
      for(unsigned int i=0;i<j.size();i++)
        if(!j[i].isInt())
          return false;
        else
          c.didLocation[i]=j[i].asInt();
    }
    if(json.isMember("encrypted"))
    {
      const Json::Value& j=json["encrypted"];
      if(!j.isBool())  return false;
      c.encrypted=new bool(j.asBool());
    }

  }
  catch(...)
  {
    return false;
  }
  return checkIntegrity(c);
}

