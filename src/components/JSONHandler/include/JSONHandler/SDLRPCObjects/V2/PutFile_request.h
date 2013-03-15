//
// Copyright (c) 2013 Ford Motor Company
//

#ifndef NSSMARTDEVICELINKKRPCV2_PUTFILE_REQUEST_INCLUDE
#define NSSMARTDEVICELINKKRPCV2_PUTFILE_REQUEST_INCLUDE

#include <string>

#include "FileType.h"
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
     Used to push a binary data onto the SYNC module from a mobile device, such as icons and album art
     Not supported on first generation SYNC vehicles. 
*/

  class PutFile_request : public NsSmartDeviceLinkRPC::SDLRPCMessage
  {
  public:
  
    PutFile_request(const PutFile_request& c);
    PutFile_request(void);
    
    virtual ~PutFile_request(void);
  
    PutFile_request& operator =(const PutFile_request&);
  
    bool checkIntegrity(void);

    const std::string& get_syncFileName(void) const;
    const FileType& get_fileType(void) const;
    const bool* get_persistentFile(void) const;
    const std::string* get_fileData(void) const;

    bool set_syncFileName(const std::string& syncFileName_);
    bool set_fileType(const FileType& fileType_);
    void reset_persistentFile(void);
    bool set_persistentFile(bool persistentFile_);
    void reset_fileData(void);
    bool set_fileData(const std::string& fileData_);

  private:
  
    friend class PutFile_requestMarshaller;


///  File reference name.
      std::string syncFileName;	//!< (500)

///  Selected file type.
      FileType fileType;

/**
     Indicates if the file is meant to persist between sessions / ignition cycles.
     If set to TRUE, then the system will aim to persist this file through session / cycles.
     While files with this designation will have priority over others, they are subject to deletion by the system at any time.
     In the event of automatic deletion by the system, the app will receive a rejection and have to resend the file.
     If omitted, the value will be set to false.
*/
      bool* persistentFile;

///  Binary data.
      std::string* fileData;
  };

}

#endif
