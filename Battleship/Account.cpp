#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <time.h>
#include "board.h"
#include "Functions.h"
#include "Account.h"


using namespace std;
//declaring the  constants
const int ARRAY_SIZE = 100;
const int PASSWORD_WIDTH = 16;
const int ROWS = 9;
const int COLS = 9;
const int CARRIER_SIZE = 5;					//Aircraft Carriers are 5 spaces long
const int BATTLESHIP_SIZE = 4;				//Battleships are 4 spaces long
const int SUBMARINE_SIZE = 3;				    //Submarines are 3 spaces long
const int DESTROYER_SIZE = 3;				//Destroyers are 3 spaces long
const int PATROLBOAT_SIZE = 2;				//Patrol Boats are 2 spaces long

struct UserAcct
{
	string userName;
	string password;
	string firstName;
	int wins;
	int losses;
	double winPercent;
};

bool userCheck(UserAcct player[], string uName, int count)
{
	for (int index = 0; index < count; index++)
	{
		if (player[index].userName == uName)
			return true;
	}
	return false;
}
string getPass(int width)
{
	cout << "[";
	for (int i = 0; i < width - 1; i++)
		cout << "_";
	cout << "]";
	for (int i = 0; i < width; i++)
		cout << "\b";
	char letter, pass[PASSWORD_WIDTH];
	int i = 0;
	do
	{
		do
		{
			cin >> letter;
			if (letter != 8 && letter != 13 && i < width - 1)
			{
				pass[i] = letter;
				cout << "*";
				i++;
			}
			else if (letter == 8 && i > 0)
			{
				cout << "\b" << "_" << "\b";
				i--;
			}
		} while (letter != 13 && i < width - 1);
		if (letter != 13)
		{
			cin >> letter;
			if (letter == 8 && i > 0)
			{
				cout << "\b" << "_" << "\b";
				i--;
			}
		}
	} while (letter != 13);
	pass[i] = '\0';
	return pass;
}
//This function shows the user account menu and returns the account menu choice
char showAcctMenu()
{
	char choice = ' ';

	cout; //colorchange
	cout << "\n\n\t\t\t     ACCOUNT SETTINGS MENU\n\n";
	cout << "\t\t\t    1 -- Create New Account\n";
	cout << "\t\t\t    2 -- Edit Existing Account\n";
	cout << "\t\t\t    3 -- Delete Existing Account\n";
	cout << "\t\t\t    4 -- Show Existing Accounts\n";
	cout << "\t\t\t    5 -- Return to Main Menu\n\n";
	cout << "\t\t\t      Enter 1, 2, 3, 4 or 5: ";

	cin >> choice;
	if (choice == 0)
	{
		while (choice == 0)
		{

			system("cls");
			showLogo();
			cout << "\t\t      WARNING!!!  Num Lock is turned off."; //colorchange
			cout << "\a";


			cout << "\n\n\t\t\t     ACCOUNT SETTINGS MENU\n\n";
			cout << "\t\t\t    1 -- Create New Account\n";
			cout << "\t\t\t    2 -- Edit Existing Account\n";
			cout << "\t\t\t    3 -- Delete Existing Account\n";
			cout << "\t\t\t    4 -- Show Existing Accounts\n";
			cout << "\t\t\t    5 -- Return to Main Menu\n\n";
			cout << "\t\t\t      Enter 1, 2, 3, 4 or 5: ";
			cin >> choice;
		}
	}

	if (choice == '1')
		return choice;
	if (choice == '2')
		return choice;
	if (choice == '3')
		return choice;
	if (choice == '4')
		return choice;
	if (choice == '5')
		return choice;

}

//this function lists all user names in the player array
void showUsers(UserAcct player[], char& choice, int count)
{
	system("cls");
	cout << "\n\n\t\t\t     EXISTING USER ACCOUNTS\n\n";
	cout << "\n";
	cout << "\t\t\tWin Percent\t\tUser Name\n\n";

	for (int index = 1; index < count; index++)
	{
		cout << "\t\t\t  " << player[index].winPercent << "%\t\t" << player[index].userName << endl;
	}

	cout << endl;
	system("pause");

	system("cls");
	showLogo();

	choice = showAcctMenu();
}

void editAcct(fstream& userData, UserAcct player[], char& choice, int& count)
{
	//declare variables
	int
		index = 0,
		user,
		spaceFound = -1;
	bool
		valid = false,
		found = false;
	string
		uName,
		pWord,
		fName,
		password1,
		password2,
		confirm = "NO";
	char   editChoice;

	system("cls");
	showLogo();
	cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
	cout << "\nPlease enter a user name that you want to edit: ";
	cin >> uName;

	for (index; index < count; index++)
	{
		if (uName == player[index].userName)
		{
			found = true;
			user = index;
		}
	}

	if (found)
	{
		system("cls");
		showLogo();
		cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
		cout << "\nPlease enter your password:";
		pWord = getPass(PASSWORD_WIDTH);

		if (pWord == player[user].password)
		{
			valid = true;

			system("cls");
			showLogo();
			fName = player[user].firstName;

			//display the entered data (hiding the password)
			cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
			cout << "User found.\n\n";
			cout << "Username:\t" << player[user].userName << endl;
			cout << "Password:\t[***************]" << endl;
			cout << "First name:\t" << player[user].firstName << endl << endl;
			cout << "Enter \"1\" to change the password for this account.\n";
			cout << "Enter \"2\" to return to the account settings menu.\n";
			cin >> editChoice;

			while (editChoice != '2')
			{
				switch (editChoice)
				{
				case '1':	//edit password
					system("cls");
					showLogo();

					cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
					cout << "Editing password.\n\n";
					cout << "\nEnter your password (15 characters or less): ";
					password1 = getPass(PASSWORD_WIDTH);

					//checking for spaces in the password
					spaceFound = password1.find(" ", 0);

					while (spaceFound != -1)
					{
						system("cls");
						showLogo();
						cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n";
						cout << "\nYou cannot have spaces in your password."; //colorchange
						cout << "\nEnter your password (15 characters or less): ";
						cout << "\a";
						password1 = getPass(PASSWORD_WIDTH);
						spaceFound = -1;
						spaceFound = password1.find(" ", 0);
					}

					//verifying password
					system("cls");
					showLogo();
					cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
					cout << "\nPlease re-enter your password: ";
					password2 = getPass(PASSWORD_WIDTH);
					system("cls");
					showLogo();

					//if the password was not entered the same between the first and
					//second time it was entered, give the user another chance to
					//correctly enter a password
					while (password1 != password2)
					{
						cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n";
						cout << "\nPasswords did not match!"; //colorchange
						cout << "\nPlease enter your password (15 characters of less): ";
						cout << "\a";
						password1 = getPass(PASSWORD_WIDTH);
						//checking for spaces in the user name
						spaceFound = password1.find(" ", 0);

						while (spaceFound != -1)
						{
							system("cls");
							showLogo();
							cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n";
							cout << "\nYou cannot have spaces in your password."; //colorchange
							cout << "\nEnter your password (15 characters or less): ";
							cout << "\a";
							password1 = getPass(PASSWORD_WIDTH);
							spaceFound = -1;
							spaceFound = password1.find(" ", 0);
						}

						//verifying password
						system("cls");
						showLogo();
						cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
						cout << "\nPlease re-enter your password: ";
						password2 = getPass(PASSWORD_WIDTH);
						system("cls");
						showLogo();

						//confirm change to password
						cout << "Are you sure you want to change this password?\n\n";
						cout << "Enter \"" << "YES" << "\" to confirm or anything else to keep user.\n"; //colorchange
						cin >> confirm;


						if (confirm == "YES")
						{
							system("cls");
							showLogo();
							cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
							cout << "Editing user account...\n\n"; //colorchange
							cout << "Username:\t" << player[user].userName << endl;
							cout << "Password:\t[***************]" << endl;
							cout << "First name:\t" << player[user].firstName << endl << endl;

							//opening the userData file in output mode
							userData.open("playerdata.dat", ios::out);

							//writing player array before the element to be edited to the file
							for (int index = 0; index < user; index++)
							{

								//write the computer user to the userData file
								userData << player[index].userName << "\n";
								userData << player[index].password << "\n";
								userData << player[index].firstName << "\n";
								userData << player[index].wins << "\n";
								userData << player[index].losses << "\n";
								userData << player[index].winPercent << "\n";

							}

							//writing player to be edited to the file
							userData << player[user].userName << "\n";
							userData << password1 << "\n";
							userData << player[user].firstName << "\n";
							userData << player[user].wins << "\n";
							userData << player[user].losses << "\n";
							userData << player[user].winPercent << "\n";


							//writing player array after the element to be edited to the file
							for (int index = user + 1; index < count; index++)
							{

								//write the computer user to the userData file
								userData << player[index].userName << "\n";
								userData << player[index].password << "\n";
								userData << player[index].firstName << "\n";
								userData << player[index].wins << "\n";
								userData << player[index].losses << "\n";
								userData << player[index].winPercent << "\n";
							}

							//closing the data file
							userData.close();

							//reopen the data file to reload the player array
							userData.open("playerdata.dat", ios::in);

							//reloading the userData file into the player array
							count = 0;					//resetting the count variable

							//read first player into player array
							getline(userData, player[count].userName);
							getline(userData, player[count].password);
							getline(userData, player[count].firstName);
							userData >> player[count].wins;
							userData >> player[count].losses;
							userData >> player[count].winPercent;

							count++;

							//while more players exist in the userData file,
							//continue reading players into the player array
							while (userData >> player[count].userName)
							{
								userData >> player[count].password;
								userData >> player[count].firstName;
								userData >> player[count].wins;
								userData >> player[count].losses;
								userData >> player[count].winPercent;

								count++;

							}

							//closing the data file
							userData.close();

							//call back to edit menu


							cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
							cout << "User found.\n\n";
							cout << "Username:\t" << player[user].userName << endl;
							cout << "Password:\t[***************]" << endl;
							cout << "First name:\t" << player[user].firstName << endl << endl;
							cout << "Enter \"1\" to change the password for this account.\n";
							cout << "Enter \"2\" to return to the account settings menu.\n";
							cin >> editChoice;


						}
						else
						{
							if (user > 0)
							{
								system("cls");
								showLogo();
								cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
								cout << "NOT" << " editing user account.\n\n"; //colorchange								cout << "Username:\t" << player[user].userName << endl;
								cout << "Password:\t[***************]" << endl;
								cout << "First name:\t" << player[user].firstName << endl << endl;
							}

							//call back to edit menu


							cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
							cout << "User found.\n\n";
							cout << "Username:\t" << player[user].userName << endl;
							cout << "Password:\t[***************]" << endl;
							cout << "First name:\t" << player[user].firstName << endl << endl;
							cout << "Enter \"1\" to change the password for this account.\n";
							cout << "Enter \"2\" to return to the account settings menu.\n";
							cin >> editChoice;

						}

						break;
				default:
					system("cls");
					showLogo();

					cout << "\t\t      You have entered an invalid choice.\n"; //colorchange
					cout << "\a";
					cout << "\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
					cout << "User found.\n\n";
					cout << "Username:\t" << player[user].userName << endl;
					cout << "Password:\t[***************]" << endl;
					cout << "First name:\t" << player[user].firstName << endl << endl;
					cout << "Enter \"1\" to change the password for this account.\n";
					cout << "Enter \"2\" to return to the account settings menu.\n";
					cin >> editChoice;

					}
				}

				//confirm change to password
				cout << "Are you sure you want to change this password?\n\n";
				cout << "Enter \"" << "YES" << "\" to confirm or anything else to keep user.\n";
				cin >> confirm;


				if (confirm == "YES")
				{
					system("cls");
					showLogo();
					cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
					cout << "Editing user account...\n\n"; //colorchange
					cout << "Username:\t" << player[user].userName << endl;
					cout << "Password:\t[***************]" << endl;
					cout << "First name:\t" << player[user].firstName << endl << endl;

					//opening the userData file in output mode
					userData.open("playerdata.dat", ios::out);
					//writing player array before the element to be edited to the file
					for (int index = 0; index < user; index++)
					{
						//write the computer user to the userData file
						userData << player[index].userName << "\n";
						userData << player[index].password << "\n";
						userData << player[index].firstName << "\n";
						userData << player[index].wins << "\n";
						userData << player[index].losses << "\n";
						userData << player[index].winPercent << "\n";

					}

					//writing player to be edited to the file
					userData << player[user].userName << "\n";
					userData << password1 << "\n";
					userData << player[user].firstName << "\n";
					userData << player[user].wins << "\n";
					userData << player[user].losses << "\n";
					userData << player[user].winPercent << "\n";


					//writing player array after the element to be edited to the file
					for (int index = user + 1; index < count; index++)
					{

						//write the computer user to the userData file
						userData << player[index].userName << "\n";
						userData << player[index].password << "\n";
						userData << player[index].firstName << "\n";
						userData << player[index].wins << "\n";
						userData << player[index].losses << "\n";
						userData << player[index].winPercent << "\n";
					}

					//closing the data file
					userData.close();

					//reopen the data file to reload the player array
					userData.open("playerdata.dat", ios::in);

					//reloading the userData file into the player array
					count = 0;					//resetting the count variable

					//read first player into player array
					getline(userData, player[count].userName);
					getline(userData, player[count].password);
					getline(userData, player[count].firstName);
					userData >> player[count].wins;
					userData >> player[count].losses;
					userData >> player[count].winPercent;

					count++;

					//while more players exist in the userData file,
					//continue reading players into the player array
					while (userData >> player[count].userName)
					{
						userData >> player[count].password;
						userData >> player[count].firstName;
						userData >> player[count].wins;
						userData >> player[count].losses;
						userData >> player[count].winPercent;

						count++;

					}

					//closing the data file
					userData.close();

					//call back to edit menu


					system("cls");
					showLogo();
					cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
					cout << "User found.\n\n";
					cout << "Username:\t" << player[user].userName << endl;
					cout << "Password:\t[***************]" << endl;
					cout << "First name:\t" << player[user].firstName << endl << endl;
					cout << "Enter \"1\" to change the password for this account.\n";
					cout << "Enter \"2\" to return to the account settings menu.\n";
					cin >> editChoice;


				}
				else
				{
					if (user > 0)
					{
						system("cls");
						showLogo();
						cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
						cout << "NOT" << " editing user account.\n\n"; //colorchange										cout << "Username:\t" << player[user].userName << endl;
						cout << "Password:\t[***************]" << endl;
						cout << "First name:\t" << player[user].firstName << endl << endl;
					}

					//call back to edit menu



					system("cls");
					showLogo();
					cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
					cout << "User found.\n\n";
					cout << "Username:\t" << player[user].userName << endl;
					cout << "Password:\t[***************]" << endl;
					cout << "First name:\t" << player[user].firstName << endl << endl;
					cout << "Enter \"1\" to change the password for this account.\n";
					cout << "Enter \"2\" to return to the account settings menu.\n";
					cin >> editChoice;

				}

			}


		}
		else
		{
			system("cls");
			showLogo();
			int attempts = 1;
			while (attempts <= 3 && !(valid))
			{
				cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
				cout << "The password was incorrect.\n" << "Please re-enter password: "; //colorchange
				cout << "\a";
				pWord = getPass(PASSWORD_WIDTH);
				attempts++;
				if (pWord == player[user].password)
				{
					valid = true;

					system("cls");
					showLogo();
					fName = player[user].firstName;

					//display the entered data (hiding the password)
					cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
					cout << "User found.\n\n";
					cout << "Username:\t" << player[user].userName << endl;
					cout << "Password:\t[***************]" << endl;
					cout << "First name:\t" << player[user].firstName << endl << endl;
					cout << "Enter \"1\" to change the password for this account.\n";
					cout << "Enter \"2\" to return to the account settings menu.\n";
					cin >> editChoice;

					while (editChoice != '2')
					{
						switch (editChoice)
						{
						case '1':	//edit password
							system("cls");
							showLogo();

							cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
							cout << "Editing password.\n\n";
							cout << "\nEnter your password (15 characters or less): ";
							password1 = getPass(PASSWORD_WIDTH);


							//checking for spaces in the password
							spaceFound = password1.find(" ", 0);

							while (spaceFound != -1)
							{
								system("cls");
								showLogo();
								cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n";
								cout << "\nYou cannot have spaces in your password."; //colorchange
								cout << "\nEnter your password (15 characters or less): ";
								cout << "\a";
								password1 = getPass(PASSWORD_WIDTH);
								spaceFound = -1;
								spaceFound = password1.find(" ", 0);
							}

							//verifying password
							system("cls");
							showLogo();
							cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
							cout << "\nPlease re-enter your password: ";
							password2 = getPass(PASSWORD_WIDTH);
							system("cls");
							showLogo();

							//if the password was not entered the same between the first and
							//second time it was entered, give the user another chance to
							//correctly enter a password
							while (password1 != password2)
							{
								system("cls");
								showLogo();
								cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n";
								cout << "\nPasswords did not match!"; //colorchange
								cout << "\nPlease enter your password (15 characters of less): ";
								cout << "\a";
								password1 = getPass(PASSWORD_WIDTH);
								//checking for spaces in the user name
								spaceFound = password1.find(" ", 0);

								while (spaceFound != -1)
								{
									system("cls");
									showLogo();
									cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n";
									cout << "\nYou cannot have spaces in your password."; //colorchange
									cout << "\nEnter your password (15 characters or less): ";
									cout << "\a";
									password1 = getPass(PASSWORD_WIDTH);
									spaceFound = -1;
									spaceFound = password1.find(" ", 0);
								}

								//verifying password
								system("cls");
								showLogo();
								cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
								cout << "\nPlease re-enter your password: ";
								password2 = getPass(PASSWORD_WIDTH);
								system("cls");
								showLogo();

								//confirm change to password
								cout << "Are you sure you want to change this password?\n\n";
								cout << "Enter \"" << "YES" << "\" to confirm or anything else to keep user.\n"; //colorchange
								cin >> confirm;


								if (confirm == "YES")
								{
									system("cls");
									showLogo();
									cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
									cout << "Editing user account...\n\n"; //colorchange
									cout << "Username:\t" << player[user].userName << endl;
									cout << "Password:\t[***************]" << endl;
									cout << "First name:\t" << player[user].firstName << endl << endl;

									//opening the userData file in output mode
									userData.open("playerdata.dat", ios::out);

									//writing player array before the element to be edited to the file
									for (int index = 0; index < user; index++)
									{

										//write the computer user to the userData file
										userData << player[index].userName << "\n";
										userData << player[index].password << "\n";
										userData << player[index].firstName << "\n";
										userData << player[index].wins << "\n";
										userData << player[index].losses << "\n";
										userData << player[index].winPercent << "\n";

									}

									//writing player to be edited to the file
									userData << player[user].userName << "\n";
									userData << password1 << "\n";
									userData << player[user].firstName << "\n";
									userData << player[user].wins << "\n";
									userData << player[user].losses << "\n";
									userData << player[user].winPercent << "\n";


									//writing player array after the element to be edited to the file
									for (int index = user + 1; index < count; index++)
									{

										//write the computer user to the userData file
										userData << player[index].userName << "\n";
										userData << player[index].password << "\n";
										userData << player[index].firstName << "\n";
										userData << player[index].wins << "\n";
										userData << player[index].losses << "\n";
										userData << player[index].winPercent << "\n";
									}

									//closing the data file
									userData.close();

									//reopen the data file to reload the player array
									userData.open("playerdata.dat", ios::in);

									//reloading the userData file into the player array
									count = 0;					//resetting the count variable

									//read first player into player array
									getline(userData, player[count].userName);
									getline(userData, player[count].password);
									getline(userData, player[count].firstName);
									userData >> player[count].wins;
									userData >> player[count].losses;
									userData >> player[count].winPercent;

									count++;

									//while more players exist in the userData file,
									//continue reading players into the player array
									while (userData >> player[count].userName)
									{
										userData >> player[count].password;
										userData >> player[count].firstName;
										userData >> player[count].wins;
										userData >> player[count].losses;
										userData >> player[count].winPercent;

										count++;

									}

									//closing the data file
									userData.close();

									//call back to edit menu


									system("cls");
									showLogo();
									cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
									cout << "User found.\n\n";
									cout << "Username:\t" << player[user].userName << endl;
									cout << "Password:\t[***************]" << endl;
									cout << "First name:\t" << player[user].firstName << endl << endl;
									cout << "Enter \"1\" to change the password for this account.\n";
									cout << "Enter \"2\" to return to the account settings menu.\n";
									cin >> editChoice;


								}
								else
								{
									if (user > 0)
									{
										system("cls");
										showLogo();
										cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
										cout << "NOT" << " editing user account.\n\n";	//colorchange									cout << "Username:\t" << player[user].userName << endl;
										cout << "Password:\t[***************]" << endl;
										cout << "First name:\t" << player[user].firstName << endl << endl;
									}

									//call back to edit menu


									system("cls");
									showLogo();
									cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
									cout << "User found.\n\n";
									cout << "Username:\t" << player[user].userName << endl;
									cout << "Password:\t[***************]" << endl;
									cout << "First name:\t" << player[user].firstName << endl << endl;
									cout << "Enter \"1\" to change the password for this account.\n";
									cout << "Enter \"2\" to return to the account settings menu.\n";
									cin >> editChoice;

								}

								//						}

								break;
						default:
							system("cls");
							showLogo();

							cout << "\t\t      You have entered an invalid choice.\n"; //colorchange
							cout << "\a";
							cout << "\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
							cout << "User found.\n\n";
							cout << "Username:\t" << player[user].userName << endl;
							cout << "Password:\t[***************]" << endl;
							cout << "First name:\t" << player[user].firstName << endl << endl;
							cout << "Enter \"1\" to change the password for this account.\n";
							cout << "Enter \"2\" to return to the account settings menu.\n";
							cin >> editChoice;

							}
						}

						//confirm change to password
						cout << "Are you sure you want to change this password?\n\n";
						cout << "Enter \"" << "YES" << "\" to confirm or anything else to keep user.\n"; //colorchange
						cin >> confirm;


						if (confirm == "YES")
						{
							system("cls");
							showLogo();
							cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
							cout << "Editing user account...\n\n"; //colorchange
							cout << "Username:\t" << player[user].userName << endl;
							cout << "Password:\t[***************]" << endl;
							cout << "First name:\t" << player[user].firstName << endl << endl;

							//opening the userData file in output mode
							userData.open("playerdata.dat", ios::out);
							//writing player array before the element to be edited to the file
							for (int index = 0; index < user; index++)
							{
								//write the computer user to the userData file
								userData << player[index].userName << "\n";
								userData << player[index].password << "\n";
								userData << player[index].firstName << "\n";
								userData << player[index].wins << "\n";
								userData << player[index].losses << "\n";
								userData << player[index].winPercent << "\n";

							}

							//writing player to be edited to the file
							userData << player[user].userName << "\n";
							userData << password1 << "\n";
							userData << player[user].firstName << "\n";
							userData << player[user].wins << "\n";
							userData << player[user].losses << "\n";
							userData << player[user].winPercent << "\n";


							//writing player array after the element to be edited to the file
							for (int index = user + 1; index < count; index++)
							{

								//write the computer user to the userData file
								userData << player[index].userName << "\n";
								userData << player[index].password << "\n";
								userData << player[index].firstName << "\n";
								userData << player[index].wins << "\n";
								userData << player[index].losses << "\n";
								userData << player[index].winPercent << "\n";
							}

							//closing the data file
							userData.close();

							//reopen the data file to reload the player array
							userData.open("playerdata.dat", ios::in);

							//reloading the userData file into the player array
							count = 0;					//resetting the count variable

							//read first player into player array
							getline(userData, player[count].userName);
							getline(userData, player[count].password);
							getline(userData, player[count].firstName);
							userData >> player[count].wins;
							userData >> player[count].losses;
							userData >> player[count].winPercent;

							count++;

							//while more players exist in the userData file,
							//continue reading players into the player array
							while (userData >> player[count].userName)
							{
								userData >> player[count].password;
								userData >> player[count].firstName;
								userData >> player[count].wins;
								userData >> player[count].losses;
								userData >> player[count].winPercent;

								count++;

							}

							//closing the data file
							userData.close();

							//call back to edit menu


							system("cls");
							showLogo();
							cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
							cout << "User found.\n\n";
							cout << "Username:\t" << player[user].userName << endl;
							cout << "Password:\t[***************]" << endl;
							cout << "First name:\t" << player[user].firstName << endl << endl;
							cout << "Enter \"1\" to change the password for this account.\n";
							cout << "Enter \"2\" to return to the account settings menu.\n";
							cin >> editChoice;


						}
						else
						{
							if (user > 0)
							{
								system("cls");
								showLogo();
								cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
								cout << "NOT" << " editing user account.\n\n";	//colorchange									cout << "Username:\t" << player[user].userName << endl;
								cout << "Password:\t[***************]" << endl;
								cout << "First name:\t" << player[user].firstName << endl << endl;
							}

							//call back to edit menu



							system("cls");
							showLogo();
							cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
							cout << "User found.\n\n";
							cout << "Username:\t" << player[user].userName << endl;
							cout << "Password:\t[***************]" << endl;
							cout << "First name:\t" << player[user].firstName << endl << endl;
							cout << "Enter \"1\" to change the password for this account.\n";
							cout << "Enter \"2\" to return to the account settings menu.\n";
							cin >> editChoice;

						}

					}


				}
				else
				{
					system("cls");
					showLogo();

					if (attempts > 3)
					{
						system("cls");
						showLogo();
						cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
						cout << "\nUser could not be validated.\n\n"; //colorchange
						cout << "\a";
						user = -1;
					}
				}
			}
		}

	}
	else
	{
		system("cls");
		showLogo();
		cout << "\n\n\t\t\t    EDIT EXISTING ACCOUNT\n\n";
		cout << "\nThat user name cannot be found!\n\n"; //colorchange
		cout << "\a";
		user = -1;
	}


	cout << "Returning to Account Settings Menu....";

	system("cls");
	showLogo();

	choice = showAcctMenu();
}
void deleteAcct(fstream& userData, UserAcct player[], char& choice, int& count)
{
	//declare variables
	int	   index = 0,
		user;
	bool   valid = false,
		found = false;
	string uName,
		pWord,
		fName,
		confirm = "NO";

	system("cls");
	showLogo();
	cout << "\n\n\t\t\t   DELETE EXISTING ACCOUNT\n\n";
	cout << "\nPlease enter a user name that you want to delete: ";
	cin >> uName;

	for (index; index < count; index++)
	{
		if (uName == player[index].userName)
		{
			found = true;
			user = index;
		}
	}

	if (found)
	{
		system("cls");
		showLogo();
		cout << "\n\n\t\t\t   DELETE EXISTING ACCOUNT\n\n";
		cout << "\nPlease enter your password:";
		pWord = getPass(PASSWORD_WIDTH);

		if (pWord == player[user].password)
		{
			valid = true;

			system("cls");
			showLogo();
			fName = player[user].firstName;

			//display the entered data (hiding the password)
			cout << "\n\n\t\t\t   DELETE EXISTING ACCOUNT\n\n";
			cout << "User found.\n\n";
			cout << "Username:\t" << player[user].userName << endl;
			cout << "Password:\t[***************]" << endl;
			cout << "First name:\t" << player[user].firstName << endl << endl;
			cout << "Are you sure you want to delete this user?\n";
			cout << "This cannot be undone.\n\n";
			cout << "Enter \"" << "YES" << "\" to confirm or anything else to keep user.\n"; //colorchange
			cin >> confirm;
		}
		else
		{
			system("cls");
			showLogo();
			int attempts = 1;
			while (attempts <= 3 && !(valid))
			{
				cout << "\n\n\t\t\t   DELETE EXISTING ACCOUNT\n\n";
				cout << "The password was incorrect.\nPlease re-enter password: "; //colorchange
				cout << "\a";
				pWord = getPass(PASSWORD_WIDTH);
				attempts++;
				if (pWord == player[user].password)
				{
					valid = true;
					system("cls");
					showLogo();
					fName = player[user].firstName;

					//display the entered data (hiding the password)
					cout << "\n\n\t\t\t   DELETE EXISTING ACCOUNT\n\n";
					cout << "User found.\n\n";
					cout << "Username:\t" << player[user].userName << endl;
					cout << "Password:\t[***************]" << endl;
					cout << "First name:\t" << player[user].firstName << endl << endl;
					cout << "Are you sure you want to delete this user?\n";
					cout << "This cannot be undone.\n\n";
					cout << "Enter \"" << "YES" << "\" to confirm or anything else to keep user.\n";
					cin >> confirm;
				}
				else
				{
					system("cls");
					showLogo();

					if (attempts > 3)
					{
						system("cls");
						showLogo();
						cout << "\n\n\t\t\t   DELETE EXISTING ACCOUNT\n\n";
						cout << "\nUser could not be validated.\n\n"; //colorchange
						cout << "\a";
						user = -1;
					}
				}
			}
		}

	}
	else
	{
		system("cls");
		showLogo();
		cout << "\n\n\t\t\t   DELETE EXISTING ACCOUNT\n\n";
		cout << "\nThat user name cannot be found!\n\n"; //colorchange
		cout << "\a";
		user = -1;
	}

	if (confirm == "YES")
	{
		system("cls");
		showLogo();
		cout << "\n\n\t\t\t   DELETE EXISTING ACCOUNT\n\n";
		cout << "Deleting user account...\n\n"; //colorchange
		cout << "Username:\t" << player[user].userName << endl;
		cout << "Password:\t[***************]" << endl;
		cout << "First name:\t" << player[user].firstName << endl << endl;

		//trying something different
		player[user].userName = "qwertyuioplmnbvcxzasdfghjk";

		//opening the userData file in output mode
		userData.open("playerdata.dat", ios::out);

		//writing player array before the element to be deleted to the file
		for (int index = 0; index < user; index++)
		{

			//write the computer user to the userData file
			userData << player[index].userName << "\n";
			userData << player[index].password << "\n";
			userData << player[index].firstName << "\n";
			userData << player[index].wins << "\n";
			userData << player[index].losses << "\n";
			userData << player[index].winPercent << "\n";

		}

		//writing player array after the element to be deleted to the file
		for (int index = user + 1; index < count; index++)
		{

			//write the computer user to the userData file
			userData << player[index].userName << "\n";
			userData << player[index].password << "\n";
			userData << player[index].firstName << "\n";
			userData << player[index].wins << "\n";
			userData << player[index].losses << "\n";
			userData << player[index].winPercent << "\n";
		}

		//closing the data file
		userData.close();

		//reopen the data file to reload the player array
		userData.open("playerdata.dat", ios::in);

		//reloading the userData file into the player array
		count = 0;					//resetting the count variable

		//read first player into player array
		getline(userData, player[count].userName);
		getline(userData, player[count].password);
		getline(userData, player[count].firstName);
		userData >> player[count].wins;
		userData >> player[count].losses;
		userData >> player[count].winPercent;

		count++;

		//while more players exist in the userData file,
		//continue reading players into the player array
		while (userData >> player[count].userName)
		{
			userData >> player[count].password;
			userData >> player[count].firstName;
			userData >> player[count].wins;
			userData >> player[count].losses;
			userData >> player[count].winPercent;

			count++;

		}

		//closing the data file
		userData.close();

	}
	else
	{
		if (user > 0)
		{
			system("cls");
			showLogo();
			cout << "\n\n\t\t\t   DELETE EXISTING ACCOUNT\n\n";
			cout << "NOT" << " deleting user account.\n\n"; //colorchange
			cout << "Username:\t" << player[user].userName << endl;
			cout << "Password:\t[***************]" << endl;
			cout << "First name:\t" << player[user].firstName << endl << endl;
		}
	}

	cout << "Returning to Account Settings Menu....";

	system("cls");
	showLogo();

	choice = showAcctMenu();
}

//this function creates a new entry in the userData file
void createNewAcct(fstream& userData, UserAcct player[], char& choice, int& count)
{
	//variable declarations
	string uName, password1, password2, fName;
	char saveUser;							//variable to trigger writing new account to file
	bool userExists;						//variable to check if a newly entered user already exists
	int spaceFound = -1;

	system("cls");
	showLogo();
	if (count < ARRAY_SIZE)
	{
		//opening the userData file in input/output/append mode
		userData.open("playerdata.dat", ios::in | ios::out | ios::app);

		//prompting for a new user name
		cout << "\n\n\t\t\t    CREATE NEW ACCOUNT\n\n";
		cout << "\nEnter your user name: ";
		getline(cin, uName);

		//checking for spaces in the user name
		spaceFound = uName.find(" ", 0);

		while (spaceFound != -1)
		{
			system("cls");
			showLogo();
			cout << "\n\n\t\t\t    CREATE NEW ACCOUNT\n";
			cout << "\nYou cannot have spaces in your user name."; //colorchange
			cout << "\nEnter your user name: ";
			cout << "\a";
			getline(cin, uName);
			spaceFound = -1;
			spaceFound = uName.find(" ", 0);
		}

		system("cls");
		showLogo();
		userExists = userCheck(player, uName, count);

		//if the user name that was entered is already in use by aother
		//user, give the user another chance to enter a new user name
		while (userExists)
		{
			cout << "\n\n\t\t\t    CREATE NEW ACCOUNT\n";
			cout << "\nThat user name already exists, please choose another name."; //colorchange
			cout << "\nEnter your user name: ";
			cout << "\a";
			getline(cin, uName);

			//checking for spaces in the user name
			spaceFound = uName.find(" ", 0);

			while (spaceFound != -1)
			{
				system("cls");
				showLogo();
				cout << "\n\n\t\t\t    CREATE NEW ACCOUNT\n";
				cout << "\nYou cannot have spaces in your user name."; //colorchange
				cout << "\nEnter your user name: ";
				getline(cin, uName);
				spaceFound = -1;
				spaceFound = uName.find(" ", 0);
			}
			system("cls");
			showLogo();
			userExists = userCheck(player, uName, count);
		}

		//prompting for a password
		cout << "\n\n\t\t\t    CREATE NEW ACCOUNT\n\n";
		cout << "\nEnter your password (15 characters or less): ";
		password1 = getPass(PASSWORD_WIDTH);


		//checking for spaces in the password
		spaceFound = password1.find(" ", 0);
		while (spaceFound != -1)
		{
			system("cls");
			showLogo();
			cout << "\n\n\t\t\t    CREATE NEW ACCOUNT\n";
			cout << "\nYou cannot have spaces in your password."; //colorchange
			cout << "\nEnter your password (15 characters or less): ";
			cout << "\a";
			password1 = getPass(PASSWORD_WIDTH);
			spaceFound = -1;
			spaceFound = password1.find(" ", 0);
		}

		//verifying password
		system("cls");
		showLogo();
		cout << "\n\n\t\t\t    CREATE NEW ACCOUNT\n\n";
		cout << "\nPlease re-enter your password: ";
		password2 = getPass(PASSWORD_WIDTH);
		system("cls");
		showLogo();

		//if the password was not entered the same between the first and second time. One more try for user
		while (password1 != password2)
		{
			cout << "\n\n\t\t\t    CREATE NEW ACCOUNT\n";
			cout << "\nPasswords did not match!"; //colorchange
			cout << "\nPlease enter your password (15 characters of less): ";
			cout << "\a";
			password1 = getPass(PASSWORD_WIDTH);
			//checking for spaces in the user name
			spaceFound = password1.find(" ", 0);

			while (spaceFound != -1)
			{
				system("cls");
				showLogo();
				cout << "\n\n\t\t\t    CREATE NEW ACCOUNT\n";
				cout << "\nYou cannot have spaces in your password."; //colorchange
				cout << "\nEnter your password (15 characters or less): ";
				cout << "\a";
				password1 = getPass(PASSWORD_WIDTH);
				spaceFound = -1;
				spaceFound = password1.find(" ", 0);
			}

			//verifying password
			system("cls");
			showLogo();
			cout << "\n\n\t\t\t    CREATE NEW ACCOUNT\n\n";
			cout << "\nPlease re-enter your password: ";
			password2 = getPass(PASSWORD_WIDTH);
			system("cls");
			showLogo();
		}

		//Requesting for name for being able to anounce whose turn it is and who won the game
		cout << "\n\n\t\t\t\tCREATE NEW ACCOUNT\n\n";
		cout << "\nEnter your display name: ";
		getline(cin, fName);

		//checking for spaces in the user name
		spaceFound = fName.find(" ", 0);

		while (spaceFound != -1)
		{
			system("cls");
			showLogo();
			cout << "\n\n\t\t\t    CREATE NEW ACCOUNT\n";
			cout << "\nYou cannot have spaces in your display name."; //colorchange
			cout << "\nEnter your display name: ";
			cout << "\a";
			getline(cin, fName);
			spaceFound = -1;
			spaceFound = fName.find(" ", 0);
		}

		system("cls");
		showLogo();

		//loading user info into player array
		player[count].userName = uName;
		player[count].password = password1;
		player[count].firstName = fName;
		player[count].wins = 0;
		player[count].losses = 0;
		if (player[count].wins == 0 && player[count].losses == 0)
			player[count].winPercent = 0.0;
		else
			player[count].winPercent = player[count].wins / ((double)player[count].wins + player[count].losses) * 100.0;

		//display the entered data (hiding the password)
		cout << "\n\n\t\t\t    CREATE NEW ACCOUNT\n\n";
		cout << "\nNew player information entered...\n\n";
		cout << "Username:\t" << player[count].userName << endl;
		cout << "Password:\t[***************]" << endl;
		cout << "First name:\t" << player[count].firstName;

		//saving the account ot no
		cout << "\n\n\nDo you want to save this account to file?\n";
		cout << "Enter \"Y\" for Yes or \"N\" for No: ";
		cin >> saveUser;

		while (toupper(saveUser) != 'Y' && toupper(saveUser) != 'N')
		{
			//display the entered data (hiding the password), again
			system("cls");
			showLogo();

			cout << "\n\n\t\t\t    CREATE NEW ACCOUNT\n\n";
			cout << "\nNew player information entered...\n\n";
			cout << "Username:\t" << player[count].userName << endl;
			cout << "Password:\t[***************]" << endl;
			cout << "First name:\t" << player[count].firstName;

			//write the new account to file or abandon changes to file, again
			cout << "\n\nInvalid selection!  You must enter only \"Y\" or \"N\"."; //colorchange
			cout << "\nDo you want to save this account to file?\n";
			cout << "Enter \"Y\" for Yes or \"N\" for No: ";
			cout << "\a";
			cin >> saveUser;
		}

		if (toupper(saveUser) == 'Y')
		{
			//write the computer user to the userData file
			userData << player[count].userName << "\n";
			userData << player[count].password << "\n";
			userData << player[count].firstName << "\n";
			userData << player[count].wins << "\n";
			userData << player[count].losses << "\n";
			userData << player[count].winPercent << "\n";

			//incrementing the count variable
			count++;

			//account written to file
			system("cls");
			showLogo();

			cout << "\n\n\t\t\t    CREATE NEW ACCOUNT\n\n";
			cout << "\nNew account written to file.\n";
			cout << "\nReturning to Account Settings Menu.";
		}
		else
		{
			//account abandonded
			system("cls");
			showLogo();

			cout << "\n\n\t\t\t    CREATE NEW ACCOUNT\n\n";
			cout << "\nNew account " << "NOT" << " written to file.\n"; //colorchange
			cout << "\nReturning to Account Settings Menu.";
		}


		userData.close();

		system("cls");
		showLogo();

		choice = showAcctMenu();
	}
	else
	{
		cout << "\n\n\n\n\n      I'm sorry, the maximum number of player accounts has been reached.\n";
		cout << "\t\t    Please delete a player to add another.\n\n\n\n\n\n";
		cout << "\a";
		system("pause");

		system("cls");
		showLogo();

		choice = showAcctMenu();
	}
}

void accountSettings(fstream& userData, UserAcct player[], char& mnChoice, int& count)
{
	char acctChoice;

	system("cls");
	showLogo();

	acctChoice = showAcctMenu();

	while (acctChoice != '5')
	{
		switch (acctChoice)
		{
		case '1':
			createNewAcct(userData, player, acctChoice, count);
			break;
		case '2':
			editAcct(userData, player, acctChoice, count);
			break;
		case '3':
			deleteAcct(userData, player, acctChoice, count);
			break;
		case '4':
			showUsers(player, acctChoice, count);
			break;
		default:
			system("cls");
			showLogo();

			cout << "\t\t      You have entered an invalid choice."; //colorchange
			cout << "\a";

			acctChoice = showAcctMenu();

		}


	}

	system("cls");
	showLogo();
	mnChoice = showMainMenu();
}

