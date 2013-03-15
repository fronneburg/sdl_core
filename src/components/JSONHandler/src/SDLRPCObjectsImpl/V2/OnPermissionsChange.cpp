//
// Copyright (c) 2013 Ford Motor Company
//

#include "../include/JSONHandler/SDLRPCObjects/V2/OnPermissionsChange.h"
#include "OnPermissionsChangeMarshaller.h"
#include "../include/JSONHandler/SDLRPCObjects/V2/Marshaller.h"
#include "PermissionItemMarshaller.h"

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

OnPermissionsChange::~OnPermissionsChange(void)
{
}


OnPermissionsChange::OnPermissionsChange(const OnPermissionsChange& c) : NsSmartDeviceLinkRPC::SDLRPCMessage(c)
{
  *this=c;
}


bool OnPermissionsChange::checkIntegrity(void)
{
  return OnPermissionsChangeMarshaller::checkIntegrity(*this);
}


OnPermissionsChange::OnPermissionsChange(void) : NsSmartDeviceLinkRPC::SDLRPCMessage(PROTOCOL_VERSION)
{
}



bool OnPermissionsChange::set_permissionItem(const std::vector<PermissionItem>& permissionItem_)
{
  unsigned int i=permissionItem_.size();
  if(i>100 || i<1)  return false;
  while(i--)
  {
    if(!PermissionItemMarshaller::checkIntegrityConst(permissionItem_[i]))   return false;
  }
  permissionItem=permissionItem_;
  return true;
}




const std::vector<PermissionItem>& OnPermissionsChange::get_permissionItem(void) const 
{
  return permissionItem;
}

