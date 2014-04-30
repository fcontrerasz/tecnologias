

// stuff specific to Microsoft's Visual C++ compiler

#ifdef _MSC_VER
	#ifndef REG_DLL
		#define REG_DLL __declspec(dllimport)
	#endif
#else
	// other compilers
	#define REG_DLL
#endif

