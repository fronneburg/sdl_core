//
// Copyright (c) 2013 Ford Motor Company
//

#include "../include/JSONHandler/SDLRPCObjects/V2/DeleteCommand_response.h"
#include "DeleteCommand_responseMarshaller.h"

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
DeleteCommand_response& DeleteCommand_response::operator =(const DeleteCommand_response& c)
{
    success = c.success;
    resultCode = c.resultCode;
    info = c.info ? new std::string(c.info[0]) : 0;

    return *this;
}

DeleteCommand_response::~DeleteCommand_response(void)
{}

DeleteCommand_response::DeleteCommand_response(const DeleteCommand_response& c)
{
    *this = c;
}

bool DeleteCommand_response::checkIntegrity(void)
{
    return DeleteCommand_responseMarshaller::checkIntegrity(*this);
}

DeleteCommand_response::DeleteCommand_response(void) : NsSmartDeviceLinkRPC::SDLRPCResponse(PROTOCOL_VERSION)
{}
