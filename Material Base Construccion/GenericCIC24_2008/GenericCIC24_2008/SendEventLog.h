// SendEventLog.h: interface for the CSendEventLog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SENDEVENTLOG_H__92C38801_FF7D_48D2_A4F2_2BE544EBB2DA__INCLUDED_)
#define AFX_SENDEVENTLOG_H__92C38801_FF7D_48D2_A4F2_2BE544EBB2DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSendEventLog  
{
public:
	BOOL WriteEventLogEntry( LPCTSTR lpMachine,LPCTSTR lpEventSource,WORD    wEventType,WORD    wCatagory,DWORD   dwEventID,PSID    pSID,WORD    wNumStrings,LPCTSTR *lpStrings,DWORD   dwDataSize,LPVOID  lpBinary );
	LPTSTR GetLastErrorString( DWORD dwLastError );
	void SendEventLog(int EventType, int wMessageType, int wCategoryType, const char *fmt);
	HANDLE GetExplorerProcessHandle();
	CSendEventLog();
	virtual ~CSendEventLog();

};

#endif // !defined(AFX_SENDEVENTLOG_H__92C38801_FF7D_48D2_A4F2_2BE544EBB2DA__INCLUDED_)
