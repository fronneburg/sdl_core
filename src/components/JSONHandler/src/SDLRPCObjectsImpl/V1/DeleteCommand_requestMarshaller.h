//
// Copyright (c) 2013 Ford Motor Company
//

#ifndef NSSMARTDEVICELINKRPC_DELETECOMMAND_REQUESTMARSHALLER_INCLUDE
#define NSSMARTDEVICELINKRPC_DELETECOMMAND_REQUESTMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../include/JSONHandler/SDLRPCObjects/V1/DeleteCommand_request.h"


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

  struct DeleteCommand_requestMarshaller
  {
    static bool checkIntegrity(DeleteCommand_request& e);
    static bool checkIntegrityConst(const DeleteCommand_request& e);
  
    static bool fromString(const std::string& s,DeleteCommand_request& e);
    static const std::string toString(const DeleteCommand_request& e);
  
    static bool fromJSON(const Json::Value& s,DeleteCommand_request& e);
    static Json::Value toJSON(const DeleteCommand_request& e);
  };
}

#endif
