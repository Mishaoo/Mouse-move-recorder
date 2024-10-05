#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <thread>
using namespace std;

void countingSeconds(int second, bool& flag)
{
	for (int i = 0; i < second; i++)
	{
		Sleep(1000);
	}
	cout << "Good! Your mouse is being recorded. Click any key to continue . . ." << endl;
	system("pause >> void");
	flag = true;
}
