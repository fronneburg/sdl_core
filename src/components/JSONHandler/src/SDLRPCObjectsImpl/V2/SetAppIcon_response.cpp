//
// Copyright (c) 2013 Ford Motor Company
//

#include "../include/JSONHandler/SDLRPCObjects/V2/SetAppIcon_response.h"
#include "SetAppIcon_responseMarshaller.h"

namespace
{
    const int PROTOCOL_VERSION = 2;
}

/*
  interface Ford Sync RAPI
  version   2.0O
  date      2012-11-02
  generated at  Thu Jan 24 06:36:23 2013
  source stamp  Thu Jan 24 06:35:41 2013
  author    RC
*/

using namespace NsSmartDeviceLinkRPCV2;
SetAppIcon_response& SetAppIcon_response::operator =(const SetAppIcon_response& c)
{
    success = c.success;
    resultCode = c.resultCode;
    info = c.info ? new std::string(c.info[0]) : 0;

    return *this;
}

SetAppIcon_response::~SetAppIcon_response(void)
{}

SetAppIcon_response::SetAppIcon_response(const SetAppIcon_response& c)
{
    *this = c;
}

bool SetAppIcon_response::checkIntegrity(void)
{
    return SetAppIcon_responseMarshaller::checkIntegrity(*this);
}

SetAppIcon_response::SetAppIcon_response(void) : NsSmartDeviceLinkRPC::SDLRPCResponse(PROTOCOL_VERSION)
{}
