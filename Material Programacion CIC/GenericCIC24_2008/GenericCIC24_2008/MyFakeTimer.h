#if !defined(AFX_MYFAKETIMER_H__30150C05_55D9_431F_A037_11091A3B87E3__INCLUDED_)
#define AFX_MYFAKETIMER_H__30150C05_55D9_431F_A037_11091A3B87E3__INCLUDED_

#define NO_ANSWER 0
#define HIDE_BALLOON 1
#define TS_CUSTOM 2

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyFakeTimer.h : header file
//
#include "Resource.h"
/////////////////////////////////////////////////////////////////////////////
// MyFakeTimer dialog

class MyFakeTimer : public CDialog
{
// Construction
public:
	void StartTimer(int miliseconds, int function);
	void StopTimer();
	MyFakeTimer(CWnd* pParent = NULL);   // standard constructor

	int _FUNCTION_;

	BOOL MI_MAIN_AYUDA_CHECK;
	BOOL MI_ACCIONES_MUDO_CHECK;
	BOOL MI_ACCIONES_MENSAJE_CHECK;

// Dialog Data
	//{{AFX_DATA(MyFakeTimer)
	enum { IDD = IDD_DIALOG2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MyFakeTimer)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	LRESULT WindowProc(UINT message,WPARAM wParam,LPARAM lParam);
	// Generated message map functions
	//{{AFX_MSG(MyFakeTimer)
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYFAKETIMER_H__30150C05_55D9_431F_A037_11091A3B87E3__INCLUDED_)
