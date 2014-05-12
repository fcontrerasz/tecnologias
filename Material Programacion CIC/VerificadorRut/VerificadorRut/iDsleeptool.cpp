
#include "stdafx.h"	// specific to MS VC++

#include "i3idtool.h"	// enums and typedefs for the API

#include "i3idtoolreg.h"	// prototypes for API functions

#include "idinternalregdll.h"	// specifies the linkage to I3IDTOOLREG dll
								// not part of the public API
								// if you're using MS VC++, you can use 
								// something like this:
//			#ifdef UNICODE
//				#ifdef _DEBUG
//					#pragma comment(lib,"I3IDTOOLREGUD")
//				#else
//					#pragma comment(lib,"I3IDTOOLREGU")
//				#endif
//			#else
//				#ifdef _DEBUG
//					#pragma comment(lib,"I3IDTOOLREGAD")
//				#else
//					#pragma comment(lib,"I3IDTOOLREGA")
//				#endif
//			#endif



//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// See InitializeTools and InitializeTypes at bottom for starting point.



//----------------------------------------------------------------------------
BOOL RegisterToolSleep() 
{
	TCHAR strMsg[100];	// a message buffer for anything that might happen 
						// during this registration

	I3IDToolHandle_t toolHdl;	// the handle for the tool we'll be creating

	// Creates a tool called Sleep.
	// We'll use toolHdl to add an input to Sleep later
	IdToolRetCode_t nRC = I3IDRegisterTool(&toolHdl,
								L"Sleep",	// internal name for the tool
											// don't internationalize this one
								L"IDSleepTool.DLL",	// module that 
											// registered the tool
								L"Sleep",	// label for the tool
											// internationalize this one,
											// it's what the user sees
								L"Pauses execution of this handler's thread.",
											// description
								L"Basic",	// the Category this tool goes under
											// corresponds to the tab on the 
											// Tool Palette
								NULL,	// 32 x 32 icon
										// NULL means default
								NULL,	// 16 x 16 icon
										// NULL means default
								L"IPSLEEPTOOLU",
										// the IP run-time callback DLL
								L"ExecuteSleep",
										// the IP run-time callback function
								1);	// how many parameters (inputs & outputs)
									// this tool will have at run-time.

	if (nRC != eIdToolRetCode_SUCCESS) {
		wsprintf(strMsg,_T("RegisterTool returns %d\n"),nRC);
		::MessageBox(NULL, strMsg, _T("Sleep Tool Registration"), MB_OK);
		return(FALSE);
	}


	// The Sleep tool never really fails (at least in this example),
	// so we only need one exitpath from a Sleep step.
	nRC = I3IDAddToolExitPath(toolHdl,	// got this from Register above
					  L"Next",	// label for the exitpath
					  1,		// the return code from our 
					  			// run-time callback function 
								// ExecuteSleep
					  FALSE);	// FALSE => this exitpath is not an 
								// "error" condition

	if (nRC != eIdToolRetCode_SUCCESS) {
		wsprintf(strMsg,_T("Add Exit Path returns %d\n"),nRC);
		::MessageBox(NULL, strMsg, _T("Sleep Tool Registration"), MB_OK);
		return(FALSE);
	}


	// find out what the name for the integer type is in ID.
	// we'll use this to add an input to our tool
	int len = I3IDMaxLenNativeTypeNames();
	// the length returned doesn't include a NULL terminator, so add 1
	wchar_t * pwBuffer = (wchar_t *)calloc( len + 1, sizeof(wchar_t));

	int nFilled(I3IDQueryNativeTypeName(eIdNativeTypeNameID_INTEGER,
									   pwBuffer, len));

	if (nFilled <= 0) {
		wsprintf(strMsg,_T("Query Native TypeName INTEGER returns %d\n"),nFilled);
		::MessageBox(NULL, strMsg, _T("Sleep Tool Registration"), MB_OK);
		free(pwBuffer);
		return(FALSE);
	}

	// now we know the name of integer so we can add an input to our Sleep
	// tool
	// We want the user to choose the number of seconds that Sleep 
	// should occur.  This input can either be an integer variable or 
	// an integer expression.
	nRC = I3IDAddToolInputCombobox(toolHdl,
									0,	// index of this parameter in the 
										// array of parameters given 
										// to our run-time callback 
										// function.
    								L"Sleep Time (milliseconds)",
										// GUI label for the properties
										// sheet of a Sleep step.
									TRUE,	// This value is 
											// required from the 
											// user
									pwBuffer,	// name for the 
											// integer type
									NULL);	// internal type
											// if we were using an 
											// external type here,
											// we'd enter the 
											// module that registered 
											// the type

	free(pwBuffer);	// clean up the buffer we calloc'd

	if (nRC != eIdToolRetCode_SUCCESS) {
		wsprintf(strMsg,_T("Add Input Sleep Time returns %d\n"),nRC);
		::MessageBox(NULL, strMsg, _T("Sleep Tool Registration"), MB_OK);
		return(FALSE);
	}

	// The Sleep tool is finished, so let's commit it
	nRC = I3IDCommitTool(toolHdl);

	if (nRC != eIdToolRetCode_SUCCESS) {
		wsprintf(strMsg,_T("Commit returns %d\n"),nRC);
		::MessageBox(NULL, strMsg, _T("Sleep Tool Registration"), MB_OK);
		return(FALSE);
	}


	return(TRUE);
}



extern "C" {

//----------------------------------------------------------------------------
void __declspec(dllexport) InitializeTools()
{
	// this is to keep this dll's MS VC++ run-time state from 
	// screwing up ID's MS run-time state.
	// If you use MS VC++, do this (read about it in 
	// the doc first).
	// If you don't use MS VC++, you don't have to 
	// worry about it.
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	RegisterToolSleep();

}


//----------------------------------------------------------------------------
void __declspec(dllexport) InitializeTypes()
{
	// this is to keep this dll's MS VC++ run-time state from 
	// screwing up ID's MS run-time state.
	// If you use MS VC++, do this (read about it in 
	// the doc first).
	// If you don't use MS VC++, you don't have to 
	// worry about it.
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// no types to register

	return;
}



}	// extern C