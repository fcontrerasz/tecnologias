#pragma once
#include "resource.h"


#define DIALING 103
#define ALERTING 1
#define CONNECTED 105
#define CONNECTED2 2
#define DISCONNECTED 106
#define INITIALIZING 100
#define MANUALDIALING 102
#define OFFERING 101
#define ONHOLD 4
#define STATIONAUDIO 107

#define TIMEOUT_NOANSWER 1
#define TIMEOUT_BALLOON  2


class CTelephony
{
public:
	CTelephony();
	~CTelephony();

	ISIPPhonePtr		 IC_SipPhone;
	IEICServer3Ptr       IC_Server;
	IEICQueue2Ptr		 IC_Queue; 
	IEICCallObject2Ptr	 IC_Call;
	IEICNotificationPtr  IC_Notification;
	IEICUser3Ptr         IC_User;
	
	CCallObjectWatcher*	 IC_CallWatcher;
	CQueueWatcher*		 IC_QueueWatcher;

	IEICCallObject2Ptr	 IC_TempCall;

	bool InitializePhone(_bstr_t user, _bstr_t password, _bstr_t station, _bstr_t server);
	void Shutdown(_bstr_t user, _bstr_t station);
	void Dial(_bstr_t number);
	void Hangup();
	void StartRecord();
	void EndRecord();
	void SetAttribute(_bstr_t name, _bstr_t value);
	bool IsOnCall();
	
};
