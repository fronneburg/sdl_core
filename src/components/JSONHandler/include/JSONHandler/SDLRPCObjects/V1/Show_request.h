//
// Copyright (c) 2013 Ford Motor Company
//

#ifndef NSSMARTDEVICELINKKRPC_SHOW_REQUEST_INCLUDE
#define NSSMARTDEVICELINKKRPC_SHOW_REQUEST_INCLUDE

#include <string>

#include "TextAlignment.h"
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

///  Updates the persistent display. Supported fields depend on display capabilities.

  class Show_request : public SDLRPCRequest
  {
  public:
  
    Show_request(const Show_request& c);
    Show_request(void);
    
    virtual ~Show_request(void);
  
    Show_request& operator =(const Show_request&);
  
    bool checkIntegrity(void);

    const std::string* get_mainField1(void) const;
    const std::string* get_mainField2(void) const;
    const TextAlignment* get_alignment(void) const;
    const std::string* get_statusBar(void) const;
    const std::string* get_mediaClock(void) const;
    const std::string* get_mediaTrack(void) const;

    void reset_mainField1(void);
    bool set_mainField1(const std::string& mainField1_);
    void reset_mainField2(void);
    bool set_mainField2(const std::string& mainField2_);
    void reset_alignment(void);
    bool set_alignment(const TextAlignment& alignment_);
    void reset_statusBar(void);
    bool set_statusBar(const std::string& statusBar_);
    void reset_mediaClock(void);
    bool set_mediaClock(const std::string& mediaClock_);
    void reset_mediaTrack(void);
    bool set_mediaTrack(const std::string& mediaTrack_);

  private:
  
    friend class Show_requestMarshaller;


/**
     The text that should be displayed in a single or upper display line.
     If this text is not set, the text of mainField1 stays unchanged.
     If this text is empty "", the field will be cleared.
*/
      std::string* mainField1;	//!< (500)

/**
     The text that should be displayed on the second dispay line.
     If this text is not set, the text of mainField2 stays unchanged.
     If this text is empty "", the field will be cleared.
*/
      std::string* mainField2;	//!< (500)

/**
     Specifies how mainField1 and mainField2 texts should be aligned on display.
     If omitted, texts will be centered
*/
      TextAlignment* alignment;

///  Requires investigation regarding the nav display capabilities. Potentially lower lowerStatusBar, upperStatusBar, titleBar, etc.
      std::string* statusBar;	//!< (500)

/**
     Text value for MediaClock field. Has to be properly formatted by Mobile App according to Sync capabilities.
     If this text is set, any automatic media clock updates previously set with SetMediaClockTimer will be stopped.
*/
      std::string* mediaClock;	//!< (500)

/**
     The text that should be displayed in the track field.
     This field is only valid for media applications on NGN type ACMs.
     If this text is not set, the text of mediaTrack stays unchanged.
     If this text is empty "", the field will be cleared.
*/
      std::string* mediaTrack;	//!< (500)
  };

}

#endif
