// Generic.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "cti.h"
#include "Generic.h"



BEGIN_MESSAGE_MAP(CGenericApp, CWinApp)
	//{{AFX_MSG_MAP(CGenericApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

LRESULT CALLBACK	TaskBar(HWND, UINT, WPARAM, LPARAM);

/////////////////////////////////////////////////////////////////////////////
// CGenericApp construction

LRESULT CALLBACK TaskBar(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;

	}
    return FALSE;
}

CGenericApp::CGenericApp()
{
	try
	{
		stCTI_DUMMY = new CTaskBar(AfxGetMainWnd());
		DUMMYWINDOW = 0;
		stCTI_TELEPHONY = new CTelephony();

		stCTI_PARAM = NULL;
	}
	catch(_com_error ex)
	{
		TCHAR error[255];
		_stprintf(error,_T("Finalize %s"),(LPCTSTR)ex.ErrorMessage());
		AfxMessageBox(error);
	}
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CGenericApp object


static CGenericApp theApp;

CGenericApp * CGenericApp::GetGeneric(){
	return & theApp;
}

BOOL CallCti(struct CTI_PARAM *stCTI_PARAM)
{
	CoInitialize(NULL);
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (CGenericApp::GetGeneric()->stCTI_PARAM!=NULL)
	{
		delete CGenericApp::GetGeneric()->stCTI_PARAM;
		CGenericApp::GetGeneric()->stCTI_PARAM=NULL;
	}
	CGenericApp::GetGeneric()->stCTI_PARAM = stCTI_PARAM;

	_bstr_t server				= CGenericApp::GetGeneric()->stCTI_PARAM->m_ServerName;
	_bstr_t user				= CGenericApp::GetGeneric()->stCTI_PARAM->m_AgentPhoneSystemLogin;
	_bstr_t password			= CGenericApp::GetGeneric()->stCTI_PARAM->m_AgentPhoneSystemPassword;
	_bstr_t extension			= CGenericApp::GetGeneric()->stCTI_PARAM->m_PhoneExtension1;
	_bstr_t station				= CGenericApp::GetGeneric()->stCTI_PARAM->m_PhoneExtension2;
	_bstr_t project				= CGenericApp::GetGeneric()->stCTI_PARAM->m_ProjectName;
	_bstr_t number				= CGenericApp::GetGeneric()->stCTI_PARAM->m_PhoneNumber;
	int     outbound_telelink	= CGenericApp::GetGeneric()->stCTI_PARAM->m_OutBoundXTelelink;


	switch(CGenericApp::GetGeneric()->stCTI_PARAM->m_Action)
	{
	case TELESCRIPT_COMMAND_OPENTELEPHONYPROJECT:

		break;

	case TELESCRIPT_COMMAND_CLOSETELEPHONYPROJECT:

		break;

	case TELEPHONY_COMMAND_HANGUP:
		
		break;

	case TELEPHONY_COMMAND_DIAL:
		try
		{
			CGenericApp::GetGeneric()->stCTI_TELEPHONY->Dial(number);
		}
		catch(_com_error ex)
		{
			TCHAR error[255];
			_stprintf(error,_T("Dialing %s"),(LPCTSTR)ex.ErrorMessage());
			AfxMessageBox(error);
			stCTI_PARAM->m_Result = TELEPHONY_ERROR_NODIALTONE;
			return(FALSE);
		}
		break;
		
	case TELEPHONY_COMMAND_GETINBOUND:

		int nResponse;
		nResponse=CGenericApp::GetGeneric()->m_wait.DoModal();

		if (nResponse==IDOK)
		{

		}
		else
		{
			stCTI_PARAM->m_Result = TELEPHONY_ERROR_CANCELGETINBOUND;
			return(FALSE);
		}

		break;

	case TELEPHONY_COMMAND_INITIALIZE:
		{
			try
			{
				if(!CGenericApp::GetGeneric()->stCTI_TELEPHONY->InitializePhone(user,password,station,server))
				{
					stCTI_PARAM->m_Result = TELEPHONY_ERROR_NOTINITIALIZED;
					AfxMessageBox("Usuario o Password erroneo");
					return(FALSE);
				}

				if (CGenericApp::GetGeneric()->DUMMYWINDOW==0)
				{
					
					CGenericApp::GetGeneric()->stCTI_DUMMY->Create();
					CGenericApp::GetGeneric()->DUMMYWINDOW = 1;
					CGenericApp::GetGeneric()->stCTI_DUMMY->ShowWindow(SW_HIDE);
					CGenericApp::GetGeneric()->stCTI_DUMMY->CreateTray();
				}
			}
			catch(_com_error ex)
			{
				TCHAR error[255];
				_stprintf(error,_T("Initialize %s"),(LPCTSTR)ex.ErrorMessage());
				AfxMessageBox(error);
				stCTI_PARAM->m_Result = TELEPHONY_ERROR_DLLNOTLOADEDPROPERLY;
				return(FALSE);
			}
			break;
		}

	case TELEPHONY_COMMAND_FINALIZE:
		{
			try
			{
				CGenericApp::GetGeneric()->stCTI_TELEPHONY->Shutdown(user,station);
				CGenericApp::GetGeneric()->stCTI_DUMMY->DestroyTray();
				CGenericApp::GetGeneric()->stCTI_DUMMY->DestroyWindow();

				delete CGenericApp::GetGeneric()->stCTI_DUMMY;
				delete CGenericApp::GetGeneric()->stCTI_TELEPHONY;

			}
			catch(_com_error ex)
			{
				TCHAR error[255];
				_stprintf(error,_T("Finalize %s"),(LPCTSTR)ex.ErrorMessage());
				AfxMessageBox(error);
			}
			break;
		}

	case TELEPHONY_COMMAND_HOLD:

		break;

	case TELEPHONY_COMMAND_TRANSFERINIT:

		break;

	case TELEPHONY_COMMAND_TRANSFERCOMPLETE:

		break;

	case TELEPHONY_COMMAND_CONFERENCEINIT:

		break;

	case TELEPHONY_COMMAND_CONFERENCECOMPLETE:

		break;

	case TELEPHONY_COMMAND_TRANSFERCANCEL:

		break;

	case TELEPHONY_COMMAND_UNHOLD:

		break;

	case TELEPHONY_COMMAND_CONFERENCECANCEL:

		break;

	case TELEPHONY_COMMAND_CONFERENCEBREAK:

		break;

	case TELEPHONY_COMMAND_3WAY:

		break;

	case TELEPHONY_COMMAND_CANCEL3WAY:

		break;

	case TELEPHONY_COMMAND_BLINDTRANSFER:

		break;

	case TELEPHONY_COMMAND_ANSWERPHONE:

		break;

	case TELEPHONY_COMMAND_GETVERSIONANDCOMMANDSSUPPORTED:

		break;

	case TELESCRIPT_COMMAND_OPENTELEPHONYPANEL:

		break;
 
	}

	stCTI_PARAM->m_Result = TELEPHONY_ERROR_OK;
	return(TRUE);
}

BOOL GetLastTelephonyError(char *strError)
{
	strcpy(strError,"Missing main driver!");
	return(TRUE);
}

void CGenericApp::PrintMessage(_com_error ex, _bstr_t classname, _bstr_t procname, int level)
{
	TCHAR error[255];
	_stprintf(error,_T("Error en clase: %s, procedimiento: %s \nDetalle: %s"),classname,procname,(LPCTSTR)ex.ErrorMessage());
	AfxMessageBox(error);
}