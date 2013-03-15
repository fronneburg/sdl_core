//
// Copyright (c) 2013 Ford Motor Company
//

#include <cstring>
#include "../include/JSONHandler/SDLRPCObjects/V2/PRNDL.h"
#include "PRNDLMarshaller.h"
#include "PRNDLMarshaller.inc"


/*
  interface	Ford Sync RAPI
  version	2.0O
  date		2012-11-02
  generated at	Thu Jan 24 06:36:23 2013
  source stamp	Thu Jan 24 06:35:41 2013
  author	RC
*/

using namespace NsSmartDeviceLinkRPCV2;


const PRNDL::PRNDLInternal PRNDLMarshaller::getIndex(const char* s)
{
  if(!s)
    return PRNDL::INVALID_ENUM;
  const struct PerfectHashTable* p=PRNDL_intHash::getPointer(s,strlen(s));
  return p ? static_cast<PRNDL::PRNDLInternal>(p->idx) : PRNDL::INVALID_ENUM;
}


bool PRNDLMarshaller::fromJSON(const Json::Value& s,PRNDL& e)
{
  e.mInternal=PRNDL::INVALID_ENUM;
  if(!s.isString())
    return false;

  e.mInternal=getIndex(s.asString().c_str());
  return (e.mInternal!=PRNDL::INVALID_ENUM);
}


Json::Value PRNDLMarshaller::toJSON(const PRNDL& e)
{
  if(e.mInternal==PRNDL::INVALID_ENUM) 
    return Json::Value(Json::nullValue);
  const char* s=getName(e.mInternal);
  return s ? Json::Value(s) : Json::Value(Json::nullValue);
}


bool PRNDLMarshaller::fromString(const std::string& s,PRNDL& e)
{
  e.mInternal=PRNDL::INVALID_ENUM;
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

const std::string PRNDLMarshaller::toString(const PRNDL& e)
{
  Json::FastWriter writer;
  return e.mInternal==PRNDL::INVALID_ENUM ? "" : writer.write(toJSON(e));

}

const PerfectHashTable PRNDLMarshaller::mHashTable[14]=
{
  {"PARK",0},
  {"REVERSE",1},
  {"NEUTRAL",2},
  {"LOWGEAR",3},
  {"FORWARD_DRIVE_2",4},
  {"FORWARD_DRIVE_3",5},
  {"FORWARD_DRIVE_4",6},
  {"FORWARD_DRIVE_5",7},
  {"FORWARD_DRIVE_6",8},
  {"SECOND_GEAR_HOLD",9},
  {"THIRD_GEAR_HOLD",10},
  {"FOURTH_GEAR_HOLD",11},
  {"FIFTH_GEAR_HOLD",12},
  {"SIXTH_GEAR_HOLD",13}
};
