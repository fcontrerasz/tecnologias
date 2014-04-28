//
//  Values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//


//
// Define the severity codes
//


//
// MessageId: LOG_MSG_DLLINFO_SYSTEM
//
// MessageText:
//
//  INFO DE DLL : %1
//
#define LOG_MSG_DLLINFO_SYSTEM           0x00000001L

//
// MessageId: LOG_MSG_DLLINFO
//
// MessageText:
//
//  INFO DE DLL : %1
//
#define LOG_MSG_DLLINFO                  0x00000002L

//
// MessageId: LOG_MSG_DLLERROR
//
// MessageText:
//
//  ERROR DE DLL : %1
//
#define LOG_MSG_DLLERROR                 0x00000003L

//
// MessageId: LOG_MSG_DLLWARNING
//
// MessageText:
//
//  WARNING DE DLL : %1
//
#define LOG_MSG_DLLWARNING               0x00000004L

