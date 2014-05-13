// TaskBar.cpp : implementation file
//

#include "stdafx.h"
#include "Generic.h"
#include "TaskBar.h"


// CTaskBar dialog
#define WM_MY_TRAY_NOTIFICATION WM_APP+100

IMPLEMENT_DYNAMIC(CTaskBar, CDialog)
CTaskBar::CTaskBar(CWnd* pParent /*=NULL*/)
	: CDialog(CTaskBar::IDD, pParent)
{
	ASSERT(pParent != NULL);

	m_pParent = pParent;
	m_nID = CTaskBar::IDD;
}

CTaskBar::~CTaskBar()
{
}

BOOL CTaskBar::Create()
{
	CREATED=0;
	return CDialog::Create(m_nID, m_pParent);
}

void CTaskBar::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

void CTaskBar::PostNcDestroy()
{
	delete this;
}

void CTaskBar::CreateTray()
{
	if (CREATED==0)
	{
		TrayIcon.Create(CGenericApp::GetGeneric()->m_hInstance,
			this->m_hWnd,
			WM_MY_TRAY_NOTIFICATION,
			_T("Generic DLL for Telescript 6.0 METS S.A."), 
			::LoadIcon(CGenericApp::GetGeneric()->m_hInstance, (LPCTSTR)IDI_ICON1),
			IDR_MENU1);
		CREATED=1;
	}
}

void CTaskBar::DestroyTray()
{
	if (CREATED==1)
	{
		TrayIcon.RemoveIcon();
		CREATED=0;
	}
}
LRESULT CTaskBar::WindowProc(UINT message,WPARAM wParam,LPARAM lParam)
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
					case ID_MENU_TEST:
						TrayIcon.ShowBalloon("Test","Test",NIIF_NONE,2);
						AfxMessageBox("Menu 1");

					default:
						return DefWindowProc(message, wParam, lParam);
				}

			default:
				return DefWindowProc(message,wParam,lParam);
		}
		
}

BEGIN_MESSAGE_MAP(CTaskBar, CDialog)
END_MESSAGE_MAP()


// CTaskBar message handlers
