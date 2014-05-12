// MyFakeTimer.cpp : implementation file

#include "stdafx.h"
#include "generic.h"
#include "MyFakeTimer.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MyFakeTimer dialog


MyFakeTimer::MyFakeTimer(CWnd* pParent /*=NULL*/)
	: CDialog(MyFakeTimer::IDD, pParent)
{
	//{{AFX_DATA_INIT(MyFakeTimer)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void MyFakeTimer::DoDataExchange(CDataExchange* pDX)
{
	MI_MAIN_AYUDA_CHECK = FALSE;
	MI_ACCIONES_MUDO_CHECK = FALSE;
	MI_ACCIONES_MENSAJE_CHECK = FALSE;
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(MyFakeTimer)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(MyFakeTimer, CDialog)
	//{{AFX_MSG_MAP(MyFakeTimer)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MyFakeTimer message handlers

void MyFakeTimer::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
		
		try{
			if(_FUNCTION_==NO_ANSWER){
				/*mycti->m_DialConnectionResult = DCR_LINE_NOANSWER;*/
				/*CSendEventLog *LOG = new CSendEventLog();
				TCHAR Clog[255];
				_stprintf(Clog, _T("No Answer:\nTSUSER:%s\nTSTERMINAL:%s\nUser:%s\nExtension:%s\nEstación:%s\nProyecto:%s\nPhoneNumber:%s\nBilling Code:%d"), m_SrcUserID, m_SrcWstation,(LPCTSTR)User,(LPCTSTR)Extension,(LPCTSTR)Station,(LPCTSTR)Project,(LPCTSTR)PhoneNumber,(LPCTSTR)BillingCode);
				LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_DIAL,Clog,mycti);*/
			}
			else if (_FUNCTION_==HIDE_BALLOON){
				CGenericApp::GetGeneric()->TrayIcon.HideBalloon();
			}
			/*else if (_FUNCTION_==TS_CUSTOM)
			{
				AfxMessageBox("timer");
			}*/
			KillTimer(1);
			CDialog::OnTimer(nIDEvent);
			
		}
		catch(_com_error ex){
			CSendEventLog *LOG = new CSendEventLog();
			TCHAR Clog[255];
			_stprintf(Clog, _T("Error on MyFakeTimer:%s"),(LPCTSTR)ex.ErrorMessage());
			LOG->SendEventLog(EVENTLOG_ERROR_TYPE,LOG_MSG_DLLERROR,LOG_DIAL,Clog);	
			KillTimer(1);
			CDialog::OnTimer(nIDEvent);
		}
	//
	
}

void MyFakeTimer::StartTimer(int miliseconds, int function)
{
	SetTimer(1,miliseconds,NULL);
	_FUNCTION_=function;
}


void MyFakeTimer::StopTimer()
	{
		if (_FUNCTION_==NO_ANSWER){

		}
		_FUNCTION_=-1;
		KillTimer(1);
	}

LRESULT MyFakeTimer::WindowProc(UINT message,WPARAM wParam,LPARAM lParam)
	{
		int wmId, wmEvent;

		switch (message) 
		{

			case WM_TIMER:
				wmId    = LOWORD(wParam); 
				wmEvent = HIWORD(wParam); 
				OnTimer(wmId);
				return DefWindowProc(message,wParam,lParam);

		    case WM_ICON_NOTIFY:
			     return CGenericApp::GetGeneric()->TrayIcon.OnTrayNotification(wParam,lParam);

			case WM_COMMAND:
				wmId    = LOWORD(wParam); 
				wmEvent = HIWORD(wParam); 
				// Parse the menu selections:
				switch (wmId)
				{

						case ID_ACCIONES_TEST:
							CGenericApp::GetGeneric()->TrayIcon.ShowBalloon("No Implementado aún","Telescript-CIC",NIIF_INFO,5);
							StartTimer(3000,HIDE_BALLOON);
							return DefWindowProc(message,wParam,lParam);

                        /*case MI_MAIN_AYUDA:
							CGenericApp::GetGeneric()->TrayIcon.ShowBalloon("Generic 56 DLL Interface by METS","Telescript-CIC",NIIF_INFO,1);
							StartTimer(3000,HIDE_BALLOON);
							return DefWindowProc(message,wParam,lParam);*/
						
						default:
							return DefWindowProc(message,wParam,lParam);
				}
			default:
				return DefWindowProc(message,wParam,lParam);
		}

	}
	