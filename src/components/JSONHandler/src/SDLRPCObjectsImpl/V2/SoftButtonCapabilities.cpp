//
// Copyright (c) 2013 Ford Motor Company
//

#include "../include/JSONHandler/SDLRPCObjects/V2/SoftButtonCapabilities.h"
#include "SoftButtonCapabilitiesMarshaller.h"

/*
  interface	Ford Sync RAPI
  version	2.0O
  date		2012-11-02
  generated at	Thu Jan 24 06:36:23 2013
  source stamp	Thu Jan 24 06:35:41 2013
  author	RC
*/



using namespace NsSmartDeviceLinkRPCV2;

SoftButtonCapabilities::SoftButtonCapabilities(const SoftButtonCapabilities& c)
{
  *this=c;
}


bool SoftButtonCapabilities::checkIntegrity(void)
{
  return SoftButtonCapabilitiesMarshaller::checkIntegrity(*this);
}


SoftButtonCapabilities::SoftButtonCapabilities(void)
{
}



bool SoftButtonCapabilities::set_imageSupported(bool imageSupported_)
{
  imageSupported=imageSupported_;
  return true;
}

bool SoftButtonCapabilities::set_longPressAvailable(bool longPressAvailable_)
{
  longPressAvailable=longPressAvailable_;
  return true;
}

bool SoftButtonCapabilities::set_shortPressAvailable(bool shortPressAvailable_)
{
  shortPressAvailable=shortPressAvailable_;
  return true;
}

bool SoftButtonCapabilities::set_upDownAvailable(bool upDownAvailable_)
{
  upDownAvailable=upDownAvailable_;
  return true;
}




bool SoftButtonCapabilities::get_imageSupported(void) const
{
  return imageSupported;
}


bool SoftButtonCapabilities::get_longPressAvailable(void) const
{
  return longPressAvailable;
}


bool SoftButtonCapabilities::get_shortPressAvailable(void) const
{
  return shortPressAvailable;
}


bool SoftButtonCapabilities::get_upDownAvailable(void) const
{
  return upDownAvailable;
}


