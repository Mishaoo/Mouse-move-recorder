#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class ClassMouseTemplate
{
private:
	int secondsMoving = 0;
	bool fileIsCreate = false;
	int scoreIndex = 0;

	bool isMouseMoving = false;

	ofstream fileX;
	ofstream fileY;
	int id = 0;

	string cordFileName = to_string(id);


public:

	void initId(int id)
	{
		this->id = id;
		cordFileName = to_string(id);
	}

	void recordingCord(int x, int y)
	{
		if (fileIsCreate == false)
		{
			// Відкриття файлів та перевірка на успішне відкриття
			fileX.open("data/" + to_string(id) + "x.txt");
			fileY.open("data/" + to_string(id) + "y.txt");

			if (!fileX.is_open() || !fileY.is_open())
			{
				std::cerr << "Не вдалося відкрити файл для запису!" << std::endl;
				return; // вихід, якщо файл не відкрито
			}

			fileIsCreate = true;
		}
		if (fileX.is_open() && fileY.is_open())
		{
			fileX << x << std::endl;  // Запис координат X
			fileY << y << std::endl;  // Запис координат Y
			scoreIndex++;
		}



	}

	void setSecond(int seconds)
	{
		this->secondsMoving = seconds;
	}

	int getSeconds()
	{
		return secondsMoving;
	}

	int getId()
	{
		return id;
	}

	void movingMouse()
	{
		isMouseMoving = true;
		ifstream fileReaderX("data/" + to_string(id) + "x.txt");
		ifstream fileReaderY("data/" + to_string(id) + "y.txt");
		for (int i = 0; i < scoreIndex; i++)
		{
			if(isMouseMoving == true)
			{
				int x;
				fileReaderX >> x;
				int y;
				fileReaderY >> y;

				SetCursorPos(x, y);
				Sleep(10);
			}

			else
			{
				break;
			}
		}
		isMouseMoving = false;
	}

	void closeDate()
	{
		fileX.close();
		fileY.close();
	}


	void stopMovingMouse()
	{
		while (isMouseMoving == true)
		{
			if (GetAsyncKeyState(0x53)) 
			{
				isMouseMoving = false;
				cout << "You have stopped it. Press any key to continue . . ." << endl;
				system("pause >> void");
			}
		}
	}


	ClassMouseTemplate() = default;
};

