#include "stdafx.h"
#include "Generic.h"
#include "QueueWatcher.h"

CQueueWatcher::CQueueWatcher()
{
	m_inCall = 0;
	m_ActualId = 0;
	m_Ref = 0;
}

CQueueWatcher::~CQueueWatcher()
{
	Release();
}

HRESULT __stdcall CQueueWatcher::raw_ObjectAdded (struct IEICQueue2 * p_Queue, struct IEICQueueObject2 * p_Object)
{	
	return S_OK;
}

HRESULT __stdcall CQueueWatcher::raw_ObjectChanged (struct IEICQueue2 * p_Queue, struct IEICQueueObject2 * p_Object)
{
	return S_OK;
}

HRESULT __stdcall CQueueWatcher::raw_ObjectRemoved (struct IEICQueue2 * p_Queue, long p_Id )
{
	return S_OK;
}

HRESULT __stdcall CQueueWatcher::raw_StatisticsUpdated (struct IEICQueue2 * p_Queue)
{
	return S_OK;
}

STDMETHODIMP CQueueWatcher::QueryInterface(REFIID riid, void **ppv)
{
	if ( ppv == NULL )
	{
		return E_POINTER;
	}
	if ( riid == __uuidof(IEICQueue2Watcher) )
	{
		*ppv = static_cast<IEICQueue2Watcher*>(this);
		AddRef();
	}
	else if ( riid == IID_IUnknown )
	{
		*ppv = static_cast<IEICQueue2Watcher*>(this);
		AddRef();
	}
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}
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
