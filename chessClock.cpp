#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<conio.h>

using namespace std;

int userTime;
int user1Minutes;
int user2Minutes;
int user1Seconds;
int user2Seconds;

void sleep(float seconds)
{
	clock_t startClock = clock();
	float secondsAhead = seconds*CLOCKS_PER_SEC;

	while(clock() < startClock+secondsAhead);
	return;

}
void menu()
{
	bool userCorrect = true;
	do
	{
		cout << "Please Enter The Time Control You Want" << endl;
		cout << "1. Rapid (10 minutes)" << endl;
		cout << "2. Blitz (5 minutes)" << endl;
		cout << "3. Bullet (3 minutes)" << endl;
		cout << "4. Custom" << endl;

		cin >> userTime;
		if((userTime == 1) || (userTime == 2) || (userTime == 3) || (userTime == 4))
		{
			if(userTime == 1)
			{
				userTime = 10;
			}
			else if(userTime == 2)
			{
				userTime = 5;
			}
			else if(userTime == 3)
			{
				userTime = 3;
			}
			else if(userTime == 4)
			{
				cout << "Enter the number of minutes you want for your time control: "; cin >> userTime;
				system("CLS");
			}
			userCorrect = true;
		}
		else
		{
			cout << "Enter a correct Choice Please" << endl;
			sleep(1.0);
			system("CLS");
			userCorrect = false;
		}
	}while(userCorrect == false);
	system("CLS");
	
}

string ClockDisplay(int m1, int s1)
{
	string str;
	if(m1 < 10)
	{
		if(s1 < 10)
		{
			str = '0' + to_string(m1) + ':' + '0' + to_string(s1);
			return str;
		}
		else
		{
			str = '0' + to_string(m1) + ':' + to_string(s1);
			return str;
		}
	}
	else
	{
		if(s1 < 10)
		{
			str = to_string(m1) + ':' + '0' + to_string(s1);
			return str;
		}
		else
		{
			str = to_string(m1) + ':' + to_string(s1);
			return str;
		}
	}
}

void chessClock(int minutes1, int seconds1, int minutes2, int seconds2)
{

	minutes1 = userTime;
	minutes2 = userTime;
	seconds2 = 0;
	seconds1 = 0;
	bool loop1 = true;
	bool loop2 = false;

	while((minutes1 >= 0) && (minutes2 >= 0))
	{
		while(loop1 && ((minutes1 >= 0) && (minutes2 >= 0)))
		{
			cout << "\t\t\t\t" << "White: "<< ClockDisplay(minutes1, seconds1) << "\t\t\t\t" << "Black: " << ClockDisplay(minutes2, seconds2) << endl;
			if(seconds1 == 0)
			{
				seconds1 = 60;
				minutes1--;
			}
			seconds1--;
			sleep(1.0);
			system("CLS");

			if(_kbhit())
			{
				loop1 = false;
				loop2 = true;
			}
		}


		while(_kbhit()) getch();
		

		while(loop2 && ((minutes1 >= 0) && (minutes2 >= 0)))
		{
			cout << "\t\t\t\t" << "White: " << ClockDisplay(minutes1, seconds1) << "\t\t\t\t" << "Black: " << ClockDisplay(minutes2, seconds2) << endl;
			if(seconds2 == 0)
			{
				seconds2 = 60;
				minutes2--;
			}
			seconds2--;
			sleep(1.0);
			system("CLS");

			if(_kbhit())
			{
				loop2 = false;
				loop1 = true;
			}
		}
		while(_kbhit()) getch();
	}
	user1Seconds = seconds1 + minutes1;
	user2Seconds = seconds2 + minutes2;
}

int main()
{
		menu();
		chessClock(userTime, 0, userTime, 0);
		cout << "Game Over!" << endl;
		if(user2Seconds < user1Seconds)
		{
			cout << "Black Wins!" << endl;
		}
		else if(user1Seconds < user2Seconds)
		{
			cout << "White Wins!" << endl;
		}

}