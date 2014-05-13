#ifndef __JAVADLL_H__
#define __JAVADLL_H__

#include "tchar.h"

#if defined (BUILDING_JAVADLL_DLL)
	#define JAVADLL_DLL __declspec(dllexport)
	#if defined (DEBUG)
		#pragma comment(lib, "javai.lib")
	#else
		#pragma comment(lib, "javai.lib")
#endif		
#else
	#define JAVADLL_DLL __declspec(dllimport)
#endif


enum JavaDLLParameterTypes
{
	I3Integer = 1,
	I3Double = 2,
	I3Boolean = 3,
	I3String = 4,
	I3DateTime = 5,
	I3Database = 6,
	I3DatabaseConnection = 7,
	I3IntegerList = 101,
	I3DoubleList = 102,
	I3BooleanList = 103,
	I3StringList = 104,
	I3DateTimeList = 105,
	I3DatabaseList = 106,
	I3DatabaseConnectionList = 107,
};

typedef struct Parameter
{
	int m_ParameterType;

	//Simple Data Types
	wchar_t *m_String;
	BOOL 	m_Boolean;
	long 	m_Integer;
	double 	m_Double;
	time_t 	m_DateTime;
	long 	m_Database;
	long 	m_DatabaseConnection;
	
	//List Data Types
	wchar_t  **m_StringList;
	BOOL	 *m_BooleanList;
	long	 *m_IntegerList;
	double	 *m_DoubleList;
	time_t	 *m_DateTimeList;
	long	 *m_DatabaseList;
	long	 *m_DatabaseConnectionList;
	
	//Number of items in the list if the parameter is a list
	int		 m_ListCount;

	//True if the parameter is an output parameter
	BOOL m_OutParameter;
	
	//True if the parameter is empty - m_Parameter type will contain 
	//the correct type for this variable, but it will not contain a meaningful
	//value and any value set for this will not be returned to the handler
	BOOL m_EmptyParameter;
} Parameter;

#endif
