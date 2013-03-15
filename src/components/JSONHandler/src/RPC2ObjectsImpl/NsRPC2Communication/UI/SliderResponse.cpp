//
// Copyright (c) 2013 Ford Motor Company
//

#include "../src/../include/JSONHandler/RPC2Objects/NsRPC2Communication/UI/SliderResponse.h"
#include "../src/../include/JSONHandler/RPC2Objects/Marshaller.h"

/*
  interface	NsRPC2Communication::UI
  version	1.2
  generated at	Thu Jan 24 06:41:15 2013
  source stamp	Wed Jan 23 13:56:28 2013
  author	RC
*/

using namespace NsRPC2Communication::UI;


SliderResponse& SliderResponse::operator =(const SliderResponse& c)
{
  sliderPosition=c.sliderPosition;
  return *this;
}


SliderResponse::~SliderResponse(void)
{
}


SliderResponse::SliderResponse(void) : 
  RPC2Response(Marshaller::METHOD_NSRPC2COMMUNICATION_UI__SLIDERRESPONSE)
{
}


SliderResponse::SliderResponse(const SliderResponse& c) : RPC2Response(Marshaller::METHOD_NSRPC2COMMUNICATION_UI__SLIDERRESPONSE,c.getId(),c.getResult())
{
  *this=c;
}


unsigned int SliderResponse::get_sliderPosition(void)
{
  return sliderPosition;
}

bool SliderResponse::set_sliderPosition(unsigned int sliderPosition_)
{
  sliderPosition=sliderPosition_;
  return true;
}

bool SliderResponse::checkIntegrity(void)
{
  return SliderResponseMarshaller::checkIntegrity(*this);
}
