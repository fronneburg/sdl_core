//
// Copyright (c) 2013 Ford Motor Company
//

#include "../src/../include/JSONHandler/RPC2Objects/NsRPC2Communication/VR/OnCommand.h"
#include "../src/SDLRPCObjectsImpl/V2/ResultMarshaller.h"
#include "../src/../src/RPC2ObjectsImpl//NsRPC2Communication/VR/OnCommandMarshaller.h"

/*
  interface	NsRPC2Communication::VR
  version	1.2
  generated at	Thu Jan 24 06:41:15 2013
  source stamp	Wed Jan 23 13:56:28 2013
  author	RC
*/

using namespace NsRPC2Communication::VR;

bool OnCommandMarshaller::checkIntegrity(OnCommand& s)
{
  return checkIntegrityConst(s);
}


bool OnCommandMarshaller::fromString(const std::string& s,OnCommand& e)
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


const std::string OnCommandMarshaller::toString(const OnCommand& e)
{
  Json::FastWriter writer;
  return checkIntegrityConst(e) ? writer.write(toJSON(e)) : "";
}


bool OnCommandMarshaller::checkIntegrityConst(const OnCommand& s)
{
  if(s.cmdID>2000000000)  return false;

  return true;
}


Json::Value OnCommandMarshaller::toJSON(const OnCommand& e)
{
  Json::Value json(Json::objectValue);
  if(!checkIntegrityConst(e))
    return Json::Value(Json::nullValue);

  json["jsonrpc"]=Json::Value("2.0");
  json["method"]=Json::Value("VR.OnCommand");
  json["params"]=Json::Value(Json::objectValue);

  json["params"]["cmdID"]=Json::Value(e.cmdID);;
  json["params"]["appId"]=Json::Value(e.appId);;
  return json;
}


bool OnCommandMarshaller::fromJSON(const Json::Value& json,OnCommand& c)
{
  try
  {
    if(!json.isObject())  return false;
    if(!json.isMember("jsonrpc") || !json["jsonrpc"].isString() || json["jsonrpc"].asString().compare("2.0"))  return false;
    if(!json.isMember("method") || !json["method"].isString() || json["method"].asString().compare("VR.OnCommand"))  return false;
    if(!json.isMember("params")) return false;

    Json::Value js=json["params"];
    if(!js.isObject())  return false;

    if(!js.isMember("cmdID") || !js["cmdID"].isInt())  return false;
    c.cmdID=js["cmdID"].asInt();
    if(c.cmdID>2000000000)  return false;

    if(!js.isMember("appId") || !js["appId"].isInt())  return false;
    c.appId=js["appId"].asInt();
    
  }
  catch(...)
  {
    return false;
  }
  return checkIntegrity(c);
}
