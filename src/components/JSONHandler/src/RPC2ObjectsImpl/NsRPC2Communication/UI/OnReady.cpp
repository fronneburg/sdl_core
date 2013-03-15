//
// Copyright (c) 2013 Ford Motor Company
//

#include "../src/../include/JSONHandler/RPC2Objects/NsRPC2Communication/UI/OnReady.h"
#include "../src/../include/JSONHandler/RPC2Objects/Marshaller.h"

/*
  interface	NsRPC2Communication::UI
  version	1.2
  generated at	Thu Jan 24 06:41:15 2013
  source stamp	Wed Jan 23 13:56:28 2013
  author	RC
*/

using namespace NsRPC2Communication::UI;


OnReady& OnReady::operator =(const OnReady& c)
{
  return *this;
}


OnReady::~OnReady(void)
{
}


OnReady::OnReady(void) : 
  RPC2Notification(Marshaller::METHOD_NSRPC2COMMUNICATION_UI__ONREADY)
{
}


OnReady::OnReady(const OnReady& c) : RPC2Notification(Marshaller::METHOD_NSRPC2COMMUNICATION_UI__ONREADY)
{
  *this=c;
}


bool OnReady::checkIntegrity(void)
{
  return OnReadyMarshaller::checkIntegrity(*this);
}
