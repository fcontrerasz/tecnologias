#pragma once
#include "resource.h"

// CTimerDialog dialog

class CTimerDialog : public CDialog
{
	DECLARE_DYNAMIC(CTimerDialog)

public:
	CTimerDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTimerDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT nIDEvent);

	void StartTimer(UINT nIDEvent, int timeout);
	void StopTimer(UINT nIDEvent);
};
