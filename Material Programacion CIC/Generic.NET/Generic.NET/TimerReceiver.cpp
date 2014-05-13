#include "StdAfx.h"
#include ".\timerreceiver.h"
#include "Generic.h";

ManagedLib::TimerReceiver::TimerReceiver(void)
{
	stCTI_TIMERCALLBACK = new TimerCallback(this,&TimerReceiver::Receive);
	stCTI_AUTOEVENT     = new AutoResetEvent(false);
	stCTI_ACTION		= -1;
}

void ManagedLib::TimerReceiver::Receive(Object *o)
{
	if (stCTI_ACTION<1)
		AfxMessageBox("no");
	else
		CGenericApp::GetGeneric()->TimerReceiver((int)stCTI_ACTION);
}

void ManagedLib::TimerReceiver::StartTimer(int miliseconds, int action)
{
	stCTI_ACTION = action;
	if (stCTI_TIMER == NULL)
	{
		stCTI_TIMER	= new Timer(stCTI_TIMERCALLBACK,stCTI_AUTOEVENT,0,miliseconds);
	}
	else 
	{
		stCTI_TIMER->Change(0,miliseconds);
	}
}

void ManagedLib::TimerReceiver::StopTimer()
{
	stCTI_ACTION = -1;
	stCTI_TIMER->Change(Timeout::Infinite,0);
}

