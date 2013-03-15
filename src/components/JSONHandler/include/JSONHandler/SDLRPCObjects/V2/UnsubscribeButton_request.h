//
// Copyright (c) 2013 Ford Motor Company
//

#ifndef NSSMARTDEVICELINKKRPCV2_UNSUBSCRIBEBUTTON_REQUEST_INCLUDE
#define NSSMARTDEVICELINKKRPCV2_UNSUBSCRIBEBUTTON_REQUEST_INCLUDE


#include "ButtonName.h"
#include "JSONHandler/SDLRPCMessage.h"


/*
  interface	Ford Sync RAPI
  version	2.0O
  date		2012-11-02
  generated at	Thu Jan 24 06:36:23 2013
  source stamp	Thu Jan 24 06:35:41 2013
  author	RC
*/

namespace NsSmartDeviceLinkRPCV2
{

///  Unsubscribes from built-in HMI buttons.

  class UnsubscribeButton_request : public NsSmartDeviceLinkRPC::SDLRPCMessage
  {
  public:
  
    UnsubscribeButton_request(const UnsubscribeButton_request& c);
    UnsubscribeButton_request(void);
    
    virtual ~UnsubscribeButton_request(void);
  
    bool checkIntegrity(void);

    const ButtonName& get_buttonName(void) const;

    bool set_buttonName(const ButtonName& buttonName_);

  private:
  
    friend class UnsubscribeButton_requestMarshaller;


///  Name of the button to unsubscribe.
      ButtonName buttonName;
  };

}

#endif
