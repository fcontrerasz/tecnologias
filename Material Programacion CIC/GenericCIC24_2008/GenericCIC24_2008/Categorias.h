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
// MessageId: LOG_INITIALIZE
//
// MessageText:
//
//  Initialize
//
#define LOG_INITIALIZE                   0x00000001L

//
// MessageId: LOG_DIAL
//
// MessageText:
//
//  Dial
//
#define LOG_DIAL                         0x00000002L

//
// MessageId: LOG_HANGUP
//
// MessageText:
//
//  HangUp
//
#define LOG_HANGUP                       0x00000003L

//
// MessageId: LOG_RECSTART
//
// MessageText:
//
//  Recording Start
//
#define LOG_RECSTART                     0x00000004L

//
// MessageId: LOG_RECSTOP
//
// MessageText:
//
//  Recording Stop
//
#define LOG_RECSTOP                      0x00000005L

//
// MessageId: LOG_FINALIZE
//
// MessageText:
//
//  Finalize
//
#define LOG_FINALIZE                     0x00000006L

//
// MessageId: LOG_GETINBOUND
//
// MessageText:
//
//  GetInbound
//
#define LOG_GETINBOUND                   0x00000007L

//
// MessageId: LOG_OPENPROJECT
//
// MessageText:
//
//  Open Project
//
#define LOG_OPENPROJECT                  0x00000008L

//
// MessageId: LOG_CLOSEPROJECT
//
// MessageText:
//
//  Close Project
//
#define LOG_CLOSEPROJECT                 0x00000009L

//
// MessageId: LOG_ANSWER
//
// MessageText:
//
//  Answer
//
#define LOG_ANSWER                       0x0000000AL

