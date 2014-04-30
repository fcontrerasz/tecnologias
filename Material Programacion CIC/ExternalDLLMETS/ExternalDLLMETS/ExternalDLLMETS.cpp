// ExternalDLLMETS.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "ExternalDLLMETS.h"
#include "Resource.h"
#include "PageDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


extern "C" int APIENTRY ClientCreateDlg(HWND** p_pawndDialogs,int* p_pnCount,LPCSTR p_pszUserId)
{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		HWND* pawndDialogs = new HWND [1];

		CPageDlg* dlg = new CPageDlg;

		dlg->Create(CPageDlg::IDD);

		pawndDialogs[0] = (HWND) dlg->m_hWnd;
		*p_pawndDialogs = pawndDialogs;
		*p_pnCount = 1;
		/*g_sDlg.Lock();
		g_vDlgs.push_back(dlg);

		g_sDlg.Unlock();*/
		return S_OK;
}

extern "C" int APIENTRY ClientDlgTitle(LPCTSTR** p_pastrTitles,int* p_pnCount)
{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		LPCTSTR* apszTitles = new LPCTSTR [1];

		apszTitles[0] = new TCHAR[80];
		_tcscpy((LPTSTR) apszTitles[0], (LPCTSTR) _T("My Test")); 
		*p_pastrTitles = apszTitles; 
		*p_pnCount = 1; 
		return S_OK; 
}

