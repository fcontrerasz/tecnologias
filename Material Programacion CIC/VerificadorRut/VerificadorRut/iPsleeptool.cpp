#include "stdafx.h"
#include <winbase.h>

#include "javadll.h"	// defines structures for getting values from 
						// parameter array


// The functions that support tools registered by IDSleepTool


extern "C" {



//----------------------------------------------------------------------------
long __declspec(dllexport) ExecuteSleep(
	Parameter * p_paParms, 
	int p_nParms
)
{
	AFX_MANAGE_STATE (AfxGetStaticModuleState());

	// Parameter 0: Int input sleep time in seconds			IN

	ASSERT (p_nParms == 1);
	ASSERT(p_paParms[0].m_ParameterType == I3Integer);


	int nSleepTime;

	// if somehow the value wasn't specified, we'll default to 
	// 0	
 	if (p_paParms[0].m_EmptyParameter) {
		nSleepTime = 0;
	} else {
		nSleepTime = p_paParms[0].m_Integer * 1000;
	}

	::Sleep((DWORD)nSleepTime);

	// return the number we registered with the exitpath called Next	
	return (1);
}



}	// extern C