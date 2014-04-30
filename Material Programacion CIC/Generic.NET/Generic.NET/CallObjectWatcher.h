#if !defined(AFX_CALLOBJECTWATCHER_H__FCD73CA2_827E_11D3_A4B9_0090277455F6__INCLUDED_)
#define AFX_CALLOBJECTWATCHER_H__FCD73CA2_827E_11D3_A4B9_0090277455F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCallObjectWatcher : public EICClientCOMLib::IEICQueueObject2Watcher   
{
public:
	CCallObjectWatcher();
	virtual ~CCallObjectWatcher();

	// IUnknown
	STDMETHODIMP QueryInterface(REFIID riid, void **ppv);
	STDMETHODIMP_(ULONG) AddRef(void);
	STDMETHODIMP_(ULONG) Release(void);

	// IDispatch
	STDMETHODIMP GetTypeInfoCount(UINT *pcti);
	STDMETHODIMP GetTypeInfo(UINT cti, LCID, ITypeInfo **ppti);
	STDMETHODIMP GetIDsOfNames(REFIID riid, OLECHAR **prgpsz, UINT cNames, LCID lcid, DISPID *prgids);
	STDMETHODIMP Invoke(DISPID id, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *params, VARIANT *pVarResult, EXCEPINFO *pei, UINT *puArgErr);

	//IEICQueueObjectWatcher
	virtual HRESULT __stdcall raw_StateChanged(struct EICClientCOMLib::IEICQueueObject2 *p_object, long p_NewState, BSTR p_StateString);
	virtual HRESULT __stdcall raw_ObjectDestroyed(struct EICClientCOMLib::IEICQueueObject2 *p_object);
	virtual HRESULT __stdcall raw_ObjectSpecificError(struct EICClientCOMLib::IEICQueueObject2 *p_object,long p_Error);
	virtual HRESULT __stdcall raw_SubObjectChanged(struct EICClientCOMLib::IEICQueueObject2 *p_object,struct EICClientCOMLib::IEICQueueObject2 *p_object2);


private:

		LONG m_Ref;
		long ActualState;
};

#endif // !defined(AFX_CALLOBJECTWATCHER_H__FCD73CA2_827E_11D3_A4B9_0090277455F6__INCLUDED_)
