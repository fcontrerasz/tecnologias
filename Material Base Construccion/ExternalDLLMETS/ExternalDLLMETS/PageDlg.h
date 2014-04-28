#pragma once


// CPageDlg dialog

class CPageDlg : public CDialog
{
	DECLARE_DYNAMIC(CPageDlg)

public:
	CPageDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CPageDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
