//
// Copyright (c) 2013 Ford Motor Company
//

#ifndef NSSMARTDEVICELINKKRPCV2_LISTFILES_REQUEST_INCLUDE
#define NSSMARTDEVICELINKKRPCV2_LISTFILES_REQUEST_INCLUDE


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

/**
     Requests the current list of resident filenames for the registered app
     Not supported on first generation SYNC vehicles. 
*/

  class ListFiles_request : public NsSmartDeviceLinkRPC::SDLRPCMessage
  {
  public:
  
    ListFiles_request(const ListFiles_request& c);
    ListFiles_request(void);
    
    virtual ~ListFiles_request(void);
  
    bool checkIntegrity(void);



  private:
  
    friend class ListFiles_requestMarshaller;

  };

}

#endif
