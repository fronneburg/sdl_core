//
// Copyright (c) 2013 Ford Motor Company
//

#include "../src/../include/JSONHandler/RPC2Objects/NsRPC2Communication/UI/OnDriverDistraction.h"
#include "../src/SDLRPCObjectsImpl/V2/DriverDistractionStateMarshaller.h"
#include "../src/SDLRPCObjectsImpl/V2/ResultMarshaller.h"
#include "../src/../src/RPC2ObjectsImpl//NsRPC2Communication/UI/OnDriverDistractionMarshaller.h"

/*
  interface	NsRPC2Communication::UI
  version	1.2
  generated at	Thu Jan 24 06:41:15 2013
  source stamp	Wed Jan 23 13:56:28 2013
  author	RC
*/

using namespace NsRPC2Communication::UI;

bool OnDriverDistractionMarshaller::checkIntegrity(OnDriverDistraction& s)
{
  return checkIntegrityConst(s);
}


bool OnDriverDistractionMarshaller::fromString(const std::string& s,OnDriverDistraction& e)
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


const std::string OnDriverDistractionMarshaller::toString(const OnDriverDistraction& e)
{
  Json::FastWriter writer;
  return checkIntegrityConst(e) ? writer.write(toJSON(e)) : "";
}


bool OnDriverDistractionMarshaller::checkIntegrityConst(const OnDriverDistraction& s)
{
  if(!NsSmartDeviceLinkRPCV2::DriverDistractionStateMarshaller::checkIntegrityConst(s.state))  return false;

  return true;
}


Json::Value OnDriverDistractionMarshaller::toJSON(const OnDriverDistraction& e)
{
  Json::Value json(Json::objectValue);
  if(!checkIntegrityConst(e))
    return Json::Value(Json::nullValue);

  json["jsonrpc"]=Json::Value("2.0");
  json["method"]=Json::Value("UI.OnDriverDistraction");
  json["params"]=Json::Value(Json::objectValue);

  json["params"]["state"]=NsSmartDeviceLinkRPCV2::DriverDistractionStateMarshaller::toJSON(e.state);;
  return json;
}


bool OnDriverDistractionMarshaller::fromJSON(const Json::Value& json,OnDriverDistraction& c)
{
  try
  {
    if(!json.isObject())  return false;
    if(!json.isMember("jsonrpc") || !json["jsonrpc"].isString() || json["jsonrpc"].asString().compare("2.0"))  return false;
    if(!json.isMember("method") || !json["method"].isString() || json["method"].asString().compare("UI.OnDriverDistraction"))  return false;
    if(!json.isMember("params")) return false;

    Json::Value js=json["params"];
    if(!js.isObject())  return false;

    if(!js.isMember("state") || !NsSmartDeviceLinkRPCV2::DriverDistractionStateMarshaller::fromJSON(js["state"],c.state))  return false;

  }
  catch(...)
  {
    return false;
  }
  return checkIntegrity(c);
}
