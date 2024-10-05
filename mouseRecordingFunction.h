#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <thread>
#include "ClassMouseTemplate.h"
using namespace std;

void mouseRecording(bool& flag, ClassMouseTemplate& mouse, int seconds, int id)
{
	POINT point;
	mouse.setSecond(seconds);
	mouse.initId(id);

	while (flag == false)
	{
		GetCursorPos(&point);

		mouse.recordingCord(point.x, point.y);

		Sleep(10);
	}

	
}
