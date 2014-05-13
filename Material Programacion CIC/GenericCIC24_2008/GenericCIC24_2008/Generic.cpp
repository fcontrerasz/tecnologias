// Generic.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "Generic.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


BEGIN_MESSAGE_MAP(CGenericApp, CWinApp)
	//{{AFX_MSG_MAP(CGenericApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGenericApp construction

CGenericApp::CGenericApp()
{
	LOG = new CSendEventLog();
	CALLID=0;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CGenericApp object

static CGenericApp app;


CGenericApp * CGenericApp::GetGeneric(){
	return & app;
}

BOOL GetLastTelephonyError(char *strError)
{
	strcpy_s(strError,sizeof(strError),"Dll no cargada correctamente");
	return(TRUE);
}

void CGenericApp::AddAttToCurrentCall(CString att_name, CString att_value)
{
	TCHAR log[255];

	if (CGenericApp::GetGeneric()->CALLID > 0)
	{
		IEICCallObjectPtr p_Object;
		p_Object = EICClientCOMLib::IEICCallObjectPtr(__uuidof(EICClientCOMLib::EICCallObject));
		try{

			p_Object->Id = CGenericApp::GetGeneric()->CALLID;

			p_Object->SetNamedAttribute(att_name.AllocSysString(),att_value.AllocSysString());

			_stprintf_s(log, _T("SET ATTRIBUTE -> %s == %s"),att_name,att_value);
			LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_DIAL,log);
		}
		catch(_com_error ex)
		{
			_stprintf_s(log, _T("SET ATTRIBUTE ERROR: %s"), (LPCTSTR)ex.Description());
			LOG->SendEventLog(EVENTLOG_ERROR_TYPE,LOG_MSG_DLLERROR,LOG_DIAL,log);
		}
	}


}

void CGenericApp::HangupCall()
{
	TCHAR log[255];

	if (CGenericApp::GetGeneric()->CALLID > 0)
	{
		IEICCallObjectPtr p_Object;
		p_Object = EICClientCOMLib::IEICCallObjectPtr(__uuidof(EICClientCOMLib::EICCallObject));
		try{

			p_Object->Id = CGenericApp::GetGeneric()->CALLID;
			p_Object->Disconnect(L"");
			_stprintf_s(log, _T("HANGUP"));
			LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_HANGUP,log);
		}
		catch(_com_error ex)
		{
			_stprintf_s(log, _T("HANGUP ERROR: %s"), (LPCTSTR)ex.Description());
			LOG->SendEventLog(EVENTLOG_ERROR_TYPE,LOG_MSG_DLLERROR,LOG_HANGUP,log);
		}
	}
}

void CGenericApp::HangupCallQueue()
{
	TCHAR log[255];

	CGenericApp::GetGeneric()->m_pEICQueue->StartObjectsList();

	long ctype, cid;
	ctype=0;
	cid=0;

	try
	{
		CGenericApp::GetGeneric()->m_pEICQueue->GetNextObject(&ctype,&cid);
	}
	catch(_com_error ex)
	{
		_stprintf_s(log, _T("HANGUP ERROR: %s"), (LPCTSTR)ex.Description());
		LOG->SendEventLog(EVENTLOG_ERROR_TYPE,LOG_MSG_DLLERROR,LOG_HANGUP,log);
	}

	while (cid!=NULL && cid>0)
	{
		IEICCallObjectPtr p_Object;
		p_Object = EICClientCOMLib::IEICCallObjectPtr(__uuidof(EICClientCOMLib::EICCallObject));
		try{

			p_Object->Id = cid;
			p_Object->Disconnect(L"");
			_stprintf_s(log, _T("HANGUPCALLQUEUE"));
			LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_HANGUP,log);
			cid = 0;
			ctype = 0;
			try
			{
				CGenericApp::GetGeneric()->m_pEICQueue->GetNextObject(&ctype,&cid);
			}
			catch(_com_error ex)
			{
				_stprintf_s(log, _T("HANGUPCALLQUEUE ERROR: %s"), (LPCTSTR)ex.Description());
				LOG->SendEventLog(EVENTLOG_ERROR_TYPE,LOG_MSG_DLLERROR,LOG_HANGUP,log);
			}
		}
		catch(_com_error ex)
		{
			_stprintf_s(log, _T("HANGUPCALLQUEUE ERROR: %s"), (LPCTSTR)ex.Description());
			LOG->SendEventLog(EVENTLOG_ERROR_TYPE,LOG_MSG_DLLERROR,LOG_HANGUP,log);
		}
	}
}

void CGenericApp::DialNumber(CString Number)
{
	TCHAR log[255];

	m_pEICCallObject = EICClientCOMLib::IEICCallObjectPtr(__uuidof(EICClientCOMLib::EICCallObject));
	try{
		m_pEICCallObject->ExtendedDial(Number.AllocSysString(),30,FALSE,TRUE);
		stCTI_PARAM->m_DialConnectionResult = DCR_WAITING_FOR_RESULT;
		_stprintf_s(log, _T("DIAL:\nNumber: %s"),Number);
		LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_DIAL,log);
	}
	catch(_com_error ex)
	{
		_stprintf_s(log, _T("DIAL ERROR: %s"), (LPCTSTR)ex.Description());
		LOG->SendEventLog(EVENTLOG_ERROR_TYPE,LOG_MSG_DLLERROR,LOG_DIAL,log);
	}
}

void CGenericApp::PlayDigits(CString Number)
{
	TCHAR log[255];

	if (CGenericApp::GetGeneric()->CALLID > 0)
	{
		IEICCallObjectPtr p_Object;
		p_Object = EICClientCOMLib::IEICCallObjectPtr(__uuidof(EICClientCOMLib::EICCallObject));
		try
		{
			p_Object->Id = CGenericApp::GetGeneric()->CALLID;
			p_Object->PlayDigits(Number.AllocSysString());
			_stprintf_s(log, _T("PLAYDIGITS %s"),Number);
			LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_DIAL,log);
		}
		catch(_com_error ex)
		{
			_stprintf_s(log, _T("PLAYDIGITS ERROR: %s"), (LPCTSTR)ex.Description());
			LOG->SendEventLog(EVENTLOG_ERROR_TYPE,LOG_MSG_DLLERROR,LOG_DIAL,log);
		}
	}

}
void CGenericApp::Hold()
{
	TCHAR log[255];
	if (CGenericApp::GetGeneric()->CALLID > 0)
	{
		IEICCallObjectPtr p_Object;
		p_Object = EICClientCOMLib::IEICCallObjectPtr(__uuidof(EICClientCOMLib::EICCallObject));
		try
		{
			p_Object->Id = CGenericApp::GetGeneric()->CALLID;
			p_Object->Hold(L"",L"");
			_stprintf_s(log, _T("HOLD"));
			LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_DIAL,log);
		}
		catch(_com_error ex)
		{
			_stprintf_s(log, _T("HOLD ERROR: %s"), (LPCTSTR)ex.Description());
			LOG->SendEventLog(EVENTLOG_ERROR_TYPE,LOG_MSG_DLLERROR,LOG_DIAL,log);
		}
	}
}

void CGenericApp::UnHold()
{
	TCHAR log[255];
	if (CGenericApp::GetGeneric()->CALLID > 0)
	{
		IEICCallObjectPtr p_Object;
		p_Object = EICClientCOMLib::IEICCallObjectPtr(__uuidof(EICClientCOMLib::EICCallObject));
		try
		{
			p_Object->Id = CGenericApp::GetGeneric()->CALLID;
			p_Object->Pickup(L"");
			_stprintf_s(log, _T("UNHOLD"));
			LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_DIAL,log);
		}
		catch(_com_error ex)
		{
			_stprintf_s(log, _T("UNHOLD ERROR: %s"), (LPCTSTR)ex.Description());
			LOG->SendEventLog(EVENTLOG_ERROR_TYPE,LOG_MSG_DLLERROR,LOG_DIAL,log);
		}
	}
}

void CGenericApp::BlindTransfer(CString Number)
{
	TCHAR log[255];
	if (CGenericApp::GetGeneric()->CALLID > 0)
	{
		IEICCallObjectPtr p_Object;
		p_Object = EICClientCOMLib::IEICCallObjectPtr(__uuidof(EICClientCOMLib::EICCallObject));
		try
		{
			p_Object->Id = CGenericApp::GetGeneric()->CALLID;
			p_Object->BlindTransfer(Number.AllocSysString(),L"");
			_stprintf_s(log, _T("TRANSFER:\nNUMBER:%s"),Number);
			LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_DIAL,log);
		}
		catch(_com_error ex)
		{
			_stprintf_s(log, _T("TRANSFER ERROR: %s"), (LPCTSTR)ex.Description());
			LOG->SendEventLog(EVENTLOG_ERROR_TYPE,LOG_MSG_DLLERROR,LOG_DIAL,log);
		}
	}
}

BOOL CallCti(struct CTI_PARAM *stCTI_PARAM)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CoInitialize(NULL);
	AfxEnableControlContainer(); 	

	TCHAR log[255];

	CGenericApp::GetGeneric()->stCTI_PARAM = stCTI_PARAM;

	switch(stCTI_PARAM->m_Action)
	{
	case TELESCRIPT_COMMAND_OPENTELEPHONYPROJECT:
		{
			CGenericApp::GetGeneric()->m_ProjectName = (LPCTSTR)stCTI_PARAM->m_ProjectName;
		}
		break;

	case TELESCRIPT_COMMAND_CLOSETELEPHONYPROJECT:
		{

		}
		break;

	case TELEPHONY_COMMAND_HANGUP:
		{
			CGenericApp::GetGeneric()->HangupCallQueue();
		}
		break;

	case TELEPHONY_COMMAND_DIAL:
		{
			TCHAR tempNumber[255];
			TCHAR tempNumber_2[255];
			CString tempNumberC, tempNumberC_2, tempNumberC_3;

			_stprintf_s(tempNumber, _T("%s"), (LPCTSTR)stCTI_PARAM->m_PhoneNumber);
			_stprintf_s(tempNumber_2, _T("%s"), (LPCTSTR)stCTI_PARAM->m_PhoneNumber);
			tempNumberC = tempNumber_2;
			tempNumberC_2 = tempNumberC.Left(2); 

			if (tempNumberC_2.Compare(_T("#1"))==0){
				//XTelelink
				tempNumberC_3 = tempNumberC.Mid(2);
				CGenericApp::GetGeneric()->AddAttToCurrentCall(L"IC_METS_XTelelink",tempNumberC_3);

			}
			else if (tempNumberC_2.Left(2).Compare(_T("#2"))==0){
				//Correlat
				tempNumberC_3 = tempNumberC.Mid(2);
				CGenericApp::GetGeneric()->AddAttToCurrentCall(L"IC_METS_Correlat",tempNumberC_3);
			}
			else if (tempNumberC_2.Left(2).Compare(_T("#3"))==0){
				//PlayDigits
				tempNumberC_3 = tempNumberC.Mid(2);
				CGenericApp::GetGeneric()->PlayDigits(tempNumberC_3.AllocSysString());
			}
			else if (tempNumberC.GetLength()>6)
			{
				//Dial
				CGenericApp::GetGeneric()->HangupCallQueue();
				CGenericApp::GetGeneric()->DialNumber(tempNumber);
			}
			else
			{
				_stprintf_s(log, _T("No se puede discar este numero:\nNUMBER:%s"),tempNumber);
				CGenericApp::GetGeneric()->LOG->SendEventLog(EVENTLOG_WARNING_TYPE,LOG_MSG_DLLWARNING,LOG_DIAL,log);
				stCTI_PARAM->m_DialConnectionResult = DCR_WAITING_FOR_RESULT;
				stCTI_PARAM->m_DialConnectionResult = DCR_LINE_NO_CONTACT;
				CGenericApp::GetGeneric()->TrayIcon.ShowBalloon(log,"Telescript-CIC",NIIF_INFO,1);
				CGenericApp::GetGeneric()->mytime->StartTimer(1500,HIDE_BALLOON);
			}
		}
		break;
		
	case TELEPHONY_COMMAND_GETINBOUND:
		{


		}
		break;

	case TELEPHONY_COMMAND_INITIALIZE:
		{
			HWND hWnd;
			CWnd * cWnd;

			HINSTANCE hInst;
			CGenericApp::GetGeneric()->User=stCTI_PARAM->m_PhoneExtension1;
			CGenericApp::GetGeneric()->Password="METS2008PORTUGAL";
			CGenericApp::GetGeneric()->Station=stCTI_PARAM->m_PhoneExtension2;

			CGenericApp::GetGeneric()->m_TSUser = (LPCTSTR)stCTI_PARAM->m_SrcUserID;


			CGenericApp::GetGeneric()->mytime = new MyFakeTimer;
			hInst = CGenericApp::GetGeneric()->m_hInstance; 
			CGenericApp::GetGeneric()->mytime->Create(IDD_DIALOG2,AfxGetMainWnd());
			cWnd = CGenericApp::GetGeneric()->mytime;
    		hWnd = CGenericApp::GetGeneric()->mytime->GetSafeHwnd();
			CGenericApp::GetGeneric()->TrayIcon.Create(hInst,
						 hWnd,
                         WM_ICON_NOTIFY,                  // Icon notify message to use
                         _T("Generic DLL for Telescript 55a METS S.A."),  // tooltip
                         ::LoadIcon(hInst, (LPCTSTR)IDI_ICON1),IDR_MENU1);

			CGenericApp::GetGeneric()->m_pSIPPhone = EICClientCOMLib::ISIPPhonePtr(__uuidof(EICClientCOMLib::SIPPhone));
			CGenericApp::GetGeneric()->m_pEICServer = EICClientCOMLib::IEICServer2Ptr(__uuidof(EICClientCOMLib::EICServer2));

			CGenericApp::GetGeneric()->m_pSIPPhone->Activate();
			CGenericApp::GetGeneric()->m_pEICServer->FullConnect(L"TSRWMAIN.EXE","cic01",
							CGenericApp::GetGeneric()->User.AllocSysString(),CGenericApp::GetGeneric()->Password.AllocSysString(),CGenericApp::GetGeneric()->Station.AllocSysString(),false,MT_CALL);
			if(CGenericApp::GetGeneric()->m_pEICServer->GetConnectionValid())
			{
				CGenericApp::GetGeneric()->m_pEICQueue = EICClientCOMLib::IEICQueuePtr(__uuidof(EICClientCOMLib::EICQueue));
	    		CGenericApp::GetGeneric()->m_pEICQueue->Connect(9,CGenericApp::GetGeneric()->User.AllocSysString());	
				CGenericApp::GetGeneric()->m_QueueWatcher = new CQueueWatcher();
				CGenericApp::GetGeneric()->m_pEICQueue->SetChangeHandler(CGenericApp::GetGeneric()->m_QueueWatcher);
				_stprintf_s(log, _T("INICIO EXITOSO:\nUsuario:%s\nEstacion:%s"),CGenericApp::GetGeneric()->User,CGenericApp::GetGeneric()->Station);
				CGenericApp::GetGeneric()->LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_INITIALIZE,log);
			}
			else
			{
				_stprintf_s(log, _T("INICIO CON ERROR:\nUsuario:%s\nEstacion:%s"),CGenericApp::GetGeneric()->User,CGenericApp::GetGeneric()->Station);
				CGenericApp::GetGeneric()->LOG->SendEventLog(EVENTLOG_ERROR_TYPE,LOG_MSG_DLLERROR,LOG_INITIALIZE,log);
				stCTI_PARAM->m_Result = TELEPHONY_ERROR_DLLNOTLOADEDPROPERLY;
				return(TRUE);
			}
		}
		break;

	case TELEPHONY_COMMAND_FINALIZE:
		{
			CGenericApp::GetGeneric()->mytime->DestroyWindow();
			CGenericApp::GetGeneric()->m_pEICServer->Disconnect(FALSE);
			CGenericApp::GetGeneric()->m_pSIPPhone->Deactivate();
			
			_stprintf_s(log, _T("FINALIZACION EXITOSA:\nUsuario:%s\nEstacion:%s"),CGenericApp::GetGeneric()->User,CGenericApp::GetGeneric()->Station);
			CGenericApp::GetGeneric()->LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_FINALIZE,log);
		}
		break;

	case TELEPHONY_COMMAND_HOLD:
		{
			CGenericApp::GetGeneric()->Hold();
		}
		break;

	case TELEPHONY_COMMAND_TRANSFERINIT:
		{

		}
		break;

	case TELEPHONY_COMMAND_TRANSFERCOMPLETE:
		{

		}
		break;

	case TELEPHONY_COMMAND_CONFERENCEINIT:
		{

		}
		break;

	case TELEPHONY_COMMAND_CONFERENCECOMPLETE:
		{

		}
		break;

	case TELEPHONY_COMMAND_TRANSFERCANCEL:
		{

		}
		break;

	case TELEPHONY_COMMAND_UNHOLD:
		{
			CGenericApp::GetGeneric()->UnHold();
		}
		break;

	case TELEPHONY_COMMAND_CONFERENCECANCEL:
		{

		}
		break;

	case TELEPHONY_COMMAND_CONFERENCEBREAK:
		{

		}
		break;

	case TELEPHONY_COMMAND_3WAY:
		{

		}
		break;

	case TELEPHONY_COMMAND_CANCEL3WAY:
		{

		}
		break;

	case TELEPHONY_COMMAND_BLINDTRANSFER:
		{
			TCHAR tempNumber[255];
			CString tempNumberC;

			_stprintf_s(tempNumber, _T("%s"), (LPCTSTR)stCTI_PARAM->m_PhoneNumber);
			tempNumberC = tempNumber;
			CGenericApp::GetGeneric()->BlindTransfer(tempNumberC);
		}
		break;

	case TELEPHONY_COMMAND_ANSWERPHONE:
		{

		};
 		break;

	case TELEPHONY_COMMAND_GETVERSIONANDCOMMANDSSUPPORTED:
		{

		}
 		break;

	case TELESCRIPT_COMMAND_OPENTELEPHONYPANEL:
		{

		}
 		break;
 
	}

	stCTI_PARAM->m_Result = TELEPHONY_ERROR_OK;
	return(TRUE);
}

char* CGenericApp::ConvertBSTRToString(BSTR pSrc)
{
    if(!pSrc) return NULL;

    //convert even embeded NULL
    DWORD cb,cwch = ::SysStringLen(pSrc);

    char *szOut = NULL;

    if(cb = ::WideCharToMultiByte(CP_ACP, 0, 
               pSrc, cwch + 1, NULL, 0, 0, 0))
    {
        szOut = new char[cb];
        if(szOut)
        {
            szOut[cb - 1]  = '\0';

            if(!::WideCharToMultiByte(CP_ACP, 0, 
                pSrc, cwch + 1, szOut, cb, 0, 0))
            {
                delete []szOut;//clean up if failed;
                szOut = NULL;
            }
        }
    }

    return szOut;
};
