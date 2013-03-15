//
// Copyright (c) 2013 Ford Motor Company
//

#include "../include/JSONHandler/SDLRPCObjects/V1/CreateInteractionChoiceSet_request.h"
#include "CreateInteractionChoiceSet_requestMarshaller.h"
#include "../include/JSONHandler/SDLRPCObjects/V1/Marshaller.h"
#include "ChoiceMarshaller.h"

#define PROTOCOL_VERSION	1


/*
  interface	Ford Sync RAPI
  version	1.2
  date		2011-05-17
  generated at	Thu Jan 24 06:36:21 2013
  source stamp	Thu Jan 24 06:35:34 2013
  author	RC
*/

using namespace NsSmartDeviceLinkRPC;

CreateInteractionChoiceSet_request::~CreateInteractionChoiceSet_request(void)
{
}


CreateInteractionChoiceSet_request::CreateInteractionChoiceSet_request(const CreateInteractionChoiceSet_request& c)
{
  *this=c;
}


bool CreateInteractionChoiceSet_request::checkIntegrity(void)
{
  return CreateInteractionChoiceSet_requestMarshaller::checkIntegrity(*this);
}


CreateInteractionChoiceSet_request::CreateInteractionChoiceSet_request(void) : SDLRPCRequest(PROTOCOL_VERSION,Marshaller::METHOD_CREATEINTERACTIONCHOICESET_REQUEST)
{
}



bool CreateInteractionChoiceSet_request::set_interactionChoiceSetID(unsigned int interactionChoiceSetID_)
{
  if(interactionChoiceSetID_>2000000000)  return false;
  interactionChoiceSetID=interactionChoiceSetID_;
  return true;
}

bool CreateInteractionChoiceSet_request::set_choiceSet(const std::vector<Choice>& choiceSet_)
{
  unsigned int i=choiceSet_.size();
  if(i>100 || i<1)  return false;
  while(i--)
  {
    if(!ChoiceMarshaller::checkIntegrityConst(choiceSet_[i]))   return false;
  }
  choiceSet=choiceSet_;
  return true;
}




unsigned int CreateInteractionChoiceSet_request::get_interactionChoiceSetID(void) const
{
  return interactionChoiceSetID;
}

const std::vector<Choice>& CreateInteractionChoiceSet_request::get_choiceSet(void) const 
{
  return choiceSet;
}

