// PageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ExternalDLLMETS.h"
#include "PageDlg.h"


// CPageDlg dialog

IMPLEMENT_DYNAMIC(CPageDlg, CDialog)
CPageDlg::CPageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPageDlg::IDD, pParent)
{
}

CPageDlg::~CPageDlg()
{
}

void CPageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPageDlg, CDialog)
END_MESSAGE_MAP()


// CPageDlg message handlers
