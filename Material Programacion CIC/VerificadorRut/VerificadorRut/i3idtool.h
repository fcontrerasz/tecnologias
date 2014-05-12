#ifndef I3IDTOOL_h		
#define I3IDTOOL_h		

#ifdef __cplusplus
extern "C" {
#endif


// Simple Types --------------------------------------------------------------

// The following handle types provide a mechanism for referring to tools 
// you've registered.  These handles are used for subsequent API calls to 
// add on to the definition of that tool.

// the handle for Tools
typedef long I3IDToolHandle_t;

// handle for Initiators
typedef long I3IDInitHandle_t;

// handle for Types
typedef WORD I3IDTypeHandle_t;

// native types in the Interaction Designer
// use these with IdNativeTypeName to 
// get the strings for native types
enum IdNativeTypeNameID_t {
	eIdNativeTypeNameID_STRING,
	eIdNativeTypeNameID_INTEGER,
	eIdNativeTypeNameID_DATETIME,
	eIdNativeTypeNameID_REAL,
	eIdNativeTypeNameID_BOOLEAN,

	eIdNativeTypeNameID_LISTOFSTRING,
	eIdNativeTypeNameID_LISTOFINTEGER,
	eIdNativeTypeNameID_LISTOFDATETIME,
	eIdNativeTypeNameID_LISTOFREAL,
	eIdNativeTypeNameID_LISTOFBOOLEAN,

	eIdNativeTypeNameID_DATABASE,
	eIdNativeTypeNameID_DBCONNECTION,
	eIdNativeTypeNameID_WEBCONNECTION,

	eIdNativeTypeNameID_LISTOFDATABASE,
	eIdNativeTypeNameID_LISTOFDBCONNECTION,
	eIdNativeTypeNameID_LISTOFWEBCONNECTION 
};


// values for use in the Initiator type bitmask.

#define INITIATORTYPE_PRIMARY	0x0001L
#define INITIATORTYPE_MONITOR	0x0002L


// Return codes from the I3ID Tool Registration API.
enum IdToolRetCode_t {
	eIdToolRetCode_SUCCESS = 0,

// API operations
	eIdToolRetCode_TOOLNAMEBLANK = -1,			// tool name was blank
	eIdToolRetCode_TOOLNAMEUSED = -2,			// tool name already registered for 
												// the given module
	eIdToolRetCode_INVALIDHANDLE = -3,			// handle was not valid
	eIdToolRetCode_PATHRETCODEUSED = -4,		// rc specified has already been used
	eIdToolRetCode_PATHNAMEBLANK = -5,			// exit path name was blank
	eIdToolRetCode_PATHNAMEUSED = -6,			// exit path name already registered
	eIdToolRetCode_TYPENAMEBLANK = -7,			// type name was blank
	eIdToolRetCode_TYPENAMEUSED = -8,			// type name already registered
	eIdToolRetCode_PARMLABELBLANK = -9,			// parm label was blank
	eIdToolRetCode_TYPENAMENOTFOUND = -10,		// the type named is not registered
	eIdToolRetCode_FUNCNOTIMPLEMENTED = -11,	// the registration function is 
												// not implemented.
	eIdToolRetCode_STRINGTABLEERROR = -12,		// an internal type name could 
												// not be loaded from the string
												// resource table
	eIdToolRetCode_INTERNALTYPEERROR = -13,		// an internal type could not be found
	eIdToolRetCode_INITIATORNAMEBLANK = -14,	// initiator name was blank
	eIdToolRetCode_INITIATORNAMEUSED = -15,		// initiator name already registered
												// for the given module.
	eIdToolRetCode_INVALIDOPERATION = -16,		// operation not valid for this 
												// entity (tool, parm, etc.)
	eIdToolRetCode_INVALIDTOOL = -17,			// the tool definition is not 
												// consistent with the instance of it.
	eIdToolRetCode_VARNAMEUSED = -18,			// the variable or field cannot be 
												// declared because one with the 
												// same name has already been declared
	eIdToolRetCode_VARNAMEBLANK = -19,			// the var name or field name is blank
	eIdToolRetCode_VARNAMEINVALID = -20,		// var name or field name 
												// contains invalid chars
	eIdToolRetCode_ALREADYINITIALIZED = -21,	// Initialize was already called 
												// for this instance
	eIdToolRetCode_NOTINITIALIZED = -22,		// Initialize was not called 
												// for this object
	eIdToolRetCode_HANDLERNULL = -23,			// the handler ptr given was NULL
	eIdToolRetCode_HANDLERSYNCERR = -24,		// the handler is out of sync with
												// the current doc state
	eIdToolRetCode_RESOURCELOADFAILURE = -25,	// couldn't load a resource
	eIdToolRetCode_INSPECTORFUNCBLANK = -26,	// the run-time inspector 
												// function name for a field 
												// was blank
	eIdToolRetCode_NATIVETYPEREQUIRED = -27,	// a native type was not specified
	eIdToolRetCode_PARMINDEXOUTOFBOUNDS = -28,	// the parameter index specified
												// is outside the bounds indicated
												// by the nbr of parms given
												// when the tool was registered
	eIdToolRetCode_PARMINDEXUSED = -29,			// the parameter index specifed
												// has already been used 
												// for this tool.
	eIdToolRetCode_INVALIDPARMSIZE = -30,		// the parameter array size 
												// is invalid (for example, 
												// it's negative)
	eIdToolRetCode_PARMSIZEALREADYSET = -31,	// SetParmSize has already 
												// been called for this tool.
	eIdToolRetCode_PARMSNOTDEFINED = -32,		// at least one parm for the 
												// tool has not been defined.
	eIdToolRetCode_INVALIDARRAYSIZE = -33,		// the size given for the 
												// array was not acceptable 
												// the current context.
	eIdToolRetCode_INVALIDOBJECTID = -34,		// the object ID given has 
												// already been used (possibly
												// by the "{all}" indicator).
	eIdToolRetCode_PARMNOTDEFINED = -35,		// the specified parameter has 
												// not been defined yet
	eIdToolRetCode_DEFVALUEINVALID = -36,		// the default value specified
												// is not valid.
	eIdToolRetCode_EXTERNTYPEREQUIRED = -37,	// an external type was 
												// not specified.
	eIdToolRetCode_INITIALIZEFAILED = -38,		// the initiailize operation
												// failed.
	eIdToolRetCode_INVALIDEVENT = -39,			// the event given has 
												// already been used (possibly
												// by the "{all}" indicator)
	eIdToolRetCode_NOCOLUMNSBOUND = -40,		// no SQL columns bindings
												// were specified.
	eIdToolRetCode_TOOLLABELUSED = -41,			// tool label already registered
												// tool labels must be unique
												// amongst all registered tools
												// and internal tools
	eIdToolRetCode_INITIATORLABELUSED = -42,	// initiator label already 
												// registered -- these labels
												// must be unique amongst all 
												// registered initiators & 
	eIdToolRetCode_BUFFERTOOSMALL = -43,		// the indicated size of the 
												// given allocated buffer is 
												// too small.
	eIdToolRetCode_BUFFERNULL = -44,			// the given buffer was NULL
	eIdToolRetCode_CANTUSERESERVEDWORD = -45,	// the entity given is a reserved word or phrase
	eIdToolRetCode_ALREADYCOMMITTED = -46,		// the tool or initiator has 
												// already been committed and 
												// cannot be changed
	eIdToolRetCode_ARRAYSNOTMATCHING = -47,		// the "parallel" arrays given 
												// do not contain the same 
												// number of elements.

};


// Return codes from the External Edit function call.
enum IdEditRetCode_t
{
	eIdEditRetCode_ACCEPTED		=  0,			// The user committed its actions
	eIdEditRetCode_CANCELED		= -1,			// The user canceled its actions
	eIdEditRetCode_FAILED		= -2			// The user couldn't edit the resource
};

// Resource OPeration masks. They are given on ReadFrom/WriteTo.
enum IdROPCode_t
{
	eIdROPCode_SAVE,	// called when resources are only saved
	eIdROPCode_COPY,	// called when resources are cut/copied to the clipboard
	eIdROPCode_PUBLISH,	// called when resources are saved during a publish
	eIdROPCode_NEW,		// called when a blank new handler is created
	eIdROPCode_LOAD,	// called when a resources are loaded
	eIdROPCode_PASTE	// called when resources are pasted from the clipboard
};

// the tool variables which can be reached by the EditFunc call.
typedef struct
{
	BOOL   bUsedInResource;						// true if used in the external resource
												// set by the EditFunc call. It will affect
												// the Java code generation.
	LPCSTR pcszVarName;							// ...
	LPCSTR pcszVarType;							// ...
} I3IDExtToolVar;

// this structure is used to describe the resource strings
typedef struct
{
	HGLOBAL hResource;							// the HGLOBAL handler to the resource
												// string. The memory is a WCHAR
												// string terminated by a 0.
	long    nSize;								// the size in bytes of the string
} I3IDResString;

// the EditFunc prototype
typedef IdEditRetCode_t (*I3IDEditFunc_t) (
	const WCHAR*     pwszHandlerName,			// the handler concerned
	HWND             hwndParent,				// The hwnd of the Property Dialog box
	I3IDResString*   pidResString,				// The resource string to be edited
	const WCHAR*     pwszModuleName,			// ...
	const WCHAR*     pwszToolName,				// ...
	I3IDExtToolVar** apetvVars					// This NULL terminated array contains
												// all the variables of the ???. If the
												// external editor use them, check the
												// nUsedByExtTool field of each variable
												// structure. This will be used during the
												// Java generation. Those checked variables
												// will be given to the ???.
												// Note: not used today ;-(, the pointer
												//       will be NULL for a while.
);
/* Notes:
  1) pidResString parameter:
     The hResource member will handle a WCHAR string.
	 The string will be allocated via GlobalAlloc by the API. The function will store
	 in this string the result of its works.
	 Note: this string will be freed using GlobalFree after the function call.
	       Use GlobalRealloc in the function if you have to reallocate the buffer.
	 The nSize member will contain the actual size in byte of the stored resource string.
	 If the resource has never been used, the hResource will be NULL. Use GlobalAlloc to
	 set it.
	 WARNING: If the return hResource is not NULL, it has to handle a valid memory area.
	 If not, Designer will complain and might experience some memory losses.
*/

// the DisplayFunc prototype
typedef HGLOBAL (*I3IDDisplayFunc_t)(			// return a handler which will contain the
												// display string as a wide char string...
												// It's the function responsability to
												// allocate the string. This string will
												// be deallocated by the API later using
												// a GlobalFree if not NULL. If the HGLOBAL
												// is NULL, nothing will be displayed.
	const WCHAR*        pwszHandlerName,		// the handler concerned
	const I3IDResString sResString				// The resource string to be validated
);

// the WriteToBufferFunc prototype
typedef void (*I3IDWriteToBufferFunc_t)(
	const WCHAR*   pwszOldHandlerName,			// the handler concerned (its old name)
	const WCHAR*   pwszNewHandlerName,			// the handler concerned (its new name)
	I3IDResString* arResourceStrings,			// The array containing all the resource
												// strings (see Notes below)
	long           nResourceCount,				// how many resources are in 
												// arResourceStrings and arResources
	HGLOBAL*       phResourceBuffer,			// The buffer which will contain all the
												// resources (see Notes below)
	long*          pnResourceBufferSize,		// its size in bytes
	IdROPCode_t    eROPCode						// The contextual information (see the enum)
);
/* Notes:
  1) arResourceStrings parameter:
     For each element of the array, the hResource member will handle a WCHAR string.
	 The string will be allocated via GlobalAlloc by the API. The function will store
	 in this string the result of its works.
	 Note: this string will be freed using GlobalFree after the function call.
	       Use GlobalRealloc in the function if you have to reallocate the buffer.
	 For each element of the array, the nSize member will contain the actual size
	 in byte of the stored resource string.

  2) phResourceBuffer parameter:
     The phResourceBuffer parameter will handle a byte buffer.
	 This buffer will contain the binary form of all resources. It's the function
	 responsability to allocate it. This buffer will be deallocated by the API
	 later using the GlobalFree Win32 call. So be sure that your memory can be
	 deallocated by this call.
	 Be sure that pnResourceBufferSize will contain the proper size.
	 If there is nothing to store, be sure to have a null size. In that case, no
	 deallocation is done by Designer..
  3) The handler names usually change when the user asked for a SaveAs, Copy, and
     when the user saves a new handler. When this function is called for a Copy, the
	 new handler name is an empty string (in addition to the relevant ROP code).
*/

// the ReadFromBufferFunc prototype
typedef void (*I3IDReadFromBufferFunc_t)(
	const WCHAR*   pwszHandlerName,				// the handler concerned
	I3IDResString* arResourceStrings,			// The array containing all the resource
												// strings (see Notes below)
	long           nResourceCount,				// how many resources are in 
												// arResourceStrings and arResources
	HGLOBAL        hResourceBuffer,				// The buffer which will contain all the
												// resources (see Notes below)
	long           nResourceBufferSize,			// its size in bytes
	IdROPCode_t    eROPCode						// The contextual information (see the enum)
);
/* Notes:
  1) arResourceStrings parameter:
     For each element of the array, the hResource member will handle a WCHAR string.
	 The string will be allocated via GlobalAlloc by the API. The function will store
	 in this string the result of its works.
	 Note: this string will be freed using GlobalFree after the function call.
	       Use GlobalRealloc in the function if you have to reallocate the buffer.
	 For each element of the array, the nSize member will contain the actual size
	 in byte of the stored resource string.

  2) arResources parameter:
     The phResourceBuffer parameter handles a byte buffer.
	 This buffer contains the binary form of the resource as read from the ihd file.
	 The function is not allowed to reallocate nor free this buffer.
*/

// the ValidateFunc prototype
typedef BOOL (*I3IDValidateFunc_t)(				// returns false if the validation failed
	const WCHAR*        pwszHandlerName,		// the handler concerned
	HGLOBAL*            phErrorMessage,			// the handler which will contain the error
												// string as a wide char string...
												// It's the function responsability to
												// allocate the buffer. This buffer will
												// be deallocated by the API later using
												// a GlobalFree if not NULL.
	const I3IDResString  sResString				// The resource string to be validated
);

// the PublishFunc prototype
typedef BOOL (*I3IDPublishFunc_t)(				// returns false if the publication failed
	const WCHAR*         pwszHandlerName,		// the handler concerned
	const I3IDResString* arResourceStrings,		// The array containing all the resource
												// strings
	long                 nResourceCount			// how many resources are in
												// arResourceStrings and arResources
);

// the CloseFunc prototype
typedef void (*I3IDCloseFunc_t)(
	const WCHAR*         pwszHandlerName,		// the handler concerned
	const I3IDResString* arResourceStrings,		// The array containing all the resource
												// strings used by the handler
	long                 nResourceCount			// how many resources are in
												// arResourceStrings and arResources
);

#ifdef __cplusplus
}
#endif

#endif
