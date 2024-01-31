#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <cassert>

using namespace std;

#include "DataBase.h"


class System {

public:

	static int Key_Check(int key, int choice, int min, int max)
	{
		if (key == 72) {
			choice--;
			if (choice < min) choice = max;
		}
		else if (key == 77) {
			choice--;
			if (choice < min) choice = max;
		}
		else if (key == 75) {
			choice++;
			if (choice > max) choice = min;
		}
		else if (key == 80) {
			choice++;
			if (choice > max) choice = min;
		}
		else if (key == 119) {
			choice--;
			if (choice < min) choice = max;
		}
		else if (key == 97) {
			choice++;
			if (choice > max) choice = min;
		}
		else if (key == 115) {
			choice++;
			if (choice > max) choice = min;
		}
		else if (key == 100) {
			choice--;
			if (choice < min) choice = max;
		}

		return choice;
	}

	static void Control()
	{
		Database db;

		Registration twitter(db);

		short int key, secim = 1;
		
		while (true)
		{
			system("cls");

			cout << (secim == 1 ? "\t>>>  " : "\t     ") << "[ 1 ] - Show All Users.\n";
			cout << (secim == 2 ? "\t>>>  " : "\t     ") << "[ 2 ] - Sign In.\n";
			cout << (secim == 3 ? "\t>>>  " : "\t     ") << "[ 3 ] - Sign Up.\n";
			cout << (secim == 0 ? "\t>>>  " : "\t     ") << "[ 0 ] - Exit\n";

			key = _getch();

			if (key == 224)
			{
				key = _getch();
				secim = Key_Check(key, secim, 0, 3);
			}
			else if (key == 13)
			{
				if (secim == 1)
				{
					cout << "\n\t\t>>>>>  All Users  <<<<<\n\n";

					twitter.ShowAllUsers();

					system("pause");
				}
				else if (secim == 2)
				{
					string userName, Password;

					cout << "\n\nEnter Username : ";
					cin >> userName;
					cout << "\nEnter Password : ";
					cin >> Password;

					twitter.Sign_In(userName, Password);
					system("pause");
				}
				else if (secim == 3)
				{
					string userName, Password, Name, Surname;

					cout << "\n\nEnter Username : ";
					cin >> userName;
					cout << "\nEnter Password : ";
					cin >> Password;
					cout << "\nEnter Name : ";
					cin >> Name;
					cout << "\nEnter Surname : ";
					cin >> Surname;

					twitter.Sign_Up(userName, Password, Name, Surname);
					system("pause");
				}
				else if (secim == 0) break;
			}
			else { secim = Key_Check(key, secim, 0, 3); }
		}
	}
};


void main()
{
	System::Control();
	system("pause");
}