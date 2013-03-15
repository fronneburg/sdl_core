//
// Copyright (c) 2013 Ford Motor Company
//

#ifndef NSRPC2COMMUNICATION_VR_GETLANGUAGE_INCLUDE
#define NSRPC2COMMUNICATION_VR_GETLANGUAGE_INCLUDE

#include "JSONHandler/RPC2Request.h"


/*
  interface	NsRPC2Communication::VR
  version	1.2
  generated at	Thu Jan 24 06:41:15 2013
  source stamp	Wed Jan 23 13:56:28 2013
  author	RC
*/

namespace NsRPC2Communication
{
  namespace VR
  {

    class GetLanguage : public ::NsRPC2Communication::RPC2Request
    {
    public:
    
      GetLanguage(const GetLanguage& c);
      GetLanguage(void);
    
      GetLanguage& operator =(const GetLanguage&);
    
      virtual ~GetLanguage(void);
    
      bool checkIntegrity(void);
    

    private:

      friend class GetLanguageMarshaller;


    };
  }
}

#endif
