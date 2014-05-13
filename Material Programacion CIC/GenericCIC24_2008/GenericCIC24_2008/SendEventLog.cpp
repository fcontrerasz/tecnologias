// SendEventLog.cpp: implementation of the CSendEventLog class.
//
//////////////////////////////////////////////////////////////////////


#include "stdafx.h"
#include "generic.h"
#include "SendEventLog.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
// EVENTLOG_INFORMATION_TYPE
// EVENTLOG_ERROR_TYPE
// EVENTLOG_WARNING_TYPE
//////////////////////////////////////////////////////////////////////
//Sample LOG
/*		LOG->SendEventLog(EVENTLOG_ERROR_TYPE,LOG_MSG_DLLINFO,LOG_INITIALIZE,"Inicializando DLL sin problem",stCTI_PARAM);
		LOG->SendEventLog(EVENTLOG_WARNING_TYPE,LOG_MSG_DLLINFO,LOG_INITIALIZE,"Inicializando DLL sin problem",stCTI_PARAM);

		LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_FINALIZE,"Inicializando DLL sin problem",stCTI_PARAM);
		LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLERROR,LOG_FINALIZE,"Inicializando DLL sin problem",stCTI_PARAM);
		LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLWARNING,LOG_FINALIZE,"Inicializando DLL sin problem",stCTI_PARAM);

		LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_INITIALIZE,"Inicializando DLL sin problem",stCTI_PARAM);
		LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_DIAL,"Inicializando DLL sin problem",stCTI_PARAM);
		LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_HANGUP,"Inicializando DLL sin problem",stCTI_PARAM);
		LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_RECSTART,"Inicializando DLL sin problem",stCTI_PARAM);
		LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_RECSTOP,"Inicializando DLL sin problem",stCTI_PARAM);
		LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_GETINBOUND,"Inicializando DLL sin problem",stCTI_PARAM);
		LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_FINALIZE,"Inicializando DLL sin problem",stCTI_PARAM);
		LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_OPENPROJECT,"Inicializando DLL sin problem",stCTI_PARAM);
		LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_CLOSEPROJECT,"Inicializando DLL sin problem",stCTI_PARAM);
		LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_ANSWER,"Inicializando DLL sin problem",stCTI_PARAM);
*/
CSendEventLog::CSendEventLog()
{

}

CSendEventLog::~CSendEventLog()
{

}

HANDLE CSendEventLog::GetExplorerProcessHandle()
{
     HANDLE hSnapshot;
     PROCESSENTRY32 pe32;
     ZeroMemory(&pe32,sizeof(pe32));
     HANDLE temp = NULL;

     try
     {
          hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,NULL);

          pe32.dwSize = sizeof(PROCESSENTRY32); 

          if(Process32First(hSnapshot,&pe32))
          {
               do
               {
                    if(!strcmp(pe32.szExeFile,"explorer.exe"))
                    {
                         temp = OpenProcess (PROCESS_ALL_ACCESS,FALSE, pe32.th32ProcessID); 

                         break;
                    }

               }while(Process32Next(hSnapshot,&pe32));
          }
     }
     catch(char *str)
     {
		AfxMessageBox(str);     
     }
     return temp;
}

void CSendEventLog::SendEventLog(int EventType, int wMessageType, int wCategoryType, const char *fmt)
{
	HANDLE hToken;
	TOKEN_USER          oUser[16];
	DWORD               u32Needed;
	TCHAR               sUserName[256], domainName[256];
	DWORD               userNameSize, domainNameSize;
	SID_NAME_USE          sidType;
    TCHAR  szMachineName[64];
    TCHAR  szEventSource[64];
    DWORD  dwEventId   = wMessageType;
    WORD   wEventType  = EventType; 
    WORD   wCategory   = wCategoryType;
    WORD   wNumStrings = 0;
    LPVOID lpdwData    = NULL;  /* No binary data */
	const int nBuffSize = 512;						//Maximum message length
	TCHAR *szMess = new TCHAR[nBuffSize+1]; 			// Buffer to build sting into   
	if( szMess == NULL )
	{
		TRACE( _T("Display() failed to create a buffer (MEMORY LOW!!!)\n") );
		return;
	}
	va_list  argptr;     							// Argument list pointer        
	va_start( argptr, fmt );						// Initialize va_ functions	
	_vsntprintf( szMess, nBuffSize, fmt, argptr );	// prints string to buffer      
	szMess[nBuffSize] = NULL;						// Close off if Overflow occured
	va_end( argptr );
    szMachineName[0] = '\0';
    szEventSource[0] = ' ';


	SetLastError( 0 );
	HANDLE hEventSource = RegisterEventSource( NULL, "GENERICDLL55A" );

	LPCTSTR lpStrings = szMess;



    strncpy_s(szMachineName, "EINSTEIN", sizeof(szMachineName));
    strncpy_s(szEventSource, "GENERICDLL55A", sizeof(szEventSource));


	wNumStrings++;

	ZeroMemory(oUser,sizeof(oUser));

	OpenProcessToken(GetExplorerProcessHandle(), TOKEN_QUERY, &hToken);
	GetTokenInformation(hToken,TokenUser,&oUser[0], sizeof(oUser), &u32Needed);
    userNameSize     = sizeof (sUserName) - 1;
    domainNameSize     = sizeof (domainName) - 1;
          
    LookupAccountSid (NULL, oUser[0].User.Sid, sUserName, &userNameSize, domainName, &domainNameSize, &sidType);


    WriteEventLogEntry( NULL, szEventSource, wEventType, wCategory, dwEventId, oUser[0].User.Sid , wNumStrings, &lpStrings, 0, lpdwData );

}

LPTSTR CSendEventLog::GetLastErrorString(DWORD dwLastError)
{
  LPVOID lpMessageBuffer;

  FormatMessage(
    FORMAT_MESSAGE_ALLOCATE_BUFFER |
    FORMAT_MESSAGE_FROM_SYSTEM,
    NULL,
    dwLastError,
    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
    (LPTSTR) &lpMessageBuffer,
    0,
    NULL );

  return( (LPTSTR)lpMessageBuffer );
}

BOOL CSendEventLog::WriteEventLogEntry(LPCTSTR lpMachine, LPCTSTR lpEventSource, WORD wEventType, WORD wCatagory, DWORD dwEventID, PSID pSID, WORD wNumStrings, LPCTSTR *lpStrings, DWORD dwDataSize, LPVOID lpBinary)
{
    HANDLE hES;
    DWORD  dwError;

    hES = RegisterEventSource( lpMachine, lpEventSource );
    if ( hES )
    {
        if ( ReportEvent( 
          hES,                  /* Handle of event source */
          wEventType,           /* Event type */
          wCatagory,            /* Event category */
          dwEventID,            /* Event identifier */
          pSID,                 /* User Security IDentifer */
          wNumStrings,          /* Number of strings to merge with message */
          dwDataSize,           /* Size of binary data (in bytes) */
          lpStrings,            /* Array of strings to merge with message */
          lpBinary ) )          /* Address of binary data */
        {
          dwError = ERROR_SUCCESS;
        }
        else
        {
          dwError = GetLastError();
          //printf("WRITELOG: ReportEvent: %s (%lu)", GetLastErrorString(dwError), dwError);
        }
        DeregisterEventSource( hES );
    }
    else
    {
      dwError = GetLastError();
      //printf("WRITELOG: RegisterEventSource: %s (%lu)", GetLastErrorString(dwError), dwError);
    }
    return( dwError != ERROR_SUCCESS ? FALSE : TRUE );
}
