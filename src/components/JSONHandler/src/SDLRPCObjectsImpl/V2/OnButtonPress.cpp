//
// Copyright (c) 2013 Ford Motor Company
//

#include "../include/JSONHandler/SDLRPCObjects/V2/OnButtonPress.h"
#include "OnButtonPressMarshaller.h"
#include "../include/JSONHandler/SDLRPCObjects/V2/Marshaller.h"
#include "ButtonNameMarshaller.h"
#include "ButtonPressModeMarshaller.h"

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

OnButtonPress::~OnButtonPress(void)
{
}


OnButtonPress::OnButtonPress(const OnButtonPress& c) : NsSmartDeviceLinkRPC::SDLRPCMessage(c)
{
  *this=c;
}


bool OnButtonPress::checkIntegrity(void)
{
  return OnButtonPressMarshaller::checkIntegrity(*this);
}


OnButtonPress::OnButtonPress(void) : NsSmartDeviceLinkRPC::SDLRPCMessage(PROTOCOL_VERSION)
{
}



bool OnButtonPress::set_buttonName(const ButtonName& buttonName_)
{
  if(!ButtonNameMarshaller::checkIntegrityConst(buttonName_))   return false;
  buttonName=buttonName_;
  return true;
}

bool OnButtonPress::set_buttonPressMode(const ButtonPressMode& buttonPressMode_)
{
  if(!ButtonPressModeMarshaller::checkIntegrityConst(buttonPressMode_))   return false;
  buttonPressMode=buttonPressMode_;
  return true;
}

bool OnButtonPress::set_customButtonID(unsigned int customButtonID_)
{
  if(customButtonID_>65536)  return false;
  customButtonID=customButtonID_;
  return true;
}




const ButtonName& OnButtonPress::get_buttonName(void) const 
{
  return buttonName;
}

const ButtonPressMode& OnButtonPress::get_buttonPressMode(void) const 
{
  return buttonPressMode;
}

unsigned int OnButtonPress::get_customButtonID(void) const
{
  return customButtonID;
}

