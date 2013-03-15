//
// Copyright (c) 2013 Ford Motor Company
//

#include "../include/JSONHandler/SDLRPCObjects/V1/DeleteSubMenu_response.h"
#include "DeleteSubMenu_responseMarshaller.h"
#include "../include/JSONHandler/SDLRPCObjects/V1/Marshaller.h"

namespace
{
    const int PROTOCOL_VERSION = 1;
}

/*
  interface Ford Sync RAPI
  version   1.2
  date      2011-05-17
  generated at  Thu Jan 24 06:36:21 2013
  source stamp  Thu Jan 24 06:35:34 2013
  author    RC
*/

using namespace NsSmartDeviceLinkRPC;
DeleteSubMenu_response& DeleteSubMenu_response::operator =(const DeleteSubMenu_response& c)
{
    success = c.success;
    resultCode = c.resultCode;
    info = c.info ? new std::string(c.info[0]) : 0;

    return *this;
}

DeleteSubMenu_response::~DeleteSubMenu_response(void)
{}

DeleteSubMenu_response::DeleteSubMenu_response(const DeleteSubMenu_response& c)
{
    *this = c;
}

bool DeleteSubMenu_response::checkIntegrity(void)
{
    return DeleteSubMenu_responseMarshaller::checkIntegrity(*this);
}

DeleteSubMenu_response::DeleteSubMenu_response(void)
    : SDLRPCResponse(PROTOCOL_VERSION, Marshaller::METHOD_DELETESUBMENU_RESPONSE)
{}
