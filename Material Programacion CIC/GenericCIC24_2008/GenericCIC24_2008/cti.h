#ifndef CTI_H
#define CTI_H

// precedes the USERID on transfer to inbound
#define TRANSFERFROMPREFIX						"TRANSFERFROM:" // i.e TRANSFERFROM:USERID

#define TELEPHONY_COMMAND_NONE					0

// to be done once after loading the DLL, before anything else
#define TELEPHONY_COMMAND_INITIALIZE			1
// INPUT:  m_DeviceName,m_DeviceLogon,m_DevicePassword,
// OUTPUT: m_ResultCode

// to be done once right before unloading the DLL, after everything else
#define TELEPHONY_COMMAND_FINALIZE				19
// OUTPUT: m_ResultCode

// put call on hold - called from the script only
#define TELEPHONY_COMMAND_HOLD					2
// OUTPUT: m_ResultCode

// start supervised call transfer - called from the script only
#define TELEPHONY_COMMAND_TRANSFERINIT			3
// INPUT:  m_PhoneNumber
// OUTPUT: m_ResultCode

// complete call transfer  - called from the script only
#define TELEPHONY_COMMAND_TRANSFERCOMPLETE		4
// OUTPUT: m_ResultCode

// start supervised call conference - called from the script only
#define TELEPHONY_COMMAND_CONFERENCEINIT		5
// INPUT:  m_PhoneNumber
// OUTPUT: m_ResultCode

// complete call conference - called from the script player only
#define TELEPHONY_COMMAND_CONFERENCECOMPLETE	6
// OUTPUT: m_ResultCode

// cancels TELEPHONY_COMMAND_CONFERENCEINIT - called from the script only
#define TELEPHONY_COMMAND_TRANSFERCANCEL		7
// OUTPUT: m_ResultCode

// hangup call
#define TELEPHONY_COMMAND_HANGUP				8
// OUTPUT: m_ResultCode

// cancels TELEPHONY_COMMAND_HOLD - called from the script only
#define TELEPHONY_COMMAND_UNHOLD				9
// OUTPUT: m_ResultCode

// cancels TELEPHONY_COMMAND_CONFERENCEINIT - called from the script only
#define TELEPHONY_COMMAND_CONFERENCECANCEL		10
// OUTPUT: m_ResultCode

// cancels TELEPHONY_COMMAND_CONFERENCECOMPLETE - called from the script only
#define TELEPHONY_COMMAND_CONFERENCEBREAK		11
// OUTPUT: m_ResultCode

// Dial Phone Number
#define TELEPHONY_COMMAND_DIAL					12
// INPUT:  m_PhoneNumber
// OUTPUT: m_ResultCode

#define TELEPHONY_COMMAND_3WAY					13
// INPUT:  m_PhoneNumber
// OUTPUT: m_ResultCode

#define TELEPHONY_COMMAND_CANCEL3WAY			14
// OUTPUT: m_ResultCode

#define TELEPHONY_COMMAND_BLINDTRANSFER			15
// INPUT:  m_PhoneNumber
// OUTPUT: m_ResultCode

// Called:	1) Inbound mode.	When waiting for inbound call. 
//			2) Predictive mode. When waiting for a call from dialer.
#define TELEPHONY_COMMAND_GETINBOUND			16
// OUTPUT: m_ResultCode, m_Ani, m_Dnis, m_XTelelink, m_IVRFields, m_IVRValues
// returns TELEPHONY_ERROR_CANCELGETINBOUND if user cancels 

// Inbound mode after TELEPHONY_COMMAND_GETINBOUND.
// Can be set in generic setup screen to wait x seconds before answering.
#define TELEPHONY_COMMAND_ANSWERPHONE			17
// OUTPUT: m_ResultCode

#define TELEPHONY_COMMAND_GETVERSIONANDCOMMANDSSUPPORTED 18
// OUTPUT: m_OperationsSupported,m_LibraryVersion;


#define TELEPHONY_COMMAND_GETINBOUND_WEB 19 // AYG 04/01/2004 to be changed to 108 soon
// OUTPUT: m_ResultCode, m_Ani, m_Dnis, m_XTelelink, m_IVRFields, m_IVRValues
// returns TELEPHONY_ERROR_CANCELGETINBOUND if user cancel


#define TELEPHONY_COMMAND_STOPINBOUND 20
// OUTPUT: m_ResultCode

// used in Call Blending to determine whether or not there is an inbound call for me to answer
#define TELEPHONY_COMMAND_INBOUNDCALLFOR_ME 22
// OUTPUT: 	m_ResultCode
// 			m_bInboundCallWaiting TRUE there is an inbound call FALSE there isn't

// currently used from the script  
#define TELEPHONY_COMMAND_SETACDINFO 23
// INPUT :  m_BreakReasonCode (optional)
// INPUT :  m_AgentState
// OUTPUT: 	m_ResultCode

// called at the beginning of break (currently after 20 seconds)
#define TELEPHONY_COMMAND_ACDBREAK   24
// INPUT :  m_BreakType 2 = Standard	or BILL_BREAK, 
//						3 = Meal		or BILL_MEAL
//						4 = Personal	or BILL_PERSONAL 
//						5 = Temp Assign or BILL_TEMPASSIGN
//						6 = Training	or BILL_TRAINING
// INPUT :  m_BreakReasonCode (user defined)
// OUTPUT: 	m_ResultCode

#define TELEPHONY_COMMAND_PLAY_MESSAGE  		25
// INPUT:   m_FullAudioRecordingPath (Name of message files to play)
// OUTPUT: 	m_ResultCode

#define TELEPHONY_COMMAND_WAIT_PLAY_MESSAGE  	26
// INPUT:   m_FullAudioRecordingPath (Name of message files to play)
// OUTPUT: 	m_ResultCode

#define TELEPHONY_COMMAND_EXHANGUP				27
// INPUT:   m_NumberOfSeconds
// OUTPUT: 	m_ResultCode

// for Calltrol predictive.
// use this instead of TELEPHONY_COMMAND_GETINBOUND,
// if this call will be the last one before going to break.
#define TELEPHONY_COMMAND_GETINBOUND_LAST			28
// OUTPUT: m_ResultCode, m_Ani, m_Dnis, m_XTelelink
// returns TELEPHONY_ERROR_CANCELGETINBOUND if user cancels or no call is waiting

// AYG 11/8/2004 sent to dialer to tell it that we are switching to inbound call
#define TELEPHONY_COMMAND_BLENDING_GOINGINBOUND				29
// OUTPUT: None
// AYG 11/8/2004 sent to dialer to tell it that we are switching to outbound call
#define TELEPHONY_COMMAND_BLENDING_GOINGOUTBOUND			30
// OUTPUT: None

// Custom Commands - This is to expose NON-GENERIC commands from within the CallCti function 
// supported by particular telephony Devices or drivers within the CAll. These commands are 
// NEVER called directly by TSRWMAIN. 
#define TELEPHONY_COMMAND_CUSTOM_STARTRECORDING		10000
#define TELEPHONY_COMMAND_CUSTOM_STOPRECORDING		10001
#define TELEPHONY_COMMAND_CUSTOM_PLAYRECORDING		10002
#define TELEPHONY_COMMAND_CUSTOM_STOPPLAYRECORDING	10003
// For Generic DLL's tells the .dll that the call was answered
#define TELEPHONY_COMMAND_CUSTOM_CONNECTEDPROPERLY	10004 

// TELESCRIPT SPECIFIC COMMANDS:	
// not implemented
#define TELESCRIPT_COMMAND_OPENTELEPHONYPANEL		105

// called each time a telescript project is opened.
#define TELESCRIPT_COMMAND_OPENTELEPHONYPROJECT		106
// INPUT:	m_ProjectName, m_uQueue, m_TelescriptProgMode, 
//			m_uPredictivePacing, m_uAnswerDelay, m_ACDProjID
// OUTPUT: m_ResultCode

// called each time a telescript project is closed.
#define TELESCRIPT_COMMAND_CLOSETELEPHONYPROJECT	107
// OUTPUT: m_ResultCode
 
#define TELEPHONY_ERROR_OK                   0
#define TELEPHONY_ERROR_BUSY                 1
#define TELEPHONY_ERROR_BADNUMBER            2
#define TELEPHONY_ERROR_NODIALTONE           3
#define TELEPHONY_ERROR_OPTIONNOTAVAILABLE   4
#define TELEPHONY_ERROR_UNKNOWN              5
#define TELEPHONY_ERROR_NOTINITIALIZED       6
#define TELEPHONY_ERROR_WAITCANCELLED        7
#define TELEPHONY_ERROR_DLLNOTLOADEDPROPERLY 8
#define TELEPHONY_ERROR_CANCELGETINBOUND	 9
#define TELEPHONY_ERROR_NOTIMPLEMENTED       10
#define TELEPHONY_ERROR_ATTEMPTINGTOOPENPROJECTTHATISALREADYOPEN     11
#define TELEPHONY_ERROR_ATTEMPTINGTOCLOSEPROJECTTHATISALREADYCLOSED  12

#define TELEPHONYTYPE_NONE		0
#define TELEPHONYTYPE_MODEM		1
#define TELEPHONYTYPE_TAPI		2
#define TELEPHONYTYPE_TSAPI		3
#define TELEPHONYTYPE_DIALER	4
#define TELEPHONYTYPE_GENERIC	5
 
#define OUTBOUND_SWITCHTOINBOUND   (-1)
#define TELESCRIPT_NOMORERECORDS   -2

#define DCR_CONNECTED_NONE			0
#define DCR_WAITING_FOR_RESULT		1
#define DCR_CONNECTED_PROPERLY		2
#define DCR_LINE_BUSY				3
#define DCR_LINE_NOANSWER			4
#define DCR_LINE_ERROR				5
#define DCR_LINE_ANSWERING_MACHINE	6
#define DCR_LINE_CALLER_HUNGUP		7
#define DCR_LINE_CALLEE_HUNGUP		8
#define DCR_LINE_NO_CONTACT			9
#define DCR_LINE_SIT_TONE			10

class CStringArray;
class CDWordArray;

#pragma pack(1)
// AYG 06/17/2005 added m_OutBoundXTelelink which is set for outbound calls right before 
// the dial command is issued
// AYG 05/31/2005 added m_TransferAndConferenceCallerID which is reset 
// at the beginning of each script
// AYG 04/06/2005 pass ANI to PREDICT.DLL
// AYG 11/09/2004 project that we are blending to... m_NextBlendedProject
// 11/2/2004 new .ini setting for predict
struct CTI_PARAM
{
	CTI_PARAM()
	{
		m_Action = m_BlendingAssignedToThisTerminal = 0;
		memset(m_BlendedProjectName,'\0',sizeof(m_BlendedProjectName));
		m_SecsToWaitForCall=m_SrcWstation=0;
		memset(m_SrcUserID,'\0',sizeof(m_SrcUserID));
		memset(m_PhoneExtension1,'\0',sizeof(m_PhoneExtension1));
		memset(m_PhoneExtension2,'\0',sizeof(m_PhoneExtension2));
		memset(m_AgentPhoneSystemLogin,'\0',sizeof(m_AgentPhoneSystemLogin));
		memset(m_AgentPhoneSystemPassword,'\0',sizeof(m_AgentPhoneSystemPassword));
		m_TelephonyTypeInbound=m_TelephonyTypeOutbound=m_TelephonyTypeDatabase= 0; 
		memset(m_PhonePrefix,'\0',sizeof(m_PhonePrefix));
		memset(m_PhoneSuffix,'\0',sizeof(m_PhoneSuffix));
		memset(m_ModemInitializationString,'\0',sizeof(m_ModemInitializationString));
		memset(m_ModemHangupString,'\0',sizeof(m_ModemHangupString));
		m_ModemOrServerPort = 0;
		memset(m_LineAddress,'\0',sizeof(m_LineAddress));
		memset(m_ServerName,'\0',sizeof(m_ServerName));
		m_StationID = 0;
		memset(m_DeviceName,'\0',sizeof(m_DeviceName));
		memset(m_DeviceLogon,'\0',sizeof(m_DeviceLogon));
		memset(m_DevicePassword,'\0',sizeof(m_DevicePassword));
		m_bDoNotPoll=0;
		memset(m_PhoneNumber,'\0',sizeof(m_PhoneNumber));
		m_CurrentTelephonyType=0;
		m_TelescriptProgMode = 0;
		memset(m_ProjectName,'\0',sizeof(m_ProjectName));
		m_Queue=m_DestWstation=0;
		memset(m_DestUserID,'\0',sizeof(m_DestUserID));
		memset(m_FullAudioRecordingPath,'\0',sizeof(m_FullAudioRecordingPath));
		memset(m_FullVideoRecordingPath,'\0',sizeof(m_FullVideoRecordingPath));
		m_Result = 0;
		memset(m_Ani,'\0',sizeof(m_Ani));
		memset(m_Dnis,'\0',sizeof(m_Dnis));
		m_XTelelink = 0;
		m_Skill=m_BreakType=m_BreakReasonCode=m_ACDProjID=m_AgentState=0;
		m_IVRFields=m_IVRValues=NULL;
		m_OperationsSupported=NULL;
		m_LibraryVersion = m_PredictivePacing=m_AnsweringMachineDelay=0;
		m_lACDGroupsAssignedToThisTerminal1_32=m_lACDGroupsAssignedToThisTerminal33_64=m_nInboundCallsWaiting=
		m_NumberOfSeconds=m_lMaxNumberOfRings=m_DialConnectionResult=m_CustomRecordingFormat=0;
		m_CustomHWND=0;
		m_bLastPredictiveCall = 0;
		m_UserSuperDialLinesForTransfer = 0;
		memset(m_NextBlendedProject,'\0',sizeof(m_NextBlendedProject));
		m_NextBlendedQueue= 0;
		memset(m_DialerANI,'\0',sizeof(m_DialerANI));
		m_DialerANI_LastQueue = 0;
		memset(m_TransferAndConferenceCallerID,'\0',sizeof(m_TransferAndConferenceCallerID));
		m_OutBoundXTelelink = 0;
};
//////////////////////////////// INPUT ////////////////////////////////
	// telephony action to execute
	// TELEPHONY_COMMAND_ *
	unsigned m_Action;
	
	// VALUES NEVER CHANGE FOR LENGTH OF PROGRAM
	// SRC - TSADMIN PROJECT ASSIGNMENT SCREEN
	BOOL m_BlendingAssignedToThisTerminal; // currently only predictive and superdial	
	char m_BlendedProjectName[50]; // switch to inbound
	
	// SRC - TSADMIN SYSTEM DEFAULT SCREEN
	unsigned m_SecsToWaitForCall; // 0 == infinite 

	// SRC - USER SIGNON SCREEN
	unsigned m_SrcWstation;// callers telescript workstation
	char m_SrcUserID[30];// callers telescrp id

	// SRC - TERMINAL SETTING SCREEN
	char m_PhoneExtension1[30];// callers
	char m_PhoneExtension2[30];// callers
	char m_AgentPhoneSystemLogin[30]; // from the personnel screen
	char m_AgentPhoneSystemPassword[30];// from the personnel screen

	//TELEPHONYTYPE *
	unsigned short m_TelephonyTypeInbound;
	unsigned short m_TelephonyTypeOutbound;
	unsigned short m_TelephonyTypeDatabase; // not being used now
	
	// SRC - GENERIC SCREEN
	// SRC - MODEM SCREEN
	// SRC - TAPI SCREEN
	// SRC - TSAPI SCREEN
	// SRC - PREDICTIVE
	char m_PhonePrefix[22];
	char m_PhoneSuffix[22];

	// SRC - MODEM SCREEN
	char m_ModemInitializationString[64];
	char m_ModemHangupString[30];
	unsigned m_ModemOrServerPort; // Server Port is currently for Generic 

	// SRC - GENERIC SCREEN
	// SRC - TAPI SCREEN
	char m_LineAddress[64];

	// SRC - GENERIC SCREEN
	char m_ServerName[64];
	UINT m_StationID;

	// SRC - GENERIC SCREEN
	// SRC - TAPI SCREEN
	// SRC - TSAPI SCREEN
	char m_DeviceName[64]; 

	// SRC - GENERIC SCREEN
	// SRC - TSAPI SCREEN
	char m_DeviceLogon[64];
	char m_DevicePassword[64];
	
/// VARIABLE INPUT
	// SRC - TSRWMAIN
	BOOL m_bDoNotPoll; // is tsrwmain going to poll on inbound/predictive or is the .dll
	char  m_PhoneNumber[30];
	unsigned short m_CurrentTelephonyType;

	// TELESCRIPT INFORMATION
	unsigned m_TelescriptProgMode;
	//ePM_none,ePM_database,ePM_inbound,ePM_windial,ePM_superdial,ePM_predictivedial,ePM_generic

	char m_ProjectName[50];
	unsigned m_Queue; // i/o 0 means random queues
	unsigned m_DestWstation;

	char m_DestUserID[30];
	char m_FullAudioRecordingPath[300];
	char m_FullVideoRecordingPath[300];
//////////////////////////////// OUTPUT ////////////////////////////////
	// TELEPHONY_ERROR_ *
	// only looked at if 
	unsigned m_Result;
	
	//predictive and inbound fill these fields
	char m_Ani[30];
	char m_Dnis[30];
	//predictive fills this field
	// > 0
	// may also have these values:
	// 1) OUTBOUND_SWITCHTOINBOUND  
	// 2) TELESCRIPT_NOMORERECORDS
	long m_XTelelink;

	/* for CStringArray* and CWordArray* members:
	      caller allocates an object and points the pointer to it
	      DLL modifies the object pointed to, but not the pointer
	      caller frees the object
	*/
	CStringArray *m_IVRFields;
	CStringArray *m_IVRValues;

	CWordArray   *m_OperationsSupported;
	long m_LibraryVersion;
	long m_PredictivePacing; // per project
	long m_AnsweringMachineDelay;// per project
	unsigned long m_lACDGroupsAssignedToThisTerminal1_32;
	unsigned long m_lACDGroupsAssignedToThisTerminal33_64;
	int m_nInboundCallsWaiting;
	DWORD m_Skill;
	DWORD m_BreakType;
	DWORD m_BreakReasonCode;
	DWORD m_ACDProjID;
	DWORD m_AgentState;
	DWORD m_NumberOfSeconds;
	DWORD m_lMaxNumberOfRings;
	char  m_DialConnectionResult; // DCR_*
	char  m_CustomRecordingFormat;
	DWORD m_Reserved1;	// in seconds should default to around 15 seconds
							// defined as time from start dial to voice heard	
	char  m_LogTelephonyEvents;
	char  m_CallAnalysis;
	DWORD m_CustomHWND;
	DWORD m_CustomMessage; // WParam = DCR_*
	char  m_bLastPredictiveCall;
	// 11/2/2004 new .ini setting for predict
	char  m_UserSuperDialLinesForTransfer;
	// AYG 11/09/2004 project and queue that we are blending to...
	char  m_NextBlendedProject[26];
	short m_NextBlendedQueue;
	// AYG 04/06/2005 I read this in from the predictiveprojects table when doing outbound
	char  m_DialerANI[100];
	// AYG 04/06/2005 For random queues I need to know the last queue number used
	short  m_DialerANI_LastQueue;
	char  m_TransferAndConferenceCallerID[100];
	// AYG 06/17/2005 see comments above;
	int   m_OutBoundXTelelink;
	char  m_Reserved[708];
//	char  m_Reserved[712];
//	char  m_Reserved[812];
//	char  m_Reserved[916];
//	char  m_Reserved[942];
//	char  m_Reserved[952];
//	char  m_Reserved[958];
//	char  m_Reserved[959];
};
#pragma pack()

#ifdef __cplusplus
extern "C"
{
#endif

__declspec(dllexport)  BOOL CallCti(struct CTI_PARAM *stCTI_PARAM);
typedef BOOL  (* CALLCTI)(struct CTI_PARAM *stCTI_PARAM);

/* strError points to an array of MAXTELEPHONYMESSAGE chars */
#define MAXTELEPHONYMESSAGE 500
__declspec(dllexport)  BOOL GetLastTelephonyError(char *strError);
typedef BOOL  (* LPFNGETLASTTELEPHONYERROR)(char *strError);

#ifdef __cplusplus
}
#endif


#endif
