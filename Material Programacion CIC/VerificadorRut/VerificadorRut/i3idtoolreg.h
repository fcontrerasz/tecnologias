#ifndef I3IDTOOLREG_h		
#define I3IDTOOLREG_h		


#include "I3IDTool.h"
#include "idregdll.h"

extern "C" {


//-----------------------------------------------------------------------------
// General state information for ID
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Summary:	Indicates whether ID is currently processing a batch publish 
//				operation.  You might want to use this to determine whether 
//				you want to pop warning dlg boxes for the user.  If this function
//				returns 1 (TRUE) and I3IDShowPublishErrorDlgs returns 1, then 
//				our recommendation is that you display error dlgs, but not warnings
//				or other "lesser" dlgs.
// Note:    This "in batch publish" state can only be true while ID is
//				processing handlers during a batch publish.  It will _never_ be 
//				true when, for instance, your tools are registering (because ID
//				has not yet started any batch publishing when tools register).
//				So only resource-supporting tools (who get callbacks during 
//				publish of handlers) will need this function.
//
//				return codes:
//				-1 for error
//				0 for FALSE
//				1 for TRUE
//-----------------------------------------------------------------------------
long REG_DLL I3IDIsBatchPublishing();


//--------------------------------------------------------------------------
// Summary: Indicates whether the user has specified the /LogPublishEvents
//				cmd line switch.  If they have, this function will return 0 (FALSE)
//				and your tool should not pop any modal dlgs.  Instead, you should 
//				write the error information to the NT event log.
// Notes:
//				returns
//				-1 for error
//				0 for FALSE
//				1 for TRUE
//--------------------------------------------------------------------------
long REG_DLL I3IDShowPublishErrorDlgs();



//-----------------------------------------------------------------------------
// IdTool Error strings information
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Summary:	Retrieves the error string length corresponding to a given error
//          code
// Note:    This is the length in characters not in bytes.
//          The count does not include a null terminator.
//          Returns 0 if the error No doesn't exist.
//-----------------------------------------------------------------------------
long REG_DLL I3IDGetErrorMessageLength(
	IdToolRetCode_t nErrno				// see enum for IdTool error Nos.
);


//-----------------------------------------------------------------------------
// Summary:	Retrieves the error string corresponding to a given error code
// Note:    Fills the given buffer with an empty string
//          if the error No doesn't exist.
//-----------------------------------------------------------------------------
long REG_DLL I3IDGetErrorMessage(		// returns how many characters have
										// been really copied
	IdToolRetCode_t nErrno,				// see enum for IdTool error Nos.
	wchar_t*        pwszMessage,		// the buffer where the error goes.
	long            nMessageLength		// the buffer length
);


//-----------------------------------------------------------------------------
// Tool Registration
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Summary:	Creates a new tool in the Designer's tool palette.
// 			The pToolHdl returned can be used for subsequent calls 
//			to the I3IDAddTool* functions.
// Notes:	The pToolHdl is only valid on return if the return code is 
//			eIdToolRetCode_SUCCESS.
//			The pszToolName, scoped by the name of the pszModule, 
//			is the internal identifier of the tool.  Thus, do not change 
//			tool name or module when "localizing" for a language.  The tool 
//			label, on the other hand, is meant to be localized.  The tool 
//			label is how the user will identify your tool.
//			The function named by pszFuncName should be of this prototype:
//				extern "C" long __declspec(dllexport) funcname(
//					Parameter * p_paParms, 
//					int p_nParms);
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDRegisterTool(	// see enum for return codes
	I3IDToolHandle_t *pToolHdl,		// handle returned if register successful
    const wchar_t *pszToolLabel,	// tool label -- this must be unique
									// amongst all registered tools, internal 
									// and external
    const wchar_t *pszModule,		// module registering this tool -- 
									// we recommend using the registering 
									// DLL's base name (for uniqueness).
    const wchar_t *pszToolName,		// name of tool -- this must be unique
									// amongst all tool names registered 
									// by the same DLL
    const wchar_t *pszDesc,			// description of tool
	const wchar_t *pszCategory,		// tool palette category for the tool
	HICON hiconLarge,				// icon 32 x 32
	HICON hiconSmall,				// icon 16 x 16
	const wchar_t *pszDLLName,		// DLL from which to load pszFuncName
									// if pszDLLName is NULL => the registering
									// DLL is assumed to contain pszFuncName
	const wchar_t *pszFuncName,		// name of function to be called at 
									// IP run-time to perform this action.
	int p_nNbrParms					// nbr of parameters of this tool
									// Note the parm indexes are zero-based
);
									

//-----------------------------------------------------------------------------
// Summary:	Commits a tool that has been defined through calls to RegisterTool
//			and all the Add functions.
// Notes:	If this function is not called for a tool before the ID is 
//			finished loading ALL tool DLLs, the tool will be de-registered.
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDCommitTool(	// see enum for return codes
	I3IDToolHandle_t toolHdl	// handle of tool to be committed
);


//-----------------------------------------------------------------------------
// Summary:	Adds a possible exit path to the specified tool.
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDAddToolExitPath(	// see enum for return codes
	I3IDToolHandle_t toolHdl,		// tool to which to add the exit path
    const wchar_t *pszPathLabel,	// label for this path out of the tool
    int nReturnCode,				// return code from the tool function
									// which will cause execution to follow
									// this exit path.
    BOOL bShowAsException			// TRUE => this path is an error path
);


//-----------------------------------------------------------------------------
// Summary: Sets a default value for a parameter of a tool.
// Notes:	The parameter must be an input parameter of native type.
//			The parameter must have already been defined for this tool (i.e.
//			created through a call to I3IDAddToolInput*).
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDSetParmDefaultValue(	// see enum for return codes
	I3IDToolHandle_t toolHdl,		// tool to which to add the exit path
	int p_nParmIdx,					// the position of the parameter in the 
									// array of parms that will be passed 
									// to the run-time funciont (zero-based)
    const wchar_t * pszDefaultValue	// default value for the parameter
);


//-----------------------------------------------------------------------------
// Summary: Sets a default variable name for a parameter of a tool.
// Notes:	Valid for use only with parameterd
//			that can accept variables, such as typed combo boxes (inputs) and 
//			entry fields (outputs).
//			If the variable does not exist when the tool is instantiated 
//			in a document, the variable is declared of the correct type for 
//			the parm.  If the variable cannot be declared (for example, 
//			because of name collision or invalid name), the parameter is left
// 			blank. The parameter must have already been defined for this tool
//			(i.e. created through a call to I3IDAddToolInput*).
//			See I3IDSetParmDefaultValue if you want to set a default that 
//			is a literal instead of a variable name.
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDSetParmDefaultVariable(	// see enum for return codes
	I3IDToolHandle_t toolHdl,		// tool to which to add the exit path
	int p_nParmIdx,					// the position of the parameter in the 
									// array of parms that will be passed 
									// to the run-time funciont (zero-based)
    const wchar_t * pszDefaultVarName	// default variable name for this parm.
);



//-----------------------------------------------------------------------------
// Summary:	Adds an output field to the specified tool.  These
//			outputs identify variables that are created by the tool.  For
//			example, MakeCall creates a call object.
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDAddToolOutput(	// see enum for return codes
	I3IDToolHandle_t toolHdl,	// handle to registered tool
	int p_nParmIdx,				// the position of this parameter in the 
								// array of parameters that will be passed 
								// to the run-time function (zero-based) 
    const wchar_t *pszUILabel,	// label for UI property dialog
    const wchar_t *pszTypeName,	// type of the object created
								// this type must have been previously
								// registered with the ID, or it must be 
								// a native ID type
	const wchar_t *pszTypeModule	// module that registered the type.  For 
									// native types, pass NULL
);


//-----------------------------------------------------------------------------
// Summary:	Adds a combobox to the input properties dialog.  If the pszTypeName
//			is a native ID type, the user will be allowed to enter literal 
//			values, otherwise they will be restricted to selecting variables 
//			of the specified type.
// Notes:	The combobox will list all variables of pszTypeName
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDAddToolInputCombobox(	// see enum for return codes
	I3IDToolHandle_t toolHdl,		// handle to registered tool
	int p_nParmIdx,				// the position of this parameter in the 
								// array of parameters that will be passed 
								// to the run-time function (zero-based) 
    const wchar_t *pszUILabel,		// label for UI property dialog
	BOOL bRequired,					// TRUE => this field is required input 
									// from user
    const wchar_t *pszTypeName,		// type of variables to list
	const wchar_t *pszTypeModule	// module that registered the type.  For 
									// native types, pass NULL
);


//-----------------------------------------------------------------------------
// Summary:	Adds a checkbox for a boolean input to the input properties for 
// 			the toolHdl.
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDAddToolInputCheckBox(	// see enum for return codes
	I3IDToolHandle_t toolHdl,	// handle to registered tool
	int p_nParmIdx,				// the position of this parameter in the 
								// array of parameters that will be passed 
								// to the run-time function (zero-based)
    const wchar_t *pszUILabel	// label for UI property dialog
);


//-----------------------------------------------------------------------------
// Summary:	Adds a multiline edit to the input properties for the 
// 			tool.
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDAddToolInputMultiline(	// see enum for return codes
	I3IDToolHandle_t toolHdl,		// handle for registered tool
	int p_nParmIdx,				// the position of this parameter in the 
								// array of parameters that will be passed 
								// to the run-time function (zero-based)
    const wchar_t *pszUILabel,		// label for UI property dialog
    BOOL bRequired					// required value from user
);


//-----------------------------------------------------------------------------
// Summary:	Adds a combobox for a string input to the input properties for 
// 			the toolHdl.
// Notes:	The pfnBuildList function is called when the 
//			string list is needed for UI display.
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDAddToolInputStringCombo(	// see enum for return codes
	I3IDToolHandle_t toolHdl,	// handle for registered tool
	int p_nParmIdx,				// the position of this parameter in the 
								// array of parameters that will be passed 
								// to the run-time function (zero-based)
    const wchar_t *pszUILabel,	// label for UI property dialog
    BOOL bRequired,				// required value from user
    BOOL bAllowEdit				// allow the user to enter new strings
/*%%%    int (*pfnBuildList)(		// ptr to list bldr func
    	CStringList *pStringList) 	// list to be filled
*/
);


/*%%% not using this
//-----------------------------------------------------------------------------
// Summary:	Adds a combobox and button for a complex data field to the 
//			input properties for the toolHdl.  The combobox will list
//			variables of the type pszTypeName.
// Notes:	When this button is pressed, the Edit function specified for that 
// 			complex field in the external type will be called.
// Example: The external type "Voice Prompt" contains a data field 
//			called "WAV data" that is designated as Complex.  Since it is 
//			a Comlex type, an edit function must be specified as well.  Let's 
//			assume the registered edit function is called EditWavFile.  
//			If a tool calls this function specifying "Voice Prompt" and 
//			"WAV data" for the pszTypeName and pszFieldName, respectively, 
//			then when the user views the properties for this tool, they will 
//			see a combobox listing all Handler variables of type "Voice Prompt".
//			When they select one, an edit labeled "WAV data" will be enabled.
//			When the user clicks on the "WAV data" button, the EditWavFile 
//			function will be called with a handle to the complex data field.
//%%% Find out exactly how we want to pass complex field handles
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDAddToolInputEditButton(	// see enum for return codes
	I3IDToolHandle_t toolHdl,	// handle for registered tool
	int p_nParmIdx,				// the position of this parameter in the 
								// array of parameters that will be passed 
								// to the run-time function (zero-based)
    const wchar_t *pszBtnLabel,	// label for btn in UI property dialog
    const wchar_t *pszTypeName,	// the type of the variable being edited
    const wchar_t *pszFieldName	// the field in the variable being edited
);
*/								

//-----------------------------------------------------------------------------
// Summary: Adds a run-time string parameter that is hidden from the user.  
//			Thus, the tool can use this as a way to "pass" itself extra 
//			information.
// Example:	Perhaps you want a single C function to support more than 
//			1 external tool step at IP run-time.  To do so, your C function 
//			should know the context in which it was used (i.e. which action 
//			the user wants carried out).  Use this function to achieve this 
//			capability.  So, your DLL would register 2 different tools with 
//			the ID, but would specify the same C function in both cases.
//			Then for each of the registered tools, your DLL 
//			can add a hidden parameter that indicates which action the 
//			registered tool represents.  At IP run-time, your C function will 
//			receive the value of that hidden parameter as a string input.  
//			Based on the value of that input, your function can perform the 
//			correct action.
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDAddToolHiddenParameter(	// see enum for return codes
	I3IDToolHandle_t toolHdl,	// handle for registered tool
	int p_nParmIdx,				// the position of this parameter in the 
								// array of parameters that will be passed 
								// to the run-time function (zero-based)
    const wchar_t *pszValue		// value to be stored and passed to the 
								// tool's run-time function
);


//-----------------------------------------------------------------------------
// Summary:	Sets the helpfile & context ID in that file for help from 
//			the property sheet of a step instantiated from this tool.
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDSetToolPropertiesHelp(	// see enum for return codes
	I3IDToolHandle_t toolHdl,	// handle for registered tool
	const wchar_t * p_pszHelpFilename,	// path & filename of helpfile
	int p_nHelpContextID		// context ID in p_pszHelpFilename for the 
								// properties of this tool
);

//-----------------------------------------------------------------------------
// Summary: Checks if a tool is registered with pszToolLabel.
//-----------------------------------------------------------------------------
BOOL REG_DLL I3IDToolLabelExists(
    const wchar_t *pszToolLabel	// tool label for which to check
);


//-----------------------------------------------------------------------------
// Summary:	Checks if the tool named by pszRegisteringDLL::pszToolName 
//			is registered with this instance of the ID.
//-----------------------------------------------------------------------------
BOOL REG_DLL I3IDToolExists(	// TRUE => the tool is registered, FALSE 
								// otherwise
    const wchar_t *pszRegisteringDLL,	// the DLL that registered the tool
    const wchar_t *pszToolName	// name of tool for which to check
);




/*%%% Hold until we decide whether this is necessary.
//--------------------------------------------------------------------------
// Summary:	Allows a tool developer to override the default designer 
// 			property dialogs and specify a custom properties editing function.
// 			Sets a function to be called for when the user elects to edit 
// 			the properties of a step (identified by toolHdl).
// 			The current Interaction Handler ID and 
// 			step instance ID will be passed in, allowing the edit function
// 			to call the designer API to get and set parm values for that step.
//--------------------------------------------------------------------------
int I3IDSetToolPropEditFn(
	I3IDToolHandle_t toolHdl,	// handle to registered tool
    void (*pfnEditProperties)(	// func to be called on properties edit of tool
    	hwnd hwndParent,			// hwnd of ID main
        UINT hdlrID,				// Handler ID
        UINT stepID));				// step ID in Handler

*/

//-----------------------------------------------------------------------------
// Initiator Registration
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// Summary:	Creates a new Initiator in the Designer's palette.
// 			The pInitHdl returned can be used for subsequent calls to 
// 			AddInitiator* functions.
// Notes:	The pfnBuildList func will be called to get a list of 
//			 entity names of type pszEntityTypeName.  These entity names will 
//			 be displayed on the properties dialog in a combobox.
//			There is only ONE exit path for an initiator (so there is 
//			 no API call available to add exit paths to initiators)
//			There a max. of ONE output for an initiator (call 
//			 AddInitiatorOutput to register it)
// 			The dwAllowedInitTypes is a mask that indicates the Handler type 
//			 allowed for selection on this handler when it is published.  e.g. 
//			 (INITIATORTYPE_PRIMARY | INITIATORTYPE_MONITOR) would mean 
// 			 that the user will be able to choose whether this is a primary 
//			 handler or a monitor handler when the user decides to publish
//			 this handler, whereas just INITIATORTYPE_PRIMARY indicates 
//			 that the handler can only be published as a primary handler.
//			The prototype for the pszFuncName should be:
//		extern "C" void __declspec(dllexport) funcname (
//						ObjectTypes	p_dwObjectType,
//						DWORD		p_dwObjectId,
//						DWORD		p_dwEventId,
//						void *		p_pData,
//						int			p_nDataLength,
//						Parameter *	p_paParms,
//						int			p_nParms);
// 			
//			 Definitions:
//				Primary Handler - 	the only handler that the IP will run  
//									for a given initiator
//				Monitor Handler -	one of a set of handlers that the IP will  
//									run for a given notification
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDRegisterInitiator(	// see enum for return codes
	I3IDInitHandle_t * pInitHdl,		// returned handle to new initiator 
	DWORD dwAllowedInitTypes,			// bit mask indicating the handler type 
    const wchar_t *pszInitLabel,		// label for initiator.  This must 
										// be unique amongst all initiators
    const wchar_t *pszModule,		// module registering this initiator -- 
									// we recommend using the registering 
									// DLL's base name (for uniqueness).
									// (see notes on I3IDRegisterTool)
	const wchar_t *pszInitiatorName,	// name of initiator.  This must be 
										// unique amongst all initiators 
										// registered by a given DLL.
	const wchar_t *pszDesc,				// description of initiator
	HICON hiconLarge,					// icon 32 x 32
	HICON hiconSmall,					// icon 16 x 16
	const wchar_t *pszObjectType,		// type of entity causing notification
										// this is the notifier object type string
										// Do not internationalize this string
										// see label below
	const wchar_t *pszObjectTypeLabel,		// GUI label for object type
									// internationalize this string
	const wchar_t *pszDLLName,		// DLL from which to load pszFuncName
									// if pszDLLName is NULL => the registering
									// DLL is assumed to contain pszFuncName
	const wchar_t *pszFuncName,		// name of function to be called upon 
									// receipt of this notification.
	int p_nNbrParms					// nbr of output parameters of this 
									// initiator
									// Note the parm indexes are zero-based
);


//-----------------------------------------------------------------------------
// Summary:	Commits an initiator that has been defined through calls to 
//			RegisterIniator and the AddOutput functions.
// Notes:	If this function is not called for an initiator before the ID is 
//			finished loading ALL tool DLLs, the initiator will be de-registered.
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDCommitInitiator(	// see enum for return codes
	I3IDInitHandle_t initHdl	// handle of tool to be committed
);


//-----------------------------------------------------------------------------
// Summary:	Defines an output field for the initiator identified by initHdl
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDAddInitiatorOutput(	// see enum for return codes
	I3IDInitHandle_t initHdl,	// handle to registered initiator
	int p_nParmIdx,				// the position of this parameter in the 
								// array of parameters that will be passed 
								// to the run-time function (zero-based) 
	const wchar_t *pszUILabel,	// label for UI property dialog
	const wchar_t *pszTypeName,	// type of the object created (must be external
								// type)
	const wchar_t *pszTypeModule	// module that registered the type
);


//-----------------------------------------------------------------------------
// Summary: Sets a default variable name for a parameter of an initiator.
// Notes:	Valid for use only with output parameters of initiators
//			If the variable does not exist when the initiator is instantiated 
//			in a document, the variable is declared of the correct type for 
//			the parm.  If the variable cannot be declared (for example, 
//			because of name collision or invalid name), the parameter is left
// 			blank. The parameter must have already been defined for this tool
//			(i.e. created through a call to I3IDAddInitiatorOutput).
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDSetInitParmDefaultVariable(	// see enum for return codes
	I3IDInitHandle_t initHdl,		// initiator for which the default will be set
	int p_nParmIdx,					// the position of the parameter in the 
									// array of parms that will be passed 
									// to the run-time function (zero-based)
    const wchar_t * pszDefaultVarName	// default variable name for this parm.
);


//-----------------------------------------------------------------------------
// Summary: Provides a list of object IDs from which the user can select one
//			when they instantiate the initiator.
// Notes:	Together, the object type, object ID, and event describe a 
//			notification that will cause the IP to start the Handler.
//			Note that the ID will add 1 entry to the list of object ids
//			given here.  That entry's label will be the language equivalent of "{all}",
//			to allow the user to specify all objects of a certain type.  
//			Therefore, the localized language equivalent of "{all}" for an 
//			object ID label will not be accepted on this call.
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDSetInitiatorObjectIDList(
	I3IDInitHandle_t initHdl,		// handle to registered initiator
	const wchar_t * pszObjectIDs,	// object IDs for the object  
									// type given in the RegisterInitiator call
									// these IDs are separated by wcSeparator
	const wchar_t * pszObjectIDLabels,	// GUI labels for the object IDs.
										// internationalize these labels, 
										// not the IDs themselves.
	wchar_t wcSeparator,				// separator char for pszObjectIDs 
	wchar_t wcLabelSeparator		// separator for pszObjectIDLabels
);


//-----------------------------------------------------------------------------
// Summary: Provides a list of events from which the user can select one
//			when they instantiate the initiator.
// Notes:	Together, the object type, object ID, and event describe a 
//			notification that will cause the IP to start the Handler.
//			Note that the Designer will add 1 entry to the list of events 
//			given here.  That entry's label will be the language equivalent of "{all}",
//			to allow the user to specify all events of a certain type.  
//			Therefore, the localized language equivalent of "{all}" for an 
//			event label will not be accepted on this call.
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDSetInitiatorEventList(
	I3IDInitHandle_t initHdl,	// handle to registered initiator
	const wchar_t * pszEvents,	// events for the initHdl
								// type given in the RegisterInitiator call
								// these events are separated by wcSeparator
	const wchar_t * pszEventLabels,	// GUI labels for events
									// internationalize these labels, 
									// not the event strings
	wchar_t wcSeparator,			// separator char for pszEvents 
	wchar_t wcLabelSeparator		// separator for pszEventLabels
);


//-----------------------------------------------------------------------------
// Summary:	Sets the helpfile & context ID in that file for help from 
//			the property sheet of an inititator instantiated from this init def.
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDSetInitPropertiesHelp(	// see enum for return codes
	I3IDInitHandle_t initHdl,	// handle for registered initiator
	const wchar_t * p_pszHelpFilename,	// path & filename of helpfile
	int p_nHelpContextID		// context ID in p_pszHelpFilename for the 
								// properties of this initiator
);


//-----------------------------------------------------------------------------
// Summary:	Checks if the initiator named by pszInitiatorName is registered
//			with the ID.
//-----------------------------------------------------------------------------
BOOL REG_DLL I3IDInitiatorLabelExists(	// TRUE => initiator found, FALSE otherwise
    const wchar_t *pszInitiatorLabel	// label of initiator for which to check
);


//-----------------------------------------------------------------------------
// Summary:	Checks if the initiator named by 
//			pszRegisteringDLL::pszInitiatorName is registered with the ID.
//-----------------------------------------------------------------------------
BOOL REG_DLL I3IDInitiatorExists(	// TRUE => initiator found, FALSE otherwise
    const wchar_t *pszRegisteringDLL,// the DLL that registered the initiator
    const wchar_t *pszInitiatorName	// name of initiator for which to check
);



//-----------------------------------------------------------------------------
// Type Registration
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Summary:	Declares a new type for use by ID end users in Interaction 
//			Handlers.
// Notes:	The pszTypeName must be unique amongst all typenames within 
//			the given module domain.  
//			The ptypeHdl will only have meaning if the operation was 
//			 successful.
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDRegisterType(
	I3IDTypeHandle_t *pTypeHdl,	// returned handle to new type
	const wchar_t *pszTypeLabel,	// label of the typedef
    const wchar_t *pszTypeName, 	// name of the type
    const wchar_t *pszModule,		// module registering this type -- 
									// we recommend using the registering 
									// DLL's base name (for uniqueness).
    const wchar_t *pszDesc		// description of the type
);


//-----------------------------------------------------------------------------
// Summary:	Accepts functions to be called for reference counting of 
//			values in variables of the specified type.
// Notes:	pszDetachFuncName will be called when the Interaction
//			 Processor needs to indicate that a value of this type is 
//			 being dereferenced. These functions can be used so that 
//			 your run-time dll can support reference counting, if necessary.
//			pszAttachFuncName will be called when IP needs to indicate that 
//			 a value of this type getting another reference added to it.
//			For example, suppose x is a variable of external type T.  And 
//			suppose that x is going to be assigned a new value.  
//			Then the handler Java code will:
//				1.  Call T's pszAttachFuncName, passing the _new_ value for 
//					x.
//				2.  Call T's pszDetachFuncName, passing the _old_ value for 
//					x.
//			The Attach & Detach functions should have the following prototypes
// 
//	extern "C" void Attach(
//	    Parameter * p_paParms,          // Parameter 0: INPUT    DWORD    val being "attached to"
//	
//	    int p_nParms
//	);
//	
//	extern "C" void Detach (
//	    Parameter * p_paParms,         // Parameter 0: INPUT    DWORD    val being detached from
//	    int p_nParms
//	);
 

//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDSetTypeRefCountFunctions(
	I3IDTypeHandle_t typeHdl,	// the type for which to set the refcount 
								// functions
	const wchar_t *pszDLLName,	// DLL from which to load the ref count functions
	const wchar_t *pszAttachFuncName,
  	const wchar_t *pszDetachFuncName
);


/*
// --------------------------------------------------------------------------
// I3IDTypeExists
// Summary:	Checks if the specified type has been registered.
// Notes:	
// Returns:	BOOL
//			TRUE indicates that the type has been registered.
//			FALSE indicates that the type is not registered.
// --------------------------------------------------------------------------
BOOL I3IDTypeExists(
	const wchar_t *pszTypeName);	// typename for which to check

*/



//----------------------------------------------------------------------------
// Summary: Returns the number of characters (not including null terminator)
//			in the longest native type name.  
// Notes:	Use this call to determine the size of buffer you should allocate
//			before calling I3IDQueryNativeTypeName.  This is the 
//			number of CHARACTERS, not just BYTES.
//----------------------------------------------------------------------------
int REG_DLL I3IDMaxLenNativeTypeNames();


//----------------------------------------------------------------------------
// Summary: Writes the name of the type (signified by the p_pNameID given) 
//			into p_pszTypeName, including a null terminator
// Notes:	The caller is expected to allocate the wchar_t buffer to a 
//			length that will allow this function to write in the 
//			result chars + a null terminator.  If the total nbr of chars 
//			(result chars + null terminator) is greater than 
//			p_nNbrCharsAllocated, the native type name will be truncated to 
//			fit the caller's buffer.  Caller can check if truncation occurred
//			by comparing p_nNbrCharsAllocated to the returned integer.
//			Use I3IDMaxLenNativeTypeNames to determine the maximum nbr 
//			of chars that will be written into p_ppszTypeName.  Remember 
//			that I3IDMaxLenNativeTypeNames does not count a null terminator.
// Example:
//
//	// add 1 for the null terminator
//	int nLen = I3IDMaxLenNativeTypeNames() + 1;
//	wchar_t * pwBuffer = (wchar_t *)calloc( nLen, sizeof(wchar_t));
//
//	int nRC = I3IDQueryNativeTypeName(eIdNativeTypeNameID_INTEGER,
//								   &pwBuffer, nLen);
//----------------------------------------------------------------------------
int REG_DLL I3IDQueryNativeTypeName( // if >= 0, indicates the nbr of chars written 
									 // into (*p_pszTypeName)
									 // if < 0, indicates an error condition
									 // see IdToolRetCode_t for details
	IdNativeTypeNameID_t p_pNameID,	// see enum for details
	wchar_t * p_pszTypeName,		// ptr to ptr to pre-allocated buffer
									// to receive the type name
	int p_nNbrCharsAllocated		// max nbr chars that (*p_ppszTypeName) 
									// can hold.
);

//-----------------------------------------------------------------------------
// Resource Type Registration
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Summary:	Declares a new resource type for use by ID end users in Interaction 
//			Handlers.
// Notes:	The pszTypeName must be unique amongst all typenames within 
//			the given module domain.  
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDRegisterResourceType(
	const wchar_t *pszResTypeLabel,		// label of the Resource type
    const wchar_t *pszResTypeName,		// name of the type
    const wchar_t *pszModule,			// module registering this type -- 
										// we recommend using the registering 
										// DLL's base name (for uniqueness).
	I3IDEditFunc_t,						// used to externally edit the resource
	I3IDDisplayFunc_t,					// used to display a string in the Property sheet
	I3IDValidateFunc_t,					// used to validate the resource
	I3IDReadFromBufferFunc_t,			// used to read  from ID to the tool
	I3IDWriteToBufferFunc_t,			// used to write from ID to the tool
	I3IDPublishFunc_t,					// used to publish the resource
	I3IDCloseFunc_t					// used to Close the resource
);

//-----------------------------------------------------------------------------
// Summary:	Adds a Resource Editor to the input properties dialog.
//-----------------------------------------------------------------------------
IdToolRetCode_t REG_DLL I3IDAddToolInputResourceEdit(	// see enum for return codes
	I3IDToolHandle_t toolHdl,			// handle to registered tool
	int p_nParmIdx,						// the position of this parameter in the
										// array of parameters that will be passed
										// to the run-time function (zero-based)
    const wchar_t *pszUILabel,			// label for UI property dialog
	BOOL bRequired,						// TRUE => this field is required input
										// from user
    const wchar_t *pszResTypeName,		// type of variables to list
	const wchar_t *pszResTypeModule		// module that registered the type.  For 
);


}


#endif
