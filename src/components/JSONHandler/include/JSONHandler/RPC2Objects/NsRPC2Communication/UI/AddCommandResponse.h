//
// Copyright (c) 2013 Ford Motor Company
//

#ifndef NSRPC2COMMUNICATION_UI_ADDCOMMANDRESPONSE_INCLUDE
#define NSRPC2COMMUNICATION_UI_ADDCOMMANDRESPONSE_INCLUDE

#include "JSONHandler/RPC2Response.h"


/*
  interface	NsRPC2Communication::UI
  version	1.2
  generated at	Thu Jan 24 06:41:15 2013
  source stamp	Wed Jan 23 13:56:28 2013
*/

namespace NsRPC2Communication
{
  namespace UI
  {

    class AddCommandResponse : public ::NsRPC2Communication::RPC2Response
    {
    public:
    
      AddCommandResponse(const AddCommandResponse& c);
      AddCommandResponse(void);
    
      AddCommandResponse& operator =(const AddCommandResponse&);
    
      virtual ~AddCommandResponse(void);
    
      bool checkIntegrity(void);
    

    private:

      friend class AddCommandResponseMarshaller;


    };
  }
}

#endif
