//
// Copyright (c) 2013 Ford Motor Company
//

#include "../include/JSONHandler/SDLRPCObjects/V1/CreateInteractionChoiceSet_response.h"
#include "CreateInteractionChoiceSet_responseMarshaller.h"
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
CreateInteractionChoiceSet_response& CreateInteractionChoiceSet_response::operator =(
    const CreateInteractionChoiceSet_response& c)
{
    success = c.success;
    resultCode = c.resultCode;
    info = c.info ? new std::string(c.info[0]) : 0;

    return *this;
}

CreateInteractionChoiceSet_response::~CreateInteractionChoiceSet_response(void)
{}

CreateInteractionChoiceSet_response::CreateInteractionChoiceSet_response(const CreateInteractionChoiceSet_response& c)
{
    *this = c;
}

bool CreateInteractionChoiceSet_response::checkIntegrity(void)
{
    return CreateInteractionChoiceSet_responseMarshaller::checkIntegrity(*this);
}


CreateInteractionChoiceSet_response::CreateInteractionChoiceSet_response(void)
    : SDLRPCResponse(PROTOCOL_VERSION, Marshaller::METHOD_CREATEINTERACTIONCHOICESET_RESPONSE)
{}
