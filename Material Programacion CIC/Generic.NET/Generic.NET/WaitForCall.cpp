// WaitForCall.cpp : implementation file
//
#include "stdafx.h"
#include "Generic.h"
#include "WaitForCall.h"



// WaitForCall dialog

IMPLEMENT_DYNAMIC(WaitForCall, CDialog)
WaitForCall::WaitForCall(CWnd* pParent /*=NULL*/)
	: CDialog(WaitForCall::IDD, pParent)
{
}

WaitForCall::~WaitForCall()
{
}

void WaitForCall::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

int WaitForCall::DoModal(){
	return CDialog::DoModal();
}

void WaitForCall::CloseWindow(){
	CDialog::OnOK();
}

void WaitForCall::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void WaitForCall::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

// WaitForCall message handlers
BEGIN_MESSAGE_MAP(WaitForCall, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
END_MESSAGE_MAP()

