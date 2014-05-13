#include "stdafx.h"
#include "Generic.h"
#include "CallObjectWatcher.h"

CCallObjectWatcher::CCallObjectWatcher()
{
	ActualState = -1;
}


CCallObjectWatcher::~CCallObjectWatcher()
{
	Release();
}


HRESULT CCallObjectWatcher::raw_StateChanged(struct EICClientCOMLib::IEICQueueObject2 *p_object,long p_NewState,BSTR p_StateString)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if ((p_object->State == CONNECTED || p_object->State == CONNECTED2) && ActualState != CONNECTED)
	{
		ActualState = CONNECTED;
	}
	else if (p_object->State == DIALING && ActualState != DIALING)
	{
		ActualState = DIALING;
	}
	return S_OK;
}


HRESULT CCallObjectWatcher::raw_ObjectDestroyed(struct EICClientCOMLib::IEICQueueObject2 *p_object)
{
	return S_OK;
}

HRESULT CCallObjectWatcher::raw_ObjectSpecificError(struct EICClientCOMLib::IEICQueueObject2 *p_object,long p_Error)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	AfxMessageBox(p_Error);
	return S_OK;
}

HRESULT CCallObjectWatcher::raw_SubObjectChanged(struct EICClientCOMLib::IEICQueueObject2 *p_object,struct EICClientCOMLib::IEICQueueObject2 *p_object2)
{
	return S_OK;
}


STDMETHODIMP CCallObjectWatcher::QueryInterface(REFIID riid, void **ppv)
{
	if ( ppv == NULL )
	{
		return E_POINTER;
	}
	if ( riid == __uuidof(IEICQueueObject2Watcher ) )
	{
		*ppv = static_cast<IEICQueueObject2Watcher *>(this);
	}
	else if ( riid == IID_IUnknown )
	{
		*ppv = static_cast<IEICQueueObject2Watcher *>(this);
	}
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}
	((LPUNKNOWN)*ppv)->AddRef();
	return S_OK;
}

STDMETHODIMP_(ULONG) CCallObjectWatcher::AddRef(void)
{
	return InterlockedIncrement(&m_Ref);
}

STDMETHODIMP_(ULONG) CCallObjectWatcher::Release(void)
{
	LONG res = InterlockedDecrement(&m_Ref);
	if ( res == 0 )
	{
		delete this;
	}
	return res;
}

STDMETHODIMP CCallObjectWatcher::GetTypeInfoCount(UINT *pcti)
{
	return E_NOTIMPL;
}

STDMETHODIMP CCallObjectWatcher::GetTypeInfo(UINT cti, LCID, ITypeInfo **ppti)
{
	return E_NOTIMPL;
}

STDMETHODIMP CCallObjectWatcher::GetIDsOfNames(REFIID riid, OLECHAR **prgpsz, UINT cNames, LCID lcid, DISPID *prgids)
{
	return E_NOTIMPL;
}

STDMETHODIMP CCallObjectWatcher::Invoke(DISPID id, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *params, VARIANT *pVarResult, EXCEPINFO *pei, UINT *puArgErr)
{
	return E_NOTIMPL;
}

