// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__D9A99375_2E52_4B22_AAF5_E7CBC94CD16A__INCLUDED_)
#define AFX_STDAFX_H__D9A99375_2E52_4B22_AAF5_E7CBC94CD16A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define _WIN32_WINNT 0x0501
#define _CRT_SECURE_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE classes
#include <afxodlgs.h>       // MFC OLE dialog classes
#include <afxdisp.h>        // MFC Automation classes
#endif // _AFX_NO_OLE_SUPPORT


#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>			// MFC ODBC database classes
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>			// MFC DAO database classes
#endif // _AFX_NO_DAO_SUPPORT

#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <windows.h>
#include <tchar.h>//
#include <Tlhelp32.h>
#include <atlbase.h>
#include <atlcom.h>
#include <afxdisp.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <afxdhtml.h>
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
#import "C:\Program Files\Interactive Intelligence\ClientCOMA.dll" named_guids exclude("IErrorInfo")
using namespace EICClientCOMLib;


#endif // !defined(AFX_STDAFX_H__D9A99375_2E52_4B22_AAF5_E7CBC94CD16A__INCLUDED_)
