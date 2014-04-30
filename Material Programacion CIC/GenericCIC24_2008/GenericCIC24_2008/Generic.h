// Generic.h : main header file for the GENERIC DLL
//

#if !defined(AFX_GENERIC_H__D9297A81_2711_4A7C_8A6A_2A80EE952546__INCLUDED_)
#define AFX_GENERIC_H__D9297A81_2711_4A7C_8A6A_2A80EE952546__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif
#define	WM_ICON_NOTIFY WM_APP+10

#include "resource.h"		// main symbols
#include "SendEventLog.h"
#include "QueueWatcher.h"
#include "Mensajes.h"
#include "Categorias.h"
#include "cti.h"
#include "MyFakeTimer.h"
#include "SystemTraySDK.h"
/////////////////////////////////////////////////////////////////////////////
// CGenericApp
// See Generic.cpp for the implementation of this class
//

class CGenericApp : public CWinApp
{
public:
	CGenericApp();
	static CGenericApp * GetGeneric();
	void HangupCall();
	void HangupCallQueue();
	void DialNumber(CString Number);
	void PlayDigits(CString Number);
	void Hold();
	void UnHold();
	void BlindTransfer(CString Number);
	void AddAttToCurrentCall(CString att_name, CString att_value);
	char* CGenericApp::ConvertBSTRToString(BSTR pSrc);

	LPCTSTR m_ProjectName;
	LPCTSTR m_TSUser;

	long CALLID;

	CSendEventLog *LOG;
	
	IEICServer2Ptr       m_pEICServer;
	ISIPPhonePtr		 m_pSIPPhone;
	IEICCallObjectPtr    m_pEICCallObject;
	IEICQueuePtr		 m_pEICQueue; 
	IEICDSUserPtr        m_pEICDSUser;
	CQueueWatcher*		 m_QueueWatcher;

	struct CTI_PARAM *stCTI_PARAM;

	CString User;
	CString Password;
	CString Name;
	CString Station;

	CSystemTray TrayIcon;
	MyFakeTimer * mytime;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGenericApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CGenericApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GENERIC_H__D9297A81_2711_4A7C_8A6A_2A80EE952546__INCLUDED_)
