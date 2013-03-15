//
// Copyright (c) 2013 Ford Motor Company
//

#ifndef NSSMARTDEVICELINKKRPCV2_ALERTMANEUVER_RESPONSE_INCLUDE
#define NSSMARTDEVICELINKKRPCV2_ALERTMANEUVER_RESPONSE_INCLUDE

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
    class AlertManeuver_response : public NsSmartDeviceLinkRPC::SDLRPCResponse
    {
    public:
        AlertManeuver_response(const AlertManeuver_response& c);
        AlertManeuver_response(void);

        virtual ~AlertManeuver_response(void);

        AlertManeuver_response& operator =(const AlertManeuver_response&);

        bool checkIntegrity(void);

    private:
        friend class AlertManeuver_responseMarshaller;
    };
}

#endif
