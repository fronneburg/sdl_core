//
// Copyright (c) 2013 Ford Motor Company
//

#include "../include/JSONHandler/SDLRPCObjects/V2/DeleteFile_request.h"


#include "DeleteFile_requestMarshaller.h"


/*
  interface	Ford Sync RAPI
  version	2.0O
  date		2012-11-02
  generated at	Thu Jan 24 06:36:23 2013
  source stamp	Thu Jan 24 06:35:41 2013
  author	RC
*/

using namespace NsSmartDeviceLinkRPCV2;


bool DeleteFile_requestMarshaller::checkIntegrity(DeleteFile_request& s)
{
  return checkIntegrityConst(s);
}


bool DeleteFile_requestMarshaller::fromString(const std::string& s,DeleteFile_request& e)
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


const std::string DeleteFile_requestMarshaller::toString(const DeleteFile_request& e)
{
  Json::FastWriter writer;
  return checkIntegrityConst(e) ? writer.write(toJSON(e)) : "";
}


bool DeleteFile_requestMarshaller::checkIntegrityConst(const DeleteFile_request& s)
{
  if(s.syncFileName.length()>500)  return false;
  return true;
}

Json::Value DeleteFile_requestMarshaller::toJSON(const DeleteFile_request& e)
{
  Json::Value json(Json::objectValue);
  if(!checkIntegrityConst(e))
    return Json::Value(Json::nullValue);

  json["syncFileName"]=Json::Value(e.syncFileName);

  return json;
}


bool DeleteFile_requestMarshaller::fromJSON(const Json::Value& json,DeleteFile_request& c)
{
  try
  {
    if(!json.isObject())  return false;

    if(!json.isMember("syncFileName"))  return false;
    {
      const Json::Value& j=json["syncFileName"];
      if(!j.isString())  return false;
      c.syncFileName=j.asString();
    }

  }
  catch(...)
  {
    return false;
  }
  return checkIntegrity(c);
}

