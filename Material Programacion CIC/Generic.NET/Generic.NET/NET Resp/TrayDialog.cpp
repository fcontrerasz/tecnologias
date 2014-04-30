#include "stdafx.h"
#include "Generic.h"
#include ".\traydialog.h"


#define WM_MY_TRAY_NOTIFICATION WM_APP+10

// CTrayDialog dialog



CTrayDialog::CTrayDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CTrayDialog::IDD, pParent)
{

}

CTrayDialog::~CTrayDialog()
{
}

void CTrayDialog::CreateTray()
{
 /*TrayIcon.Create(CGenericApp::GetGeneric()->m_hInstance,
	GetSafeHwnd(),
	WM_MY_TRAY_NOTIFICATION,
    _T("Generic DLL for Telescript 6.0 METS S.A."), 
    ::LoadIcon(CGenericApp::GetGeneric()->m_hInstance, (LPCTSTR)IDI_ICON1),
	IDR_MENU2);*/
	
}

void CTrayDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

LRESULT CTrayDialog::OnTrayNotification(WPARAM wp, LPARAM lp)
{
	return 0;
	
}

void CTrayDialog::DestroyTray()
{
	TrayIcon.RemoveIcon();
}


LRESULT CTrayDialog::WindowProc(UINT message,WPARAM wParam,LPARAM lParam)
{
		int wmId, wmEvent, lmId, lmEvent;
		wmId    = LOWORD(wParam); 
		wmEvent = HIWORD(wParam);
		lmId	= LOWORD(lParam);
		lmEvent	= HIWORD(lParam);

		switch (message) 
		{
		    case WM_MY_TRAY_NOTIFICATION:
				return TrayIcon.OnTrayNotification(wParam,lParam);

			case WM_COMMAND:
				
				switch(wmId)
				{
					case ID_GENERICDLL_ABOUT:
						AfxMessageBox("Menu 1");
				}
				return DefWindowProc(message,wParam,lParam);

			default:
				return DefWindowProc(message,wParam,lParam);
		}
		
}

