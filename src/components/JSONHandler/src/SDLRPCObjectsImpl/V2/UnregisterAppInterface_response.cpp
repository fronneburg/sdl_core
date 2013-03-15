//
// Copyright (c) 2013 Ford Motor Company
//

#include "../include/JSONHandler/SDLRPCObjects/V2/UnregisterAppInterface_response.h"
#include "UnregisterAppInterface_responseMarshaller.h"

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
UnregisterAppInterface_response& UnregisterAppInterface_response::operator =(const UnregisterAppInterface_response& c)
{
    success = c.success;
    resultCode = c.resultCode;
    info = c.info ? new std::string(c.info[0]) : 0;

    return *this;
}

UnregisterAppInterface_response::~UnregisterAppInterface_response(void)
{}

UnregisterAppInterface_response::UnregisterAppInterface_response(const UnregisterAppInterface_response& c)
{
    *this = c;
}

bool UnregisterAppInterface_response::checkIntegrity(void)
{
    return UnregisterAppInterface_responseMarshaller::checkIntegrity(*this);
}

UnregisterAppInterface_response::UnregisterAppInterface_response(void) : NsSmartDeviceLinkRPC::SDLRPCResponse(PROTOCOL_VERSION)
{}
