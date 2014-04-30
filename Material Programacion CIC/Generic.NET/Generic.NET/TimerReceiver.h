#pragma once

using namespace System;
using namespace System::Threading;

namespace ManagedLib	{
	__gc class TimerReceiver
	{
	public:

		TimerCallback* stCTI_TIMERCALLBACK;
		Timer*	stCTI_TIMER;
		AutoResetEvent* stCTI_AUTOEVENT;

		int stCTI_ACTION;
		
		TimerReceiver();

		void Receive(Object *o);
		void StartTimer(int miliseconds, int action);
		void StopTimer();
	};

}
