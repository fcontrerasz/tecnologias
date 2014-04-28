#if !defined(AFX_QUEUEWATCHER_H__7FFC4B60_8271_11D3_A4B9_0090277455F6__INCLUDED_)
#define AFX_QUEUEWATCHER_H__7FFC4B60_8271_11D3_A4B9_0090277455F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CQueueWatcher : public EICClientCOMLib::IEICQueue2Watcher  
{
public:
	CQueueWatcher();
	virtual ~CQueueWatcher();

	// IUnknown
	STDMETHODIMP QueryInterface(REFIID riid, void **ppv);
	STDMETHODIMP_(ULONG) AddRef(void);
	STDMETHODIMP_(ULONG) Release(void);

	// IDispatch
	STDMETHODIMP GetTypeInfoCount(UINT *pcti);
    STDMETHODIMP GetTypeInfo(UINT cti, LCID, ITypeInfo **ppti);
    STDMETHODIMP GetIDsOfNames(REFIID riid, OLECHAR **prgpsz, UINT cNames, LCID lcid, DISPID *prgids);
    STDMETHODIMP Invoke(DISPID id, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *params, VARIANT *pVarResult, EXCEPINFO *pei, UINT *puArgErr);

    virtual HRESULT __stdcall raw_ObjectAdded (struct EICClientCOMLib::IEICQueue2 * p_Queue, struct EICClientCOMLib::IEICQueueObject2 * p_Object);
    virtual HRESULT __stdcall raw_ObjectChanged (struct EICClientCOMLib::IEICQueue2 * p_Queue, struct EICClientCOMLib::IEICQueueObject2 * p_Object);
    virtual HRESULT __stdcall raw_ObjectRemoved (struct EICClientCOMLib::IEICQueue2 * p_Queue, long p_Id);
    virtual HRESULT __stdcall raw_StatisticsUpdated (struct EICClientCOMLib::IEICQueue2 * p_Queue);

private:
	LONG m_Ref;
	LONG m_inCall;
	LONG m_ActualId;
};

#endif // !defined(AFX_QUEUEWATCHER_H__7FFC4B60_8271_11D3_A4B9_0090277455F6__INCLUDED_)
