#include "stdafx.h"
#include "Generic.h"

CTelephony::CTelephony()
{
	try{
		IC_SipPhone		= EICClientCOMLib::ISIPPhonePtr(__uuidof(EICClientCOMLib::SIPPhone));
		IC_Server		= EICClientCOMLib::IEICServer3Ptr(__uuidof(EICClientCOMLib::EICServer3));
		IC_Queue		= EICClientCOMLib::IEICQueue2Ptr(__uuidof(EICClientCOMLib::EICQueue2));
		IC_User			= EICClientCOMLib::IEICUser3Ptr(__uuidof(EICClientCOMLib::EICUser3));


		IC_QueueWatcher = new CQueueWatcher();
		IC_CallWatcher  = new CCallObjectWatcher();
		

	}
	catch(_com_error ex)
	{	
		TCHAR error[255];
		_stprintf(error,_T("%s"),(LPCTSTR)ex.ErrorMessage());
		AfxMessageBox(error);
	}
}

CTelephony::~CTelephony()
{
}
bool CTelephony::InitializePhone(_bstr_t user, _bstr_t password, _bstr_t station, _bstr_t server)
{
		try{
			IC_SipPhone->Activate();
			IC_Server->FullConnect("IClient",server,user,password,station,false,MT_CALL);
			IC_Server->CSLogin(user,password,station,"Do Not Disturb",false,false,MT_CALL);
			if (IC_Server->GetConnectionValid())
			{
				IC_User->PutId(user);
				IC_Queue->Connect(9,user);
				IC_Queue->SetThreadCallback(IC_QueueWatcher);
			}
			else
			{
				return false;
			}
			return true;
		}
		catch(_com_error ex)
		{
			TCHAR error[255];
			_stprintf(error,_T("Initialize %s"),(LPCTSTR)ex.ErrorMessage());
			AfxMessageBox(error);
			return false;
		}
}

void CTelephony::Shutdown(_bstr_t user, _bstr_t station)
{
	try
	{
		IC_Server->CSLogout(user,station);
		IC_Server->Disconnect(true);
		IC_SipPhone->Deactivate();
	}
	catch(_com_error ex)
	{
		TCHAR error[255];
		_stprintf(error,_T("Finalize %s"),(LPCTSTR)ex.ErrorMessage());
		AfxMessageBox(error);
	}
}

void CTelephony::Dial(_bstr_t number)
{
	try
	{
		IC_Call = EICClientCOMLib::IEICCallObject2Ptr(__uuidof(EICClientCOMLib::EICCallObject2));
		IC_CallWatcher = new CCallObjectWatcher();

		IC_Call->SetThreadCallback(IC_CallWatcher);
		IC_Call->ExtendedDial(number,5,TRUE,TRUE);
	}
	catch(_com_error ex)
	{
		TCHAR error[255];
		_stprintf(error,_T("Dial %s"),(LPCTSTR)ex.ErrorMessage());
		AfxMessageBox(error);
	}
}

void CTelephony::Hangup()
{
	try
	{
		IC_Queue->StartObjectsList();

		IC_TempCall = IC_Queue->GetNextQueueObject();

		while (IC_TempCall!=NULL){
			if ((IC_TempCall->GetState()==QS_PROCEEDING)
				|| (IC_TempCall->GetState()==QS_ACTIVE)
				|| (IC_TempCall->GetState()==QS_ALERTING)
				|| (IC_TempCall->GetState()==QS_OFFERING)
				|| (IC_TempCall->GetState()==QS_CONNECTED)
				|| (IC_TempCall->GetState()==QS_SYSTEM)
				|| (IC_TempCall->GetState()==QS_HELD))
			{
				IC_TempCall->Disconnect(IC_Queue);
			}
			IC_TempCall = IC_Queue->GetNextQueueObject();
		}
	}
	catch(_com_error ex)
	{
		TCHAR error[255];
		_stprintf(error,_T("Hangup %s"),(LPCTSTR)ex.ErrorMessage());
		AfxMessageBox(error);
	}
}

void CTelephony::StartRecord()
{

}

void CTelephony::EndRecord()
{

}

void CTelephony::SetAttribute(_bstr_t name, _bstr_t value)
{

}

bool CTelephony::IsOnCall()
{
	try
	{
		IC_Queue->StartObjectsList();

		IC_TempCall = IC_Queue->GetNextQueueObject();

		while (IC_TempCall!=NULL){
			if ((IC_TempCall->GetState()==QS_PROCEEDING)
				|| (IC_TempCall->GetState()==QS_ACTIVE)
				|| (IC_TempCall->GetState()==QS_ALERTING)
				|| (IC_TempCall->GetState()==QS_OFFERING)
				|| (IC_TempCall->GetState()==QS_CONNECTED)
				|| (IC_TempCall->GetState()==QS_SYSTEM)
				|| (IC_TempCall->GetState()==QS_HELD))
			{
				return true;
			}
			IC_TempCall = IC_Queue->GetNextQueueObject();
		}
		return false;
	}
	catch(_com_error ex)
	{
		TCHAR error[255];
		_stprintf(error,_T("Is On Call %s"),(LPCTSTR)ex.ErrorMessage());
		AfxMessageBox(error);
		return false;
	}
}
