//
// Copyright (c) 2013 Ford Motor Company
//

#ifndef NSSMARTDEVICELINKKRPC_SUBSCRIBEBUTTON_REQUEST_INCLUDE
#define NSSMARTDEVICELINKKRPC_SUBSCRIBEBUTTON_REQUEST_INCLUDE


#include "ButtonName.h"
#include "JSONHandler/SDLRPCRequest.h"


/*
  interface	Ford Sync RAPI
  version	1.2
  date		2011-05-17
  generated at	Thu Jan 24 06:36:21 2013
  source stamp	Thu Jan 24 06:35:34 2013
  author	RC
*/

namespace NsSmartDeviceLinkRPC
{

/**
     Subscribes to built-in HMI buttons.
     The application will be notified by the OnButtonEvent and OnButtonPress.
     To unsubscribe the notifications, use unsubscribeButton.
*/

  class SubscribeButton_request : public SDLRPCRequest
  {
  public:
  
    SubscribeButton_request(const SubscribeButton_request& c);
    SubscribeButton_request(void);
    
    virtual ~SubscribeButton_request(void);
  
    bool checkIntegrity(void);

    const ButtonName& get_buttonName(void) const;

    bool set_buttonName(const ButtonName& buttonName_);

  private:
  
    friend class SubscribeButton_requestMarshaller;


///  Name of the button to subscribe.
      ButtonName buttonName;
  };

}

#endif
