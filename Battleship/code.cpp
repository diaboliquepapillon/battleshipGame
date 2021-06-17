#include <iostream>
#include <string>
#include <fstream> //https://www.youtube.com/watch?v=Iho2EdJgusQ Ya otsuda viuchila
#include <string.h>
#include <time.h>
#include "board.h"
#include "Functions.h"
#include "Account.h"


using namespace std;

const int ARRAY_SIZE = 100;

struct UserAcct
{
	string userName;
	string password;
	string firstName;
	int wins;
	int losses;
	double winPercent;
};

int main()
{
	char mainChoice;
	int count = 0;						//counts number of players in the player array
	UserAcct player[ARRAY_SIZE];
	fstream userData;
	userData.open("playerdata.dat", ios::in);
	if (userData.fail())				//if file does not exist, we will create it
	{
		userData.open("playerdata.dat", ios::out);

		//add computer user
		player[0].userName = "computer";
		player[0].password = "11111";
		player[0].firstName = "Computer";
		player[0].wins = 0;
		player[0].losses = 0;
		if (player[0].wins == 0 && player[0].losses == 0)
			player[0].winPercent = 0.0;
		else
			player[0].winPercent = player[0].wins / ((double)player[0].wins + player[0].losses) * 100.0;

		//write the computer user to the userData file
		userData << player[0].userName << "\n";
		userData << player[0].password << "\n";
		userData << player[0].firstName << "\n";
		userData << player[0].wins << "\n";
		userData << player[0].losses << "\n";
		userData << player[0].winPercent << "\n";

		userData.close();
	}

	//if the file exists, put the player into the player array
	else
	{
		getline(userData, player[count].userName);
		getline(userData, player[count].password);
		getline(userData, player[count].firstName);
		userData >> player[count].wins;
		userData >> player[count].losses;
		userData >> player[count].winPercent;

		count++;


		while (userData >> player[count].userName)
		{
			userData >> player[count].password;
			userData >> player[count].firstName;
			userData >> player[count].wins;
			userData >> player[count].losses;
			userData >> player[count].winPercent;

			count++;

		}

		userData.close();				//close the file
	}

	/*
	//testing the player array
	//   (uncomment this block to see the entire contents of the
	//		player data file displayed on screen)
	for (int index = 0; index < count; index++)
	{
		cout << "Player #" << index << endl;
		cout << "User Name:\t" << player[index].userName << endl;
		cout << "Password:\t" << player[index].password << endl;
		cout << "First Name:\t" << player[index].firstName << endl;
		cout << "Wins:\t\t" << player[index].wins << endl;
		cout << "Losses:\t\t" << player[index].losses << endl;
		cout << "Win Percentage:\t" << player[index].winPercent << endl << endl;
	}
	system("pause");
	*/

	system("cls");
	showLogo();

	mainChoice = showMainMenu();

	{
		while (mainChoice != '4')
		{
			switch (mainChoice)
			{
			case '1':
				onePlayerGame(userData, mainChoice, count, player);
				break;
			case '2':
				twoPlayerGame(userData, mainChoice, count, player);
				break;
			case '3':
				accountSettings(userData, player, mainChoice, count);
				break;
			default:
				system("cls");
				showLogo();

				cout << "\t\t      You have entered an invalid choice."; //colorchange
				cout << "\a";

				mainChoice = showMainMenu();

			}
		}
		system("cls");

		showLogo();

		cout << "\n\n\t\t\tYou have chosen to end the game.\n\n\t\t\t    Thank you for playing!";
		cout << "\n\n\n\n\n\n\nGame is exiting....\n";

	}
	//system("pause");
	return 0;
}