#include <iostream>
#include <string>
#include <Windows.h>
#include <thread>
#include "mouseRecordingFunction.h"
#include "countingSecondFunction.h"
#include "ClassMouseTemplate.h"
#include <fstream>
#include <direct.h>  // дл€ _mkdir
#include <errno.h>   // дл€ коду помилки
using namespace std;

const int MOUSE_CORDS_X = 100;
const int MOUSE_CORDS_Y = 100;

int score_mouseTemplate = 0;//ц€ шн€га рахуЇ загальну к≥лк≥сть клас≥в mouseTemplate





int main()
{
	int durationDelayBeforPlay = 2;
	bool program = true;

	int command;

	ClassMouseTemplate mousesTemplate[25];

	const char* folderName = "Data";

	if (_mkdir(folderName) == 0) {
	}
	else if (errno == EEXIST) {
	}

	while (program == true)
	{
		cout << "1: Start mouse template movement" << endl;
		cout << "2: Recording new mouse template movement" << endl;
		cout << "3: Settings" << endl;
		cout << "4: About the program" << endl;
		cout << "5: Exit" << endl;
		cout << ">>";
		cin >> command;



		switch (command)
		{
			case 1:
			{
				if (score_mouseTemplate == 0)
				{
					cout << "You don't have a mouse template. Please go to the menu and create one!" << endl;
				}

				else
				{
					for (int i = 0; i < score_mouseTemplate; i++)
					{
						cout << "Mouse template ID - " << mousesTemplate[i].getId() << "\tDuration - " << mousesTemplate[i].getSeconds() << " seconds" << endl;
					}
					cout << "Enter id >>";
					int selectMouseTemplate;
					cin >> selectMouseTemplate;
					if(durationDelayBeforPlay != 0) cout << "It will start in " << durationDelayBeforPlay << " seconds. (you can disable this in the settings)" << endl;
					cout << "If you want to stop the mouse movement, press \"s\"." << endl;
					Sleep(durationDelayBeforPlay * 1000);
					thread stopMouseMoving(&ClassMouseTemplate::stopMovingMouse, &mousesTemplate[selectMouseTemplate]);
					mousesTemplate[selectMouseTemplate].movingMouse();

					stopMouseMoving.join();
				}

				break;
			}

			case 2:
			{
				if (score_mouseTemplate != 24)
				{
					bool flag = false;
					int timeMouseMove;
					cout << "How many seconds do you want to record the mouse:";
					cin >> timeMouseMove;


					cout << "Recording your mouse . . ." << endl;
					thread threadWhileControl(countingSeconds, timeMouseMove, ref(flag));
					thread threadMouseRecording(mouseRecording, ref(flag), ref(mousesTemplate[score_mouseTemplate]), timeMouseMove, score_mouseTemplate);

					score_mouseTemplate++;

					threadMouseRecording.join();
					threadWhileControl.join();


				
				}

				else
				{
					cout << "you have used all available templates" << endl;
				}
				break;
			}

			case 3:
			{
				cout << "Setting" << endl;
				cout << "1: Change the delay time before playing mouse movements." << endl;
				cout << "2: Disable delay time" << endl;
				int settingChoos;
				cout << ">>";
				cin >> settingChoos;
				if (settingChoos == 1)
				{
					cout << "Enter a new time duration:";
					cin >> durationDelayBeforPlay;
					cout << "Good!" << endl;
					Sleep(500);
				}

				if (settingChoos == 2)
				{
					durationDelayBeforPlay = 0;
					cout << "Duration delay disabled" << endl;
					Sleep(500);
				}

				break;
			}

			case 4:
			{
				cout << "Version 1.0" << endl;
				cout << "Programmer Mykhailo Mosiichuk" << endl;
				cout << "Data last update 05.10.2024" << endl;
				cout << "for continue press any kay" << endl;
				system("pause >> void");
				break;
			}

			case 5:
			{
				program = false;
				break;
			}

			default:
			{
				cout << "There is no such number!" << endl;
				Sleep(700);
			}
		}





		system("cls");

	}






	
	return 0;
}