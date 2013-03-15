//
// Copyright (c) 2013 Ford Motor Company
//

#ifndef NSSMARTDEVICELINKKRPCV2_BUTTONCAPABILITIES_INCLUDE
#define NSSMARTDEVICELINKKRPCV2_BUTTONCAPABILITIES_INCLUDE


#include "ButtonName.h"


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

///  Contains information about a button's capabilities.

  class ButtonCapabilities
  {
  public:
  
    ButtonCapabilities(const ButtonCapabilities& c);
    ButtonCapabilities(void);
  
    bool checkIntegrity(void);
  // getters

    bool get_longPressAvailable(void) const;
    const ButtonName& get_name(void) const;
    bool get_shortPressAvailable(void) const;
    bool get_upDownAvailable(void) const;

// setters

    bool set_longPressAvailable(bool longPressAvailable_);
    bool set_name(const ButtonName& name_);
    bool set_shortPressAvailable(bool shortPressAvailable_);
    bool set_upDownAvailable(bool upDownAvailable_);

  private:

    friend class ButtonCapabilitiesMarshaller;


/**
     The button supports a LONG press.
     Whenever the button is pressed long, onButtonPressed( LONG) will be invoked.
*/
      bool longPressAvailable;

///  The name of the button. See ButtonName.
      ButtonName name;

/**
     The button supports a short press.
     Whenever the button is pressed short, onButtonPressed( SHORT) will be invoked.
*/
      bool shortPressAvailable;

/**
     The button supports "button down" and "button up".
     Whenever the button is pressed, onButtonEvent( DOWN) will be invoked.
     Whenever the button is released, onButtonEvent( UP) will be invoked.
*/
      bool upDownAvailable;
  };

}

#endif
