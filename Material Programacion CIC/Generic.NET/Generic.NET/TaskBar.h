#pragma once
#include "SystemTraySDK.h"

// CTaskBar dialog

class CTaskBar : public CDialog
{
	DECLARE_DYNAMIC(CTaskBar)

public:
	CTaskBar(CWnd* pParent = NULL);   // standard constructor
	BOOL Create();
	virtual ~CTaskBar();
	int CREATED;
	CSystemTray TrayIcon;
	void DestroyTray();
	void CreateTray();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	LRESULT WindowProc(UINT message,WPARAM wParam,LPARAM lParam);
	CWnd* m_pParent;
	int m_nID;

	DECLARE_MESSAGE_MAP()
};
