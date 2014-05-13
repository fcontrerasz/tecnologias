// This is the main DLL file.

#include "stdafx.h"

#include "Generic.NET.h"

#pragma unmanaged

//Place all unmanaged code between these blocks

// CGenericNETApp
// See Generic.NET.cpp for the implementation of this class
//

class CGenericNETApp : public CWinApp
{
public:
	CGenericNETApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CGenericNETApp

BEGIN_MESSAGE_MAP(CGenericNETApp, CWinApp)
END_MESSAGE_MAP()

// CGenericNETApp construction

CGenericNETApp::CGenericNETApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CGenericNETApp object

CGenericNETApp theApp;

// CGenericNETApp initialization

BOOL CGenericNETApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

#pragma managed

