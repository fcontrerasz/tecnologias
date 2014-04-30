#ifndef __EIC_ID_API_MFC_HELPERS_H_
#define __EIC_ID_API_MFC_HELPERS_H_

#include "javadll.h"

void SetJavaOutputStringList (Parameter & p_param, const CStringList & p_lstrList)
{
	ASSERT (p_param.m_ParameterType == I3StringList);
	ASSERT (p_param.m_OutParameter);
	if (p_param.m_ParameterType != I3StringList || !p_param.m_OutParameter)
		return;

	for (int i = 0; i < p_param.m_ListCount; i++) {
		if (p_param.m_StringList[i] != NULL)
			::free (p_param.m_StringList[i]);
	}
	if (p_param.m_StringList != NULL)
		::free (p_param.m_StringList);

	p_param.m_ListCount = p_lstrList.GetCount ();
	p_param.m_StringList = (WCHAR **) ::malloc (sizeof (WCHAR *) * p_param.m_ListCount);
	POSITION pos = p_lstrList.GetHeadPosition ();
	for (i = 0; pos != NULL; i++) {
		CString strEntry (p_lstrList.GetNext (pos));
		int nBytes = (strEntry.GetLength () + 1) * sizeof (WCHAR) ;
		p_param.m_StringList[i] = (WCHAR *) ::malloc (nBytes);
		::memcpy (p_param.m_StringList[i], (const TCHAR *) strEntry, nBytes);
	}
}

void SetJavaOutputStringList (Parameter & p_param, const CStringArray & p_astrList)
{
	ASSERT (p_param.m_ParameterType == I3StringList);
	ASSERT (p_param.m_OutParameter);
	if (p_param.m_ParameterType != I3StringList || !p_param.m_OutParameter)
		return;

	for (int i = 0; i < p_param.m_ListCount; i++) {
		if (p_param.m_StringList[i] != NULL)
			::free (p_param.m_StringList[i]);
	}
	if (p_param.m_StringList != NULL)
		::free (p_param.m_StringList);

	p_param.m_ListCount = p_astrList.GetSize ();
	p_param.m_StringList = (WCHAR **) ::malloc (sizeof (WCHAR *) * p_param.m_ListCount);
	for (i = 0; i < p_param.m_ListCount; i++) {
		int nBytes = (p_astrList[i].GetLength () + 1) * sizeof (WCHAR) ;
		p_param.m_StringList[i] = (WCHAR *) ::malloc (nBytes);
		::memcpy (p_param.m_StringList[i], (const TCHAR *) p_astrList[i], nBytes);
	}
}


void SetJavaOutputIntegerList (Parameter & p_param, const CDWordArray & p_anList)
{
	ASSERT (p_param.m_ParameterType == I3IntegerList);
	ASSERT (p_param.m_OutParameter);
	if (p_param.m_ParameterType != I3IntegerList || !p_param.m_OutParameter)
		return;

	if (p_param.m_IntegerList != NULL)
		::free (p_param.m_IntegerList);

	p_param.m_ListCount = p_anList.GetSize ();
	p_param.m_IntegerList = (long *) ::malloc (sizeof (long) * p_param.m_ListCount);
	for (int i = 0; i < p_param.m_ListCount; i++)
		p_param.m_IntegerList[i] = p_anList[i];
}

void JavaInputStringList (Parameter & p_param, CStringList & p_lstrList)
{
	ASSERT (p_param.m_ParameterType == I3StringList);
	if (p_param.m_ParameterType != I3StringList)
		return;

	p_lstrList.RemoveAll ();
	if (p_param.m_EmptyParameter)
		return;
	for (int i = 0; i < p_param.m_ListCount; i++) {
		p_lstrList.AddTail (CString(p_param.m_StringList[i]));
	}
}

void JavaInputStringList (Parameter & p_param, CStringArray & p_astrList)
{
	ASSERT (p_param.m_ParameterType == I3StringList);
	if (p_param.m_ParameterType != I3StringList)
		return;

	p_astrList.SetSize (p_param.m_ListCount);
	if (p_param.m_EmptyParameter)
		return;
	for (int i = 0; i < p_param.m_ListCount; i++) {
		p_astrList[i] = p_param.m_StringList[i];
	}
}

#endif  // __EIC_ID_API_MFC_HELPERS_H_