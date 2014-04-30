#pragma once
#include "resource.h"
#include "SystemTraySDK.h"

// CTrayDialog dialog

class CTrayDialog : public CDialog
{

public:

	CTrayDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTrayDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG };

protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	LRESULT WindowProc(UINT message,WPARAM wParam,LPARAM lParam);
	
public:
	LRESULT OnTrayNotification(WPARAM wp, LPARAM lp);
	void CreateTray();
	void DestroyTray();
	CSystemTray TrayIcon;

};
