#pragma once


// WaitForCall dialog

class WaitForCall : public CDialog
{
	DECLARE_DYNAMIC(WaitForCall)

public:
	WaitForCall(CWnd* pParent = NULL);   // standard constructor
	virtual ~WaitForCall();
	int DoModal();
	void CloseWindow();
// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
