#include "stdafx.h"
#include "Generic.h"

CQueueWatcher::CQueueWatcher()
{
	m_inCall = 0;
	m_ActualId = 0;
	m_Ref = 0;
}
/*
STATES:
1 QS2_ALERTING
105 QS2_CONNECTED
103 QS2_DIALING
106 QS2_DISCONNECTED
4 QS2_HELD
100 QS2_INITIALIZING
77 QS2_MESSAGING
0 QS2_NULL
101 QS2_OFFERING
80 QS2_PARKED
104 QS2_PROCEEDING
107 QS2_STATIONAUDIO
*/

CQueueWatcher::~CQueueWatcher()
{
	Release();
}

HRESULT __stdcall CQueueWatcher::raw_ObjectAdded (long p_Type, long p_Id)
{
	TCHAR log[255];
	IEICCallObjectPtr p_Object;
	p_Object = EICClientCOMLib::IEICCallObjectPtr(__uuidof(EICClientCOMLib::EICCallObject));
	p_Object->Id = p_Id;

	_stprintf_s(log, _T("NUEVO CALLID:%d\nNUMERO:%s\nESTADO:%s (%d)"),p_Id,(LPCTSTR)p_Object->RemoteId,(LPCTSTR)p_Object->StateString,p_Object->State);
	CGenericApp::GetGeneric()->LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_DIAL,log);

	return S_OK;
}

HRESULT __stdcall CQueueWatcher::raw_ObjectChanged (long p_Type, long p_Id)
{
	TCHAR log[255];
	TCHAR isdn_t[255];
	BSTR isdn_b;
	CString isdn;
	IEICCallObjectPtr p_Object;
	p_Object = EICClientCOMLib::IEICCallObjectPtr(__uuidof(EICClientCOMLib::EICCallObject));
	p_Object->Id = p_Id;

	switch(p_Object->State)
	{
		case 100:
			{
				CGenericApp::GetGeneric()->CALLID = p_Id;
				CGenericApp::GetGeneric()->AddAttToCurrentCall(L"IC_METS_ProjectName",CGenericApp::GetGeneric()->m_ProjectName);
				CGenericApp::GetGeneric()->AddAttToCurrentCall(L"IC_METS_User",CGenericApp::GetGeneric()->m_TSUser);
				_stprintf_s(log, _T("CAMBIO ESTADO CALLID:%d\nNUMERO:%s\nESTADO:%s (%d)"),p_Id,(LPCTSTR)p_Object->RemoteId, (LPCTSTR)p_Object->StateString, p_Object->State);
				CGenericApp::GetGeneric()->LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_DIAL,log);
				break;
			}
		case 103:
			{
				CGenericApp::GetGeneric()->CALLID = p_Id;
				CGenericApp::GetGeneric()->stCTI_PARAM->m_DialConnectionResult = DCR_CONNECTED_NONE;
				CGenericApp::GetGeneric()->AddAttToCurrentCall(L"IC_METS_ProjectName",CGenericApp::GetGeneric()->m_ProjectName);
				CGenericApp::GetGeneric()->AddAttToCurrentCall(L"IC_METS_User",CGenericApp::GetGeneric()->m_TSUser);
				_stprintf_s(log, _T("CAMBIO ESTADO CALLID:%d\nNUMERO:%s\nESTADO:%s (%d)"),p_Id,(LPCTSTR)p_Object->RemoteId, (LPCTSTR)p_Object->StateString, p_Object->State);
				CGenericApp::GetGeneric()->LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_DIAL,log);
				CGenericApp::GetGeneric()->TrayIcon.ShowBalloon("Discando ...","Telescript-CIC",NIIF_INFO,1);
				CGenericApp::GetGeneric()->mytime->StartTimer(1500,HIDE_BALLOON);
				break;
			}
		case 105:
			{
				CGenericApp::GetGeneric()->stCTI_PARAM->m_DialConnectionResult = DCR_CONNECTED_PROPERLY;
				_stprintf_s(log, _T("CAMBIO ESTADO CALLID:%d\nNUMERO:%s\nESTADO:%s (%d)"),p_Id,(LPCTSTR)p_Object->RemoteId, (LPCTSTR)p_Object->StateString, p_Object->State);
				CGenericApp::GetGeneric()->LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_DIAL,log);
				break;
			}
		case 106:
			{

				 p_Object->GetNamedAttribute("Eic_IsdnCauseValue",&isdn_b);
				 _stprintf_s(isdn_t, _T("%s"), (LPCTSTR)CGenericApp::GetGeneric()->ConvertBSTRToString(isdn_b));
				isdn = isdn_t;

				CGenericApp::GetGeneric()->CALLID = 0;
				_stprintf_s(log, _T("CAMBIO ESTADO CALLID:%d\nNUMERO:%s\nESTADO:%s (%d)\nISDN:%s"),p_Id,(LPCTSTR)p_Object->RemoteId, (LPCTSTR)p_Object->StateString, p_Object->State, isdn_t);
				CGenericApp::GetGeneric()->LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_DIAL,log);

				if (isdn.CompareNoCase("17")==0)
				{
					CGenericApp::GetGeneric()->stCTI_PARAM->m_DialConnectionResult = DCR_LINE_BUSY;
					CGenericApp::GetGeneric()->TrayIcon.ShowBalloon("Telefono Ocupado","Telescript-CIC",NIIF_INFO,1);
					CGenericApp::GetGeneric()->mytime->StartTimer(2000,HIDE_BALLOON);
				}
				else if (isdn.CompareNoCase("1")==0 ||
					isdn.CompareNoCase("19")==0 ||
					isdn.CompareNoCase("21")==0 ||

					isdn.CompareNoCase("22")==0 ||
					isdn.CompareNoCase("27")==0 ||
					isdn.CompareNoCase("34")==0 ||
					isdn.CompareNoCase("41")==0 ||
					isdn.CompareNoCase("42")==0 ||
					isdn.CompareNoCase("44")==0)
				{
					CGenericApp::GetGeneric()->stCTI_PARAM->m_DialConnectionResult = DCR_LINE_SIT_TONE;
					CGenericApp::GetGeneric()->TrayIcon.ShowBalloon("Teléfono temporalmente fuera de servicio\n o no existe número","Telescript-CIC",NIIF_INFO,1);
					CGenericApp::GetGeneric()->mytime->StartTimer(2000,HIDE_BALLOON);
				}
				break;
			}
		default:
			{
				_stprintf_s(log, _T("CAMBIO ESTADO CALLID:%d\nNUMERO:%s\nESTADO:%s (%d)"),p_Id,(LPCTSTR)p_Object->RemoteId, (LPCTSTR)p_Object->StateString, p_Object->State);
				CGenericApp::GetGeneric()->LOG->SendEventLog(EVENTLOG_INFORMATION_TYPE,LOG_MSG_DLLINFO,LOG_DIAL,log);
				break;
			}
	}
	
	return S_OK;
}

HRESULT __stdcall CQueueWatcher::raw_ObjectRemoved (long p_Type, long p_Id)
{
	return S_OK;
}


STDMETHODIMP CQueueWatcher::QueryInterface(REFIID riid, void **ppv)
{
	if ( ppv == NULL )
	{
		return E_POINTER;
	}
	if ( riid == __uuidof(IEICQueueWatcher) )
	{
		*ppv = static_cast<IEICQueueWatcher *>(this);
	}
	else if ( riid == IID_IUnknown )
	{
		*ppv = static_cast<IEICQueueWatcher *>(this);
	}
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}
	((LPUNKNOWN)*ppv)->AddRef();
	return S_OK;
}

STDMETHODIMP_(ULONG) CQueueWatcher::AddRef(void)
{
	return InterlockedIncrement(&m_Ref);
}

STDMETHODIMP_(ULONG) CQueueWatcher::Release(void)
{
	LONG res = InterlockedDecrement(&m_Ref);
	if ( res == 0 )
	{
		delete this;
	}
	return res;
}

STDMETHODIMP CQueueWatcher::GetTypeInfoCount(UINT *pcti)
{
	return E_NOTIMPL;
}

STDMETHODIMP CQueueWatcher::GetTypeInfo(UINT cti, LCID, ITypeInfo **ppti)
{
	return E_NOTIMPL;
}

STDMETHODIMP CQueueWatcher::GetIDsOfNames(REFIID riid, OLECHAR **prgpsz, UINT cNames, LCID lcid, DISPID *prgids)
{
	return E_NOTIMPL;
}

STDMETHODIMP CQueueWatcher::Invoke(DISPID id, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *params, VARIANT *pVarResult, EXCEPINFO *pei, UINT *puArgErr)
{
	return E_NOTIMPL;
}
