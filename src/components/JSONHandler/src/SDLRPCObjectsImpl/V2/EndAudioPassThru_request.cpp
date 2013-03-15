//
// Copyright (c) 2013 Ford Motor Company
//

#include "../include/JSONHandler/SDLRPCObjects/V2/EndAudioPassThru_request.h"
#include "EndAudioPassThru_requestMarshaller.h"
#include "../include/JSONHandler/SDLRPCObjects/V2/Marshaller.h"

#define PROTOCOL_VERSION	2


/*
  interface	Ford Sync RAPI
  version	2.0O
  date		2012-11-02
  generated at	Thu Jan 24 06:36:23 2013
  source stamp	Thu Jan 24 06:35:41 2013
  author	RC
*/

using namespace NsSmartDeviceLinkRPCV2;

EndAudioPassThru_request::~EndAudioPassThru_request(void)
{
}


EndAudioPassThru_request::EndAudioPassThru_request(const EndAudioPassThru_request& c) : NsSmartDeviceLinkRPC::SDLRPCMessage(c)
{
  *this=c;
}


bool EndAudioPassThru_request::checkIntegrity(void)
{
  return EndAudioPassThru_requestMarshaller::checkIntegrity(*this);
}


EndAudioPassThru_request::EndAudioPassThru_request(void) : NsSmartDeviceLinkRPC::SDLRPCMessage(PROTOCOL_VERSION)
{
}






