// Generic.h : main header file for the GENERIC DLL
#if !defined(AFX_GENERIC_H__D9297A81_2711_4A7C_8A6A_2A80EE952546__INCLUDED_)
#define AFX_GENERIC_H__D9297A81_2711_4A7C_8A6A_2A80EE952546__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "QueueWatcher.h"
#include "CallObjectWatcher.h"
#include "Telephony.h"
#include "TaskBar.h"
#include "WaitForCall.h"
/////////////////////////////////////////////////////////////////////////////
// CGenericApp
// See Generic.cpp for the implementation of this class
//

#define LOGINFO 1
#define LOGWARNING 2
#define LOGERROR   3


class CGenericApp : public CWinApp
{
public:
	CGenericApp();
	static CGenericApp* GetGeneric();
	void PrintMessage(_com_error ex, _bstr_t classname, _bstr_t procname, int logtype);
	
	struct CTI_PARAM	*stCTI_PARAM;
	CTaskBar*			stCTI_DUMMY;
	CTelephony			*stCTI_TELEPHONY;
	WaitForCall		m_wait;

	int DUMMYWINDOW;

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
