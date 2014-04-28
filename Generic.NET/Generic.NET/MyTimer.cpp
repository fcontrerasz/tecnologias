#include "StdAfx.h"
#include "MyTimer.h"

#pragma once

__gc class MyTimer
{
	int invokeCount, maxCount;

 public:
    // This method is called by the timer delegate.

	MyTimer(int count) : invokeCount(0), maxCount(count) {}

    void CheckStatus(Object* stateInfo)
    {
		
		//AFX_MANAGE_STATE(AfxGetStaticModuleState());
		//AfxMessageBox("si");
    }
};


