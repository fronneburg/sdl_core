//
// Copyright (c) 2013 Ford Motor Company
//

#ifndef NSSMARTDEVICELINKKRPCV2_DELETESUBMENU_RESPONSE_INCLUDE
#define NSSMARTDEVICELINKKRPCV2_DELETESUBMENU_RESPONSE_INCLUDE

#include "JSONHandler/SDLRPCResponse.h"

/*
  interface Ford Sync RAPI
  version   2.0O
  date      2012-11-02
  generated at  Thu Jan 24 06:36:23 2013
  source stamp  Thu Jan 24 06:35:41 2013
  author    RC
*/

namespace NsSmartDeviceLinkRPCV2
{
    class DeleteSubMenu_response : public NsSmartDeviceLinkRPC::SDLRPCResponse
    {
    public:
        DeleteSubMenu_response(const DeleteSubMenu_response& c);
        DeleteSubMenu_response(void);

        virtual ~DeleteSubMenu_response(void);

        DeleteSubMenu_response& operator =(const DeleteSubMenu_response&);

        bool checkIntegrity(void);

    private:
        friend class DeleteSubMenu_responseMarshaller;
    };
}

#endif
