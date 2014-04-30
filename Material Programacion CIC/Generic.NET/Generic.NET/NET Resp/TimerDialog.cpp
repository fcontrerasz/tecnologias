#include "stdafx.h"
#include "TimerDialog.h"

// CTimerDialog dialog

IMPLEMENT_DYNAMIC(CTimerDialog, CDialog)
CTimerDialog::CTimerDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CTimerDialog::IDD, pParent)
{
}

CTimerDialog::~CTimerDialog()
{
}

void CTimerDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTimerDialog, CDialog)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CTimerDialog message handlers

void CTimerDialog::OnTimer(UINT nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	AfxMessageBox("Time");
	CDialog::OnTimer(nIDEvent);
}

void CTimerDialog::StartTimer(UINT nIDEvent, int timeout)
{
	SetTimer(nIDEvent,timeout,NULL);
}

void CTimerDialog::StopTimer(UINT nIDEvent)
{
	KillTimer(nIDEvent);
}
