#include <iostream>
#include <string>
#include <fstream> //https://www.youtube.com/watch?v=Iho2EdJgusQ Ya otsuda viuchila
#include <string.h>
#include <time.h>
#include "board.h"
#include "Functions.h"
#include "Account.h"

using namespace std;


const int ARRAY_SIZE = 100,
PASSWORD_WIDTH = 16,
ROWS = 9,
COLS = 9,
CARRIER_SIZE = 5,					//Aircraft Carriers are 5 spaces long
BATTLESHIP_SIZE = 4,				//Battleships are 4 spaces long
SUBMARINE_SIZE = 3,				    //Submarines are 3 spaces long
DESTROYER_SIZE = 3,				//Destroyers are 3 spaces long
PATROLBOAT_SIZE = 2;				//Patrol Boats are 2 spaces long


//this function receives an integer value from the player's game board array
//and returns the character to display on the game board during gameplay
char showHidden(int coordinate)
{
	if (coordinate == 0)
	{
		//colorchange blue
		return '-';
	}
	if (coordinate == 1)
	{
		//colorchange blue
		return '-';
	}
	if (coordinate == 2)
	{
		//colorchange blue
		return '-';
	}
	if (coordinate == 3)
	{
		//colorchange blue
		return '-';
	}
	if (coordinate == 4)
	{
		//colorchange blue
		return '-';
	}
	if (coordinate == 5)
	{
		//colorchange blue
		return '-';
	}
	if (coordinate == 100)
	{
		cout; //colorchange
		return 'O';
	}
	if (coordinate == 101)
	{
		cout;
		return 'X';
	}
	if (coordinate == 102)
	{
		cout;
		return 'X';
	}
	if (coordinate == 103)
	{
		cout;
		return 'X';
	}
	if (coordinate == 104)
	{
		cout;
		return 'X';
	}
	if (coordinate == 105)
	{
		cout;
		return 'X';
	}
}


//this function receives an integer value from the player's game board array
//and returns the character to display on the game board while placing the 
//ships
char showVisible(int coordinate)
{
	if (coordinate == 0)
	{
		//colorchange blue
		return '-';
	}
	if (coordinate == 1)
	{
		//colorchange gray
		return 'C';
	}
	if (coordinate == 2)
	{
		//colorchange gray
		return 'B';
	}
	if (coordinate == 3)
	{
		//colorchange gray
		return 'S';
	}
	if (coordinate == 4)
	{
		//colorchange gray
		return 'D';
	}
	if (coordinate == 5)
	{
		//colorchange gray
		return 'P';
	}
	if (coordinate == 100)
	{
		cout; //colorchange
		return 'O';
	}
	if (coordinate > 100)
	{
		cout;
		return 'X';
	}
}

//this function takes an integer value from the show board function
//and returns a string that shows the status of the players' ships
// between the game boards
string showNeutralGround(int rowNumber, int c1, int b1, int s1, int d1, int playerOne, int c2, int b2, int s2, int d2, int playerTwo)
{
	if (rowNumber == 0)
		return "        SHIPS:         ";
	if (rowNumber == 1)
		return "                       ";
	if (rowNumber == 2 && c1 == CARRIER_SIZE && c2 == CARRIER_SIZE)
		return "    X  CARRIER    X    ";
	if (rowNumber == 2 && c1 == CARRIER_SIZE && c2 < CARRIER_SIZE)
		return "    X  CARRIER         ";
	if (rowNumber == 2 && c1 < CARRIER_SIZE && c2 == CARRIER_SIZE)
		return "       CARRIER    X    ";
	if (rowNumber == 2 && c1 < CARRIER_SIZE && c2 < CARRIER_SIZE)
		return "       CARRIER         ";
	if (rowNumber == 3 && b1 == BATTLESHIP_SIZE && b2 == BATTLESHIP_SIZE)
		return "    X BATTLESHIP  X    ";
	if (rowNumber == 3 && b1 == BATTLESHIP_SIZE && b2 < BATTLESHIP_SIZE)
		return "    X BATTLESHIP       ";
	if (rowNumber == 3 && b1 < BATTLESHIP_SIZE && b2 == BATTLESHIP_SIZE)
		return "      BATTLESHIP  X    ";
	if (rowNumber == 3 && b1 < BATTLESHIP_SIZE && b2 < BATTLESHIP_SIZE)
		return "      BATTLESHIP       ";
	if (rowNumber == 4 && s1 == SUBMARINE_SIZE && s2 == SUBMARINE_SIZE)
		return "    X  SUBMARINE  X    ";
	if (rowNumber == 4 && s1 == SUBMARINE_SIZE && s2 < SUBMARINE_SIZE)
		return "    X  SUBMARINE       ";
	if (rowNumber == 4 && s1 < SUBMARINE_SIZE && s2 == SUBMARINE_SIZE)
		return "       SUBMARINE  X    ";
	if (rowNumber == 4 && s1 < SUBMARINE_SIZE && s2 < SUBMARINE_SIZE)
		return "       SUBMARINE       ";
	if (rowNumber == 5 && d1 == DESTROYER_SIZE && d2 == DESTROYER_SIZE)
		return "    X  DESTROYER  X    ";
	if (rowNumber == 5 && d1 == DESTROYER_SIZE && d2 < DESTROYER_SIZE)
		return "    X  DESTROYER       ";
	if (rowNumber == 5 && d1 < DESTROYER_SIZE && d2 == DESTROYER_SIZE)
		return "       DESTROYER  X    ";
	if (rowNumber == 5 && d1 < DESTROYER_SIZE && d2 < DESTROYER_SIZE)
		return "       DESTROYER       ";
	if (rowNumber == 6 && playerOne == PATROLBOAT_SIZE && playerTwo == PATROLBOAT_SIZE)
		return "    X PATROL BOAT X    ";
	if (rowNumber == 6 && playerOne == PATROLBOAT_SIZE && playerTwo < PATROLBOAT_SIZE)
		return "    X PATROL BOAT      ";
	if (rowNumber == 6 && playerOne < PATROLBOAT_SIZE && playerTwo == PATROLBOAT_SIZE)
		return "      PATROL BOAT X    ";
	if (rowNumber == 6 && playerOne < PATROLBOAT_SIZE && playerTwo < PATROLBOAT_SIZE)
		return "      PATROL BOAT      ";
	if (rowNumber == 7)
		return "                       ";
	if (rowNumber == 8)
		return "                       ";
}



//this function shows the game board
void showBoard(int playerOneBoard[][COLS], int playerTwoBoard[][COLS], bool hidePlayer1, bool hidePlayer2, string fName1, string fName2, int c1, int b1, int s1, int d1, int playerOne, int c2, int b2, int s2, int d2, int playerTwo)
{
	cout << "\t   " << fName1 << "\'s Field\t\t\t\t      " << fName2 << "\'s Field\n";
	cout << "\t   1 2 3 4 5 6 7 8 9                           1 2 3 4 5 6 7 8 9\n"; //colorchange
	cout << "\t  -------------------                        -------------------\n";
	for (int r = 0; r < ROWS; r++)
	{
		cout << "\t" << showRowLetter(r) << "| ";  //colorchange
		for (int c = 0; c < COLS; c++)
		{
			if (hidePlayer1)
				cout << showHidden(playerOneBoard[r][c]) << " "; //colorchange
			else
				cout << showVisible(playerOneBoard[r][c]) << " "; //colorchange
		}
		cout << showNeutralGround(r, c1, b1, s1, d1, playerOne, c2, b2, s2, d2, playerTwo) << showRowLetter(r) << "| "; //colorchange

		for (int c = 0; c < ROWS; c++)
		{
			if (hidePlayer2)
				cout << showHidden(playerTwoBoard[r][c]) << " "; //colorchange
			else
				cout << showVisible(playerTwoBoard[r][c]) << " "; //colorchange
		}
		cout << endl;
	}
	/*	cout << "\t    Player 1 Field                             Player 2 Field\n";
		cout << "\t   1 2 3 4 5 6 7 8 9                         1 2 3 4 5 6 7 8 9\n";
		cout << "\t  -------------------                       -------------------\n";
		cout << "\tA| - - - - O - - - -        SHIPS:        A| X - - - - - - - -\n";
		cout << "\tB| - - - - - - - - -                      B| X - - - - O - - -\n";
		cout << "\tC| - O - - - - - - -       CARRIER        C| O - - - - - - - -\n";
		cout << "\tD| - - - - O - - O -      BATTLESHIP      D| - - O - - - - - -\n";
		cout << "\tE| - - - - - - - - -       SUBMARINE  X   E| - - - - O - - - -\n";
		cout << "\tF| - - - - - - - - -       DESTROYER      F| - - - - - - O - -\n";
		cout << "\tG| - O - O - - - - -    X PATROL BOAT     G| - - - - - - - - -\n";
		cout << "\tH| O X O - - - O - -                      H| - - O X X X - - -\n";
		cout << "\tI| - X - - - - - - -                      I| - - - - - - - - -\n\n";*/
}


//this function gets the ship orientation
char getOrientation(int playerOneBoard[][COLS], int playerTwoBoard[][COLS], bool hidePlayer1, bool hidePlayer2,
	string fName1, string fName2, string shipName, int playerOneCarr, int playerOneBatt, int playerOneSub, int playerOneDes, int playerOnePat,
	int playerTwoCarr, int playerTwoBatt, int playerTwoSub, int playerTwoDes, int playerTwoPat)
{
	char orientation;

	system("cls");
	showLogo();
	showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
	cout << endl << "To place your " << shipName << " on the board.\n";
	cout << "Choose \"H\" for Horizontal or \"V\" for vertical: ";
	cin >> orientation;

	while (toupper(orientation) != 'H' && toupper(orientation) != 'V')
	{
		system("cls");
		showLogo();
		showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
			playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
		cout << "\nInvalid selection!  You must enter only \"H\" or \"V\"."; //colorchange
		cout << "\nTo place your " << shipName << " on the board,\n";
		cout << "Choose \"H\" for Horizontal or \"V\" for vertical: ";
		cout << "\a";
		cin >> orientation;
	}

	orientation = toupper(orientation);
	return orientation;
}



//this function gets the ship's beginning row location
char getRowLocation(int playerOneBoard[][COLS], int playerTwoBoard[][COLS], bool hidePlayer1, bool hidePlayer2, string fName1, string fName2, string shipName, char orient, int playerOneCarr, int playerOneBatt, int playerOneSub, int playerOneDes, int playerOnePat, int playerTwoCarr, int playerTwoBatt, int playerTwoSub, int playerTwoDes, int playerTwoPat)
{
	char rowLocation;

	if (shipName == "Carrier")
	{
		system("cls");
		showLogo();
		showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
			playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
		cout << endl << "To place your " << shipName << " on the board.\n";
		cout << "Choose a letter between \"A\" and \"I\": ";
		cin >> rowLocation;

		while (toupper(rowLocation) != 'A' && toupper(rowLocation) != 'B' && toupper(rowLocation) != 'C'
			&& toupper(rowLocation) != 'D' && toupper(rowLocation) != 'E' && toupper(rowLocation) != 'F'
			&& toupper(rowLocation) != 'G' && toupper(rowLocation) != 'H' && toupper(rowLocation) != 'I')
		{
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
			cout << "\nInvalid selection!  You must enter only \"A\" through \"I\"."; //colorchange
			cout << "\nTo place your " << shipName << " on the board,\n";
			cout << "Choose a letter between \"A\" and \"I\": ";
			cout << "\a";
			cin >> rowLocation;
		}

		rowLocation = toupper(rowLocation);
		return rowLocation;
	}

	if (shipName == "Battleship")
	{
		if (orient == 'H')
		{
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
			cout << endl << "To place your " << shipName << " on the board.\n";
			cout << "Choose a letter between \"A\" and \"I\": ";
			cin >> rowLocation;

			while (toupper(rowLocation) != 'A' && toupper(rowLocation) != 'B' && toupper(rowLocation) != 'C'
				&& toupper(rowLocation) != 'D' && toupper(rowLocation) != 'E' && toupper(rowLocation) != 'F'
				&& toupper(rowLocation) != 'G' && toupper(rowLocation) != 'H' && toupper(rowLocation) != 'I')
			{
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
					playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << "\nInvalid selection!  You must enter only \"A\" through \"I\"."; //colorchange
				cout << "\nTo place your " << shipName << " on the board,\n";
				cout << "Choose a letter between \"A\" and \"I\": ";
				cout << "\a";
				cin >> rowLocation;
			}

			rowLocation = toupper(rowLocation);
			return rowLocation;
		}
		else
		{
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
			cout << endl << "To place your " << shipName << " on the board.\n";
			cout << "Choose a letter between \"A\" and \"F\": ";
			cin >> rowLocation;

			while (toupper(rowLocation) != 'A' && toupper(rowLocation) != 'B' && toupper(rowLocation) != 'C'
				&& toupper(rowLocation) != 'D' && toupper(rowLocation) != 'E' && toupper(rowLocation) != 'F')
			{
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
					playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << "\nInvalid selection!  You must enter only \"A\" through \"F\"."; //colorchange
				cout << "\nTo place your " << shipName << " on the board,\n";
				cout << "Choose a letter between \"A\" and \"F\": ";
				cout << "\a";
				cin >> rowLocation;
			}

			rowLocation = toupper(rowLocation);
			return rowLocation;
		}
	}

	if (shipName == "Submarine")
	{
		if (orient == 'H')
		{
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
			cout << endl << "To place your " << shipName << " on the board.\n";
			cout << "Choose a letter between \"A\" and \"I\": ";
			cin >> rowLocation;

			while (toupper(rowLocation) != 'A' && toupper(rowLocation) != 'B' && toupper(rowLocation) != 'C'
				&& toupper(rowLocation) != 'D' && toupper(rowLocation) != 'E' && toupper(rowLocation) != 'F'
				&& toupper(rowLocation) != 'G' && toupper(rowLocation) != 'H' && toupper(rowLocation) != 'I')
			{
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
					playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << "\nInvalid selection!  You must enter only \"A\" through \"I\"."; //colorchange
				cout << "\nTo place your " << shipName << " on the board,\n";
				cout << "Choose a letter between \"A\" and \"I\": ";
				cout << "\a";
				cin >> rowLocation;
			}

			rowLocation = toupper(rowLocation);
			return rowLocation;
		}
		else
		{
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
			cout << endl << "To place your " << shipName << " on the board.\n";
			cout << "Choose a letter between \"A\" and \"G\": ";
			cin >> rowLocation;

			while (toupper(rowLocation) != 'A' && toupper(rowLocation) != 'B' && toupper(rowLocation) != 'C'
				&& toupper(rowLocation) != 'D' && toupper(rowLocation) != 'E' && toupper(rowLocation) != 'F'
				&& toupper(rowLocation) != 'G')
			{
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
					playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << "\nInvalid selection!  You must enter only \"A\" through \"G\"."; //colorchange
				cout << "\nTo place your " << shipName << " on the board,\n";
				cout << "Choose a letter between \"A\" and \"G\": ";
				cout << "\a";
				cin >> rowLocation;
			}

			rowLocation = toupper(rowLocation);
			return rowLocation;
		}
	}

	if (shipName == "Destroyer")
	{
		if (orient == 'H')
		{
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
			cout << endl << "To place your " << shipName << " on the board.\n";
			cout << "Choose a letter between \"A\" and \"I\": ";
			cin >> rowLocation;

			while (toupper(rowLocation) != 'A' && toupper(rowLocation) != 'B' && toupper(rowLocation) != 'C'
				&& toupper(rowLocation) != 'D' && toupper(rowLocation) != 'E' && toupper(rowLocation) != 'F'
				&& toupper(rowLocation) != 'G' && toupper(rowLocation) != 'H' && toupper(rowLocation) != 'I')
			{
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
					playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << "\nInvalid selection!  You must enter only \"A\" through \"I\"."; //colorchange
				cout << "\nTo place your " << shipName << " on the board,\n";
				cout << "Choose a letter between \"A\" and \"I\": ";
				cout << "\a";
				cin >> rowLocation;
			}

			rowLocation = toupper(rowLocation);
			return rowLocation;
		}
		else
		{
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
			cout << endl << "To place your " << shipName << " on the board.\n";
			cout << "Choose a letter between \"A\" and \"G\": ";
			cin >> rowLocation;

			while (toupper(rowLocation) != 'A' && toupper(rowLocation) != 'B' && toupper(rowLocation) != 'C'
				&& toupper(rowLocation) != 'D' && toupper(rowLocation) != 'E' && toupper(rowLocation) != 'F'
				&& toupper(rowLocation) != 'G')
			{
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
					playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << "\nInvalid selection!  You must enter only \"A\" through \"G\"."; //colorchange
				cout << "\nTo place your " << shipName << " on the board,\n";
				cout << "Choose a letter between \"A\" and \"G\": ";
				cout << "\a";
				cin >> rowLocation;
			}

			rowLocation = toupper(rowLocation);
			return rowLocation;
		}
	}

	if (shipName == "Patrol Boat")
	{
		if (orient == 'H')
		{
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
			cout << endl << "To place your " << shipName << " on the board.\n";
			cout << "Choose a letter between \"A\" and \"I\": ";
			cin >> rowLocation;

			while (toupper(rowLocation) != 'A' && toupper(rowLocation) != 'B' && toupper(rowLocation) != 'C' && toupper(rowLocation) != 'D' && toupper(rowLocation) != 'E' && toupper(rowLocation) != 'F' && toupper(rowLocation) != 'G' && toupper(rowLocation) != 'H' && toupper(rowLocation) != 'I')
			{
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << "\nInvalid selection!  You must enter only \"A\" through \"I\"."; //colorchange
				cout << "\nTo place your " << shipName << " on the board,\n";
				cout << "Choose a letter between \"A\" and \"I\": ";
				cout << "\a";
				cin >> rowLocation;
			}

			rowLocation = toupper(rowLocation);
			return rowLocation;
		}
		else
		{
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
			cout << endl << "To place your " << shipName << " on the board.\n";
			cout << "Choose a letter between \"A\" and \"H\": ";
			cin >> rowLocation;

			while (toupper(rowLocation) != 'A' && toupper(rowLocation) != 'B' && toupper(rowLocation) != 'C' && toupper(rowLocation) != 'D' && toupper(rowLocation) != 'E' && toupper(rowLocation) != 'F' && toupper(rowLocation) != 'G' && toupper(rowLocation) != 'H')
			{
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << "\nInvalid selection!  You must enter only \"A\" through \"H\"."; //colorchange
				cout << "\nTo place your " << shipName << " on the board,\n";
				cout << "Choose a letter between \"A\" and \"H\": ";
				cout << "\a";
				cin >> rowLocation;
			}

			rowLocation = toupper(rowLocation);
			return rowLocation;
		}
	}
}



//this function gets the ship's beginning row location
char getColLocation(int playerOneBoard[][COLS], int playerTwoBoard[][COLS], bool hidePlayer1, bool hidePlayer2, string fName1, string fName2, string shipName, char orient, int playerOneCarr, int playerOneBatt, int playerOneSub, int playerOneDes, int playerOnePat, int playerTwoCarr, int playerTwoBatt, int playerTwoSub, int playerTwoDes, int playerTwoPat)
{
	char colLocation;

	if (shipName == "Carrier")
	{
		system("cls");
		showLogo();
		showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
		cout << endl << "To place your " << shipName << " on the board.\n";
		cout << "Choose a number between \"1\" and \"9\": ";
		cin >> colLocation;

		while (colLocation != '1' && colLocation != '2' && colLocation != '3'
			&& colLocation != '4' && colLocation != '5' && colLocation != '6'
			&& colLocation != '7' && colLocation != '8' && colLocation != '9')
		{
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
			cout << "\nInvalid selection!  You must enter only \"1\" through \"9\"."; //colorchange
			cout << "\nTo place your " << shipName << " on the board,\n";
			cout << "Choose a number between \"1\" and \"9\": ";
			cout << "\a";
			cin >> colLocation;
		}

		return colLocation;
	}

	if (shipName == "Battleship")
	{
		if (orient == 'V')
		{
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
			cout << endl << "To place your " << shipName << " on the board.\n";
			cout << "Choose a number between \"1\" and \"9\": ";
			cin >> colLocation;

			while (colLocation != '1' && colLocation != '2' && colLocation != '3'
				&& colLocation != '4' && colLocation != '5' && colLocation != '6'
				&& colLocation != '7' && colLocation != '8' && colLocation != '9')
			{
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
					playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << "\nInvalid selection!  You must enter only \"1\" through \"9\"."; //colorchange
				cout << "\nTo place your " << shipName << " on the board,\n";
				cout << "Choose a number between \"1\" and \"9\": ";
				cout << "\a";
				cin >> colLocation;
			}

			return colLocation;
		}
		else
		{
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
			cout << endl << "To place your " << shipName << " on the board.\n";
			cout << "Choose a number between \"1\" and \"6\": ";
			cin >> colLocation;

			while (colLocation != '1' && colLocation != '2' && colLocation != '3'
				&& colLocation != '4' && colLocation != '5' && colLocation != '6')
			{
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << "\nInvalid selection!  You must enter only \"1\" through \"6\"."; //colorchange
				cout << "\nTo place your " << shipName << " on the board,\n";
				cout << "Choose a number between \"1\" and \"6\": ";
				cout << "\a";
				cin >> colLocation;
			}

			return colLocation;
		}
	}

	if (shipName == "Submarine")
	{
		if (orient == 'V')
		{
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
			cout << endl << "To place your " << shipName << " on the board.\n";
			cout << "Choose a number between \"1\" and \"9\": ";
			cin >> colLocation;

			while (colLocation != '1' && colLocation != '2' && colLocation != '3'
				&& colLocation != '4' && colLocation != '5' && colLocation != '6'
				&& colLocation != '7' && colLocation != '8' && colLocation != '9')
			{
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
					playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << "\nInvalid selection!  You must enter only \"1\" through \"9\"."; //colorchange
				cout << "\nTo place your " << shipName << " on the board,\n";
				cout << "Choose a number between \"1\" and \"9\": ";
				cout << "\a";
				cin >> colLocation;
			}

			return colLocation;
		}
		else
		{
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
			cout << endl << "To place your " << shipName << " on the board.\n";
			cout << "Choose a number between \"1\" and \"7\": ";
			cin >> colLocation;

			while (colLocation != '1' && colLocation != '2' && colLocation != '3'
				&& colLocation != '4' && colLocation != '5' && colLocation != '6'
				&& colLocation != '7')
			{
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
					playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << "\nInvalid selection!  You must enter only \"1\" through \"7\"."; //colorchange
				cout << "\nTo place your " << shipName << " on the board,\n";
				cout << "Choose a number between \"1\" and \"7\": ";
				cout << "\a";
				cin >> colLocation;
			}

			return colLocation;
		}
	}

	if (shipName == "Destroyer")
	{
		if (orient == 'V')
		{
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
			cout << endl << "To place your " << shipName << " on the board.\n";
			cout << "Choose a number between \"1\" and \"9\": ";
			cin >> colLocation;

			while (colLocation != '1' && colLocation != '2' && colLocation != '3'
				&& colLocation != '4' && colLocation != '5' && colLocation != '6'
				&& colLocation != '7' && colLocation != '8' && colLocation != '9')
			{
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
					playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << "\nInvalid selection!  You must enter only \"1\" through \"9\"."; //colorchange
				cout << "\nTo place your " << shipName << " on the board,\n";
				cout << "Choose a number between \"1\" and \"9\": ";
				cout << "\a";
				cin >> colLocation;
			}

			return colLocation;
		}
		else
		{
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
			cout << endl << "To place your " << shipName << " on the board.\n";
			cout << "Choose a number between \"1\" and \"7\": ";
			cin >> colLocation;

			while (colLocation != '1' && colLocation != '2' && colLocation != '3'
				&& colLocation != '4' && colLocation != '5' && colLocation != '6'
				&& colLocation != '7')
			{
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
					playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << "\nInvalid selection!  You must enter only \"1\" through \"7\"."; //colorchange
				cout << "\nTo place your " << shipName << " on the board,\n";
				cout << "Choose a number between \"1\" and \"7\": ";
				cout << "\a";
				cin >> colLocation;
			}

			return colLocation;
		}
	}

	if (shipName == "Patrol Boat")
	{
		if (orient == 'V')
		{
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
			cout << endl << "To place your " << shipName << " on the board.\n";
			cout << "Choose a number between \"1\" and \"9\": ";
			cin >> colLocation;

			while (colLocation != '1' && colLocation != '2' && colLocation != '3'
				&& colLocation != '4' && colLocation != '5' && colLocation != '6'
				&& colLocation != '7' && colLocation != '8' && colLocation != '9')
			{
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << "\nInvalid selection!  You must enter only \"1\" through \"9\"."; //colorchange
				cout << "\nTo place your " << shipName << " on the board,\n";
				cout << "Choose a number between \"1\" and \"9\": ";
				cout << "\a";
				cin >> colLocation;
			}

			return colLocation;
		}
		else
		{
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
			cout << endl << "To place your " << shipName << " on the board.\n";
			cout << "Choose a number between \"1\" and \"8\": ";
			cin >> colLocation;

			while (colLocation != '1' && colLocation != '2' && colLocation != '3'
				&& colLocation != '4' && colLocation != '5' && colLocation != '6'
				&& colLocation != '7' && colLocation != '8')
			{
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
					playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << "\nInvalid selection!  You must enter only \"1\" through \"8\".";//colorchange
				cout << "\nTo place your " << shipName << " on the board,\n";
				cout << "Choose a number between \"1\" and \"8\": ";
				cout << "\a";
				cin >> colLocation;
			}

			return colLocation;
		}
	}
}


//this function accepts char variables and converts them to ints to enable entering the ship coordinates into a 2-dimensional array of ints
int characterToInteger(char ch)
{
	if (ch == 'A')
		return 0;
	if (ch == 'B')
		return 1;
	if (ch == 'C')
		return 2;
	if (ch == 'D')
		return 3;
	if (ch == 'E')
		return 4;
	if (ch == 'F')
		return 5;
	if (ch == 'G')
		return 6;
	if (ch == 'H')
		return 7;
	if (ch == 'I')
		return 8;
	if (ch == '1')
		return 0;
	if (ch == '2')
		return 1;
	if (ch == '3')
		return 2;
	if (ch == '4')
		return 3;
	if (ch == '5')
		return 4;
	if (ch == '6')
		return 5;
	if (ch == '7')
		return 6;
	if (ch == '8')
		return 7;
	if (ch == '9')
		return 8;
}

//this function compares newly placed horizontal ships to the ships
//that have already been placed in the player's board.  If the 
//ships overlap, it returns true.
bool overlappingHShips(int board[][COLS], int rowCoordinate, int colCoordinate, string shipName)

//this function compares newly placed vertical ships to the ships
//that have already been placed in the player's board.  If the 
//ships overlap, it returns true.
bool overlappingVShips(int board[][COLS], int rowCoordinate, int colCoordinate, string shipName)
{
	int spaces;

	if (shipName == "Carrier")
		return false;
	if (shipName == "Battleship")
		spaces = 4;
	if (shipName == "Submarine")
		spaces = 3;
	if (shipName == "Destroyer")
		spaces = 3;
	if (shipName == "Patrol Boat")
		spaces = 2;

	for (int shipStart = rowCoordinate; shipStart < rowCoordinate + spaces; shipStart++)
	{
		if (board[shipStart][colCoordinate] != 0)
			return true;
	}
	return false;
}


//this function will be used to place ships on the player's game board
void placeShip(int playerOneBoard[][COLS], int playerTwoBoard[][COLS],
	bool hidePlayer1, bool hidePlayer2, string fName1, string fName2, string shipName, int currentPlayer, int playerOneCarr, int playerOneBatt, int playerOneSub, int playerOneDes, int playerOnePat,
	int playerTwoCarr, int playerTwoBatt, int playerTwoSub, int playerTwoDes, int playerTwoPat)
{
	char orientation,
		rowLocation,
		colLocation;
	int rowCoordinate,			        //integer varaible to hold array locations
		colCoordinate;			        //integer variable to hold array locations
	bool overlap;               //variable to search for overlapping ships

	do
	{
		orientation = getOrientation(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, shipName,
			playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
		rowLocation = getRowLocation(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, shipName, orientation,
			playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
		colLocation = getColLocation(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, shipName, orientation,
			playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

		//checking for overlapping ships
		rowCoordinate = characterToInteger(rowLocation);           //converting coordinates to integers for comparison
		colCoordinate = characterToInteger(colLocation);           //with array elements

		if (currentPlayer == 1)
		{
			if (orientation == 'H')
			{
				overlap = overlappingHShips(playerOneBoard, rowCoordinate, colCoordinate, shipName);
			}
			else
			{
				overlap = overlappingVShips(playerOneBoard, rowCoordinate, colCoordinate, shipName);
			}
		}

		if (currentPlayer == 2)
		{
			if (orientation == 'H')
			{
				overlap = overlappingHShips(playerTwoBoard, rowCoordinate, colCoordinate, shipName);
			}
			else
			{
				overlap = overlappingVShips(playerTwoBoard, rowCoordinate, colCoordinate, shipName);
			}
		}

		if (overlap)
		{
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
			cout << "You cannot have overlapping ships." << "\nPlease re-enter your coordinates for your " << shipName << ".\n"; //colorchange
			cout << "\a";
			system("pause");
		}

	} while (overlap);

	system("cls");
	showLogo();
	showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
		playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

	//checking for ships that don't fit on the map and correcting locations before
	//entering coordinates on the player's game board
	if (shipName == "Carrier")
	{
		if (orientation == 'H')     //for horizontally placed Carriers
		{
			if (colLocation > '5')
			{
				colLocation = '5';
				cout << "\nYour " << shipName << " didn't fit at those coordinates, so I moved it over to "
					<< rowLocation << ":" << colLocation;

			}

			//converting chars to ints for ship placement in board array
			colCoordinate = characterToInteger(colLocation);
			rowCoordinate = characterToInteger(rowLocation);

			//placing ship in board array
			for (int shipStart = colCoordinate; shipStart < colCoordinate + 5; shipStart++)
			{
				if (currentPlayer == 1)
				{
					playerOneBoard[rowCoordinate][shipStart] = 1;
				}
				if (currentPlayer == 2)
				{
					playerTwoBoard[rowCoordinate][shipStart] = 1;
				}
			}
		}
		else                        //for vertically placed Carriers
		{
			if (rowLocation > 'E')
			{
				rowLocation = 'E';
				cout << "\nYour " << shipName << " didn't fit at those coordinates, so I moved it up to "
					<< rowLocation << ":" << colLocation;

			}
			//converting chars to ints for ship placement in board array
			colCoordinate = characterToInteger(colLocation);
			rowCoordinate = characterToInteger(rowLocation);

			//placing ship in board array
			for (int shipStart = rowCoordinate; shipStart < rowCoordinate + 5; shipStart++)
			{
				if (currentPlayer == 1)
				{
					playerOneBoard[shipStart][colCoordinate] = 1;
				}
				if (currentPlayer == 2)
				{
					playerTwoBoard[shipStart][colCoordinate] = 1;
				}
			}
		}
	}
	else if (shipName == "Battleship")
	{
		if (orientation == 'H')     //for horizontally placed Battleships
		{
			//converting chars to ints for ship placement in board array
			colCoordinate = characterToInteger(colLocation);
			rowCoordinate = characterToInteger(rowLocation);

			//placing ship in board array
			for (int shipStart = colCoordinate; shipStart < colCoordinate + 4; shipStart++)
			{
				if (currentPlayer == 1)
				{
					playerOneBoard[rowCoordinate][shipStart] = 2;
				}
				if (currentPlayer == 2)
				{
					playerTwoBoard[rowCoordinate][shipStart] = 2;
				}
			}
		}
		else                        //for vertically placed Battleships
		{
			//converting chars to ints for ship placement in board array
			colCoordinate = characterToInteger(colLocation);
			rowCoordinate = characterToInteger(rowLocation);

			//placing ship in board array
			for (int shipStart = rowCoordinate; shipStart < rowCoordinate + 4; shipStart++)
			{
				if (currentPlayer == 1)
				{
					playerOneBoard[shipStart][colCoordinate] = 2;
				}
				if (currentPlayer == 2)
				{
					playerTwoBoard[shipStart][colCoordinate] = 2;
				}

			}
		}

	}
	else if (shipName == "Submarine")
	{
		if (orientation == 'H')     //for horizontally placed Submarines
		{
			//converting chars to ints for ship placement in board array
			colCoordinate = characterToInteger(colLocation);
			rowCoordinate = characterToInteger(rowLocation);

			//placing ship in board array
			for (int shipStart = colCoordinate; shipStart < colCoordinate + 3; shipStart++)
			{
				if (currentPlayer == 1)
				{
					playerOneBoard[rowCoordinate][shipStart] = 3;
				}
				if (currentPlayer == 2)
				{
					playerTwoBoard[rowCoordinate][shipStart] = 3;
				}
			}
		}
		else                        //for vertically placed Submarines
		{
			//converting chars to ints for ship placement in board array
			colCoordinate = characterToInteger(colLocation);
			rowCoordinate = characterToInteger(rowLocation);

			//placing ship in board array
			for (int shipStart = rowCoordinate; shipStart < rowCoordinate + 3; shipStart++)
			{
				if (currentPlayer == 1)
				{
					playerOneBoard[shipStart][colCoordinate] = 3;
				}
				if (currentPlayer == 2)
				{
					playerTwoBoard[shipStart][colCoordinate] = 3;
				}

			}
		}

	}
	else if (shipName == "Destroyer")
	{
		if (orientation == 'H')     //for horizontally placed Destroyers
		{
			//converting chars to ints for ship placement in board array
			colCoordinate = characterToInteger(colLocation);
			rowCoordinate = characterToInteger(rowLocation);

			//placing ship in board array
			for (int shipStart = colCoordinate; shipStart < colCoordinate + 3; shipStart++)
			{
				if (currentPlayer == 1)
				{
					playerOneBoard[rowCoordinate][shipStart] = 4;
				}
				if (currentPlayer == 2)
				{
					playerTwoBoard[rowCoordinate][shipStart] = 4;
				}
			}
		}
		else                        //for vertically placed Destroyers
		{
			//converting chars to ints for ship placement in board array
			colCoordinate = characterToInteger(colLocation);
			rowCoordinate = characterToInteger(rowLocation);

			//placing ship in board array
			for (int shipStart = rowCoordinate; shipStart < rowCoordinate + 3; shipStart++)
			{
				if (currentPlayer == 1)
				{
					playerOneBoard[shipStart][colCoordinate] = 4;
				}
				if (currentPlayer == 2)
				{
					playerTwoBoard[shipStart][colCoordinate] = 4;
				}

			}
		}

	}
	else  //the only ship left is Patrol Boat
	{
		if (orientation == 'H')     //for horizontally placed Patrol Boats
		{
			//converting chars to ints for ship placement in board array
			colCoordinate = characterToInteger(colLocation);
			rowCoordinate = characterToInteger(rowLocation);

			//placing ship in board array
			for (int shipStart = colCoordinate; shipStart < colCoordinate + 2; shipStart++)
			{
				if (currentPlayer == 1)
				{
					playerOneBoard[rowCoordinate][shipStart] = 5;
				}
				if (currentPlayer == 2)
				{
					playerTwoBoard[rowCoordinate][shipStart] = 5;
				}
			}
		}
		else                        //for vertically placed Patrol Boats
		{
			//converting chars to ints for ship placement in board array
			colCoordinate = characterToInteger(colLocation);
			rowCoordinate = characterToInteger(rowLocation);

			//placing ship in board array
			for (int shipStart = rowCoordinate; shipStart < rowCoordinate + 2; shipStart++)
			{
				if (currentPlayer == 1)
				{
					playerOneBoard[shipStart][colCoordinate] = 5;
				}
				if (currentPlayer == 2)
				{
					playerTwoBoard[shipStart][colCoordinate] = 5;
				}

			}
		}

	}

	system("cls");
	showLogo();
	showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
		playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

	cout << "\nShip orientation: ";
	if (orientation == 'H')
		cout << "Horizontal\n";
	else
		cout << "Vertical\n";
	cout << "Ship coordinates: " << rowLocation << ":" << colLocation << endl;
	system("pause");
}



void autoPlaceShip(int playerOneBoard[][COLS], int playerTwoBoard[][COLS],
	bool hidePlayer1, bool hidePlayer2, string fName1, string fName2,
	string shipName, int currentPlayer, int playerOneCarr, int playerOneBatt, int playerOneSub, int playerOneDes, int playerOnePat,
	int playerTwoCarr, int playerTwoBatt, int playerTwoSub, int playerTwoDes, int playerTwoPat)
{
	int  rowCoordinate,
		colCoordinate,
		randomOrientation;
	char orientation;
	bool overlap;

	do
	{
		randomOrientation = rand() % 2;
		if (randomOrientation == 0)
			orientation = 'H';
		else
			orientation = 'V';

		if (shipName == "Carrier" && orientation == 'H')
		{
			rowCoordinate = rand() % 9;
			colCoordinate = rand() % 4;
		}
		else if (shipName == "Carrier" && orientation == 'V')
		{
			rowCoordinate = rand() % 4;
			colCoordinate = rand() % 9;
		}
		else if (shipName == "Battleship" && orientation == 'H')
		{
			rowCoordinate = rand() % 9;
			colCoordinate = rand() % 5;
		}
		else if (shipName == "Battleship" && orientation == 'V')
		{
			rowCoordinate = rand() % 5;
			colCoordinate = rand() % 9;
		}
		else if (shipName == "Submarine" && orientation == 'H')
		{
			rowCoordinate = rand() % 9;
			colCoordinate = rand() % 6;
		}
		else if (shipName == "Submarine" && orientation == 'V')
		{
			rowCoordinate = rand() % 6;
			colCoordinate = rand() % 9;
		}
		else if (shipName == "Destroyer" && orientation == 'H')
		{
			rowCoordinate = rand() % 9;
			colCoordinate = rand() % 6;
		}
		else if (shipName == "Destroyer" && orientation == 'V')
		{
			rowCoordinate = rand() % 6;
			colCoordinate = rand() % 9;
		}
		else if (shipName == "Patrol Boat" && orientation == 'H')
		{
			rowCoordinate = rand() % 9;
			colCoordinate = rand() % 7;
		}
		else
		{
			rowCoordinate = rand() % 7;
			colCoordinate = rand() % 9;
		}


		if (currentPlayer == 1)
		{
			if (orientation == 'H')
			{
				overlap = overlappingHShips(playerOneBoard, rowCoordinate, colCoordinate, shipName);
			}
			else
			{
				overlap = overlappingVShips(playerOneBoard, rowCoordinate, colCoordinate, shipName);
			}
		}

		if (currentPlayer == 2)
		{
			if (orientation == 'H')
			{
				overlap = overlappingHShips(playerTwoBoard, rowCoordinate, colCoordinate, shipName);
			}
			else
			{
				overlap = overlappingVShips(playerTwoBoard, rowCoordinate, colCoordinate, shipName);
			}
		}

	} while (overlap);

	system("cls");
	showLogo();
	showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

	if (shipName == "Carrier")
	{
		if (orientation == 'H')
		{

			for (int shipStart = colCoordinate; shipStart < colCoordinate + 5; shipStart++)
			{
				if (currentPlayer == 1)
				{
					playerOneBoard[rowCoordinate][shipStart] = 1;
				}
				if (currentPlayer == 2)
				{
					playerTwoBoard[rowCoordinate][shipStart] = 1;
				}
			}
		}
		else                        //for vertically placed carriers
		{
			for (int shipStart = rowCoordinate; shipStart < rowCoordinate + 5; shipStart++)
			{
				if (currentPlayer == 1)
				{
					playerOneBoard[shipStart][colCoordinate] = 1;
				}
				if (currentPlayer == 2)
				{
					playerTwoBoard[shipStart][colCoordinate] = 1;
				}
			}
		}
	}
	else if (shipName == "Battleship")
	{
		if (orientation == 'H')     //for horizontally placed battleships
		{
			//placing ship in board array
			for (int shipStart = colCoordinate; shipStart < colCoordinate + 4; shipStart++)
			{
				if (currentPlayer == 1)
				{
					playerOneBoard[rowCoordinate][shipStart] = 2;
				}
				if (currentPlayer == 2)
				{
					playerTwoBoard[rowCoordinate][shipStart] = 2;
				}
			}
		}
		else                        //for vertically placed battleships
		{
			//placing ship in board array
			for (int shipStart = rowCoordinate; shipStart < rowCoordinate + 4; shipStart++)
			{
				if (currentPlayer == 1)
				{
					playerOneBoard[shipStart][colCoordinate] = 2;
				}
				if (currentPlayer == 2)
				{
					playerTwoBoard[shipStart][colCoordinate] = 2;
				}

			}
		}

	}
	else if (shipName == "Submarine")
	{
		if (orientation == 'H')     //for horizontally placed Submarines
		{
			//placing ship in board array
			for (int shipStart = colCoordinate; shipStart < colCoordinate + 3; shipStart++)
			{
				if (currentPlayer == 1)
				{
					playerOneBoard[rowCoordinate][shipStart] = 3;
				}
				if (currentPlayer == 2)
				{
					playerTwoBoard[rowCoordinate][shipStart] = 3;
				}
			}
		}
		else                        //for vertically placed Submarines
		{
			//placing ship in board array
			for (int shipStart = rowCoordinate; shipStart < rowCoordinate + 3; shipStart++)
			{
				if (currentPlayer == 1)
				{
					playerOneBoard[shipStart][colCoordinate] = 3;
				}
				if (currentPlayer == 2)
				{
					playerTwoBoard[shipStart][colCoordinate] = 3;
				}

			}
		}

	}
	else if (shipName == "Destroyer")
	{
		if (orientation == 'H')     //for horizontally placed Destroyers
		{
			//placing ship in board array
			for (int shipStart = colCoordinate; shipStart < colCoordinate + 3; shipStart++)
			{
				if (currentPlayer == 1)
				{
					playerOneBoard[rowCoordinate][shipStart] = 4;
				}
				if (currentPlayer == 2)
				{
					playerTwoBoard[rowCoordinate][shipStart] = 4;
				}
			}
		}
		else                        //for vertically placed Destroyers
		{
			//placing ship in board array
			for (int shipStart = rowCoordinate; shipStart < rowCoordinate + 3; shipStart++)
			{
				if (currentPlayer == 1)
				{
					playerOneBoard[shipStart][colCoordinate] = 4;
				}
				if (currentPlayer == 2)
				{
					playerTwoBoard[shipStart][colCoordinate] = 4;
				}

			}
		}

	}
	else  //the only ship left is Patrol Boat
	{
		if (orientation == 'H')     //for horizontally placed Patrol Boats
		{
			//placing ship in board array
			for (int shipStart = colCoordinate; shipStart < colCoordinate + 2; shipStart++)
			{
				if (currentPlayer == 1)
				{
					playerOneBoard[rowCoordinate][shipStart] = 5;
				}
				if (currentPlayer == 2)
				{
					playerTwoBoard[rowCoordinate][shipStart] = 5;
				}
			}
		}
		else                        //for vertically placed Patrol boats
		{
			//placing ship in board array
			for (int shipStart = rowCoordinate; shipStart < rowCoordinate + 2; shipStart++)
			{
				if (currentPlayer == 1)
				{
					playerOneBoard[shipStart][colCoordinate] = 5;
				}
				if (currentPlayer == 2)
				{
					playerTwoBoard[shipStart][colCoordinate] = 5;
				}

			}
		}

	}

	system("cls");
	showLogo();
	showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

	cout << endl << shipName << " has been randomly placed on the game board.";
}

//this function gets a row coordinate from the players during gameplay
char getRowCoord(int playerOneBoard[][COLS], int playerTwoBoard[][COLS], bool hidePlayer1, bool hidePlayer2, string fName1, string fName2, int playerOneCarr, int playerOneBatt, int playerOneSub, int playerOneDes, int playerOnePat, int playerTwoCarr, int playerTwoBatt, int playerTwoSub, int playerTwoDes, int playerTwoPat)
{
	char coordinate;

	cout << "Choose a letter coordinate between \"A\" and \"I\": "; cin >> coordinate;


	while (toupper(coordinate) != 'A' && toupper(coordinate) != 'B' && toupper(coordinate) != 'C'
		&& toupper(coordinate) != 'D' && toupper(coordinate) != 'E' && toupper(coordinate) != 'F'
		&& toupper(coordinate) != 'G' && toupper(coordinate) != 'H' && toupper(coordinate) != 'I')
	{
		system("cls");
		showLogo();
		showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
			playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
		cout << "\nInvalid selection!  You must enter only \"A\" through \"I\".\n"; //colorchange
		cout << "Choose a letter coordinate between \"A\" and \"I\": ";
		cout << "\a";
		cin >> coordinate;

		//			coordinate = toupper(coordinate);
	}
	return coordinate;
}



//this function gets a row coordinate from the players during gameplay
char getColCoord(int playerOneBoard[][COLS], int playerTwoBoard[][COLS], bool hidePlayer1, bool hidePlayer2, string fName1, string fName2, int playerOneCarr, int playerOneBatt, int playerOneSub, int playerOneDes, int playerOnePat, int playerTwoCarr, int playerTwoBatt, int playerTwoSub, int playerTwoDes, int playerTwoPat)
{
	char coordinate;

	cout << "Choose a number coordinate between \"1\" and \"9\": ";
	cin >> coordinate;

	while (coordinate != '1' && coordinate != '2' && coordinate != '3'
		&& coordinate != '4' && coordinate != '5' && coordinate != '6'
		&& coordinate != '7' && coordinate != '8' && coordinate != '9')
	{
		system("cls");
		showLogo();
		showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
			playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
		cout << "\nInvalid selection!  You must enter only \"1\" through \"9\".\n"; //colorchange
		cout << "Choose a number coordinate between \"1\" and \"9\": ";
		cout << "\a";
		cin >> coordinate;
	}
	return coordinate;
}


void showHitMiss(char rowCoord, char colCoord, int rowArray, int colArray, int currentPlayer, int playerOneBoard[][COLS], int playerTwoBoard[][COLS])
{
	cout << endl << rowCoord << ":" << colCoord << " is a ";
	{
		if (currentPlayer == 1)
		{
			if (playerTwoBoard[rowArray][colArray] == 100)
				cout << "MISS!"; //colorchange
			else
				cout << "HIT!"; //colorchange
		}

		//current player is Player 2
		else
		{
			if (playerOneBoard[rowArray][colArray] == 100)
				cout << "MISS!"; //colorchange
			else
				cout << "HIT!"; //colorchange
		}
	}


}

//this function accepts int variables and converts them to chars to enable
//displaying the computer's chosen row coordinates during game play
char rowIntegerToCharacter(int num)
{
	if (num == 0)
		return 'A';
	if (num == 1)
		return 'B';
	if (num == 2)
		return 'C';
	if (num == 3)
		return 'D';
	if (num == 4)
		return 'E';
	if (num == 5)
		return 'F';
	if (num == 6)
		return 'G';
	if (num == 7)
		return 'H';
	if (num == 8)
		return 'I';
}


//this function accepts int variables and converts them to chars to enable
//displaying the computer's chosen column coordinates during game play
char colIntegerToCharacter(int num)
{
	if (num == 0)
		return '1';
	if (num == 1)
		return '2';
	if (num == 2)
		return '3';
	if (num == 3)
		return '4';
	if (num == 4)
		return '5';
	if (num == 5)
		return '6';
	if (num == 6)
		return '7';
	if (num == 7)
		return '8';
	if (num == 8)
		return '9';
}



void onePlayerGame(fstream& userData, char& choice, int count, UserAcct player[])
{
	string
		usernameOne,
		password1,
		fName1,
		usernameTwo,
		password2,
		fName2;
	bool
		found = false,
		valid1 = false,
		valid2 = false,
		hidePlayer1 = true,
		hidePlayer2 = true,
		player1Wins = false,
		player2Wins = false;
	int
		index = 1,
		player1,
		player2,
		playerOneBoard[ROWS][COLS],
		playerTwoBoard[ROWS][COLS],
		currentPlayer,
		playerOneCarr = 0,
		playerTwoCarr = 0,
		playerOneBatt = 0,
		playerTwoBatt = 0,
		playerOneSub = 0,
		playerTwoSub = 0,
		playerOneDes = 0,
		playerTwoDes = 0,
		playerOnePat = 0,
		playerTwoPat = 0,
		rowArray,
		colArray;
	char
		playGame = 'Y',				//controls whether a game will be played or not
		rowCoord,
		colCoord;

	srand(time(NULL));
	system("cls");
	showLogo();

	cout << "\nPlease enter a user name for Player 1: "; cin >> usernameOne;

	//searching the player array for the entered user name
	while (index < count && found == false)
	{
		if (usernameOne == player[index].userName)
		{
			found = true;
		}
		else
		{
			index++;
		}
	}

	//if the user entered a user name from the player array,
	//prompt for a matching password
	if (found)
	{
		system("cls");
		showLogo();
		cout << "\nPlease enter your password:";
		password1 = getPass(PASSWORD_WIDTH);

		//if the password matches, the player is validated
		if (password1 == player[index].password)
		{
			valid1 = true;

			//player 1 is announced and his position in the
			//player array is recorded in the player1 variable
			system("cls");
			showLogo();
			player1 = index;
			fName1 = player[index].firstName;
			cout << "\nPlayer 1 is " << fName1 << endl << endl;
		}

		//or the password didn't match and user is given three more attempts
		else
		{
			system("cls");
			showLogo();
			int attempts = 1;
			while (attempts <= 3 && !(valid1))
			{
				cout << "The password was incorrect.\n" << "Please re-enter password: "; //colorchange
				cout << "\a";
				password1 = getPass(PASSWORD_WIDTH);
				attempts++;
				if (password1 == player[index].password)
				{
					valid1 = true;

					system("cls");
					showLogo();
					player1 = index;
					fName1 = player[index].firstName;
					cout << "\nPlayer 1 is " << fName1 << endl << endl;
				}


				else
				{
					system("cls");
					showLogo();

					if (attempts > 3)
					{
						system("cls");
						showLogo();
						cout << "\nPlayer 1 could not be validated.\n\n"; //colorchange
						cout << "\a";

					}
				}
			}
		}

	}

	else
	{
		cout << "\nThat user name cannot be found!\n";
		cout << "\a";

	}

	if (valid1)
	{
		system("cls");
		showLogo();


		usernameTwo = player[0].userName;

		password2 = player[0].password;

		if (password2 == player[0].password)
		{
			valid2 = true;

			system("cls");
			showLogo();

			player2 = 0;
			fName2 = player[0].firstName;
			cout << "\nPlayer 2 is the " << fName2 << endl << endl;
		}
	}

	if (valid1 && valid2)
	{
		while (toupper(playGame) == 'Y')
		{
			system("cls");
			showLogo();
			cout << "\n\t\t\t\tThe game is on!" << "\n\n\t\tPlayer 1: " << fName1 << "\t\t\tPlayer 2: " << fName2; //colorchange


			for (int r = 0; r < ROWS; r++)
			{
				for (int c = 0; c < COLS; c++)
				{
					playerOneBoard[r][c] = 0;
					playerTwoBoard[r][c] = 0;
				}
			}


			hidePlayer1 = false;
			hidePlayer2 = true;

			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//player 1 starts out placing ships on the player 1 board
			cout << endl << fName1 << "\'s turn to place ships on the board.\n";
			system("pause");

			//placing Carrier
			placeShip(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, "Carrier", 1, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//placing Battleship
			placeShip(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, "Battleship", 1, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//placing Submarine
			placeShip(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, "Submarine", 1, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//placing Destroyer
			placeShip(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, "Destroyer", 1, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//placing Patrol Boat
			placeShip(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, "Patrol Boat", 1, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);


			//Player 2 places ships on the board
			hidePlayer1 = true;
			hidePlayer2 = true;

			//game board refresh
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			cout << endl << fName2 << "\'s turn to place ships on the board.\n";


			/*
			//temporary placement of computer's ships -- needs to be replaced with random function
			for (index = 0; index < 5; index++)
				playerTwoBoard[0][index] += 1;
			for (index = 2; index < 6; index++)
				playerTwoBoard[2][index] += 2;
			for (index = 4; index < 7; index++)
				playerTwoBoard[4][index] += 3;
			for (index = 3; index < 6; index++)
				playerTwoBoard[6][index] += 4;
			for (index = 7; index < 9; index++)
				playerTwoBoard[8][index] =+ 5;
			*/

			//placing Carrier
			autoPlaceShip(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, "Carrier", 2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//placing Battleship
			autoPlaceShip(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, "Battleship", 2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//placing Submarine
			autoPlaceShip(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, "Submarine", 2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//placing Destroyer
			autoPlaceShip(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, "Destroyer", 2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//placing Patrol Boat
			autoPlaceShip(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, "Patrol Boat", 2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//start of the game
			hidePlayer1 = true;
			hidePlayer2 = true;

			system("cls");

			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//randomly choosing which player to go first
			currentPlayer = 1 + rand() % 2;

			//first player to start is announced
			if (currentPlayer == 1)
				cout << endl << fName1 << " has randomly been chosen to go first.\n\n";
			else
				cout << endl << fName2 << " has randomly been chosen to go first.\n\n";
			system("pause");

			//start game loop -- continues until a winner is determined
			while (!(player1Wins || player2Wins))
			{
				if (currentPlayer == 1)
				{
					system("cls");
					showLogo();
					showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
						playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

					//getting the coordinates from the player to bomb
					cout << endl << fName1 << ", ";
					rowCoord = getRowCoord(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
						playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
					cout << endl << "Now, ";
					colCoord = getColCoord(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
						playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

					//converting the coordinates to integers for use with the gameboard
					rowArray = characterToInteger(rowCoord) - 97;
					colArray = characterToInteger(colCoord);

					//checking to see if chosen location has already been chosen
					while (playerTwoBoard[rowArray][colArray] >= 100)
					{
						system("cls");
						showLogo();
						showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
							playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
						cout << "Those coordinates have already been chosen.  Please choose again."; //colorchange
						cout << "\a";

						//getting the coordinates from the player to bomb
						cout << endl << fName1 << ", ";
						rowCoord = getRowCoord(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
							playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
						cout << endl << "Now, ";
						colCoord = getColCoord(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
							playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

						//converting the coordinates to integers for use with the gameboard
						rowArray = characterToInteger(rowCoord) - 97;
						colArray = characterToInteger(colCoord);
					}

					//adding 100 to the chosen coordintes indicating a bomb has landed there
					playerTwoBoard[rowArray][colArray] += 100;

					//zeroing out the ship variables

					playerTwoCarr = 0;
					playerTwoBatt = 0;
					playerTwoSub = 0;
					playerTwoDes = 0;
					playerTwoPat = 0;

					//scanning the players boards
					for (int row = 0; row < ROWS; row++)
					{
						for (int col = 0; col < COLS; col++)
						{
							if (playerTwoBoard[row][col] == 101)
								playerTwoCarr++;
							if (playerTwoBoard[row][col] == 102)
								playerTwoBatt++;
							if (playerTwoBoard[row][col] == 103)
								playerTwoSub++;
							if (playerTwoBoard[row][col] == 104)
								playerTwoDes++;
							if (playerTwoBoard[row][col] == 105)
								playerTwoPat++;
						}
					}

					//annoucing hit or miss
					system("cls");
					showLogo();
					showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
						playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

					showHitMiss(rowCoord, colCoord, rowArray, colArray, currentPlayer, playerOneBoard, playerTwoBoard);

					//looking for a winner
					if (playerTwoCarr == 5 && playerTwoBatt == 4 && playerTwoSub == 3 && playerTwoDes == 3 && playerTwoPat == 2)
						player1Wins = true;
					else					//changing current player
						currentPlayer = 2;
				}
				else						//current player is Player 2
				{
					system("cls");
					showLogo();
					showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
						playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

					//getting the coordinates from the player to bomb
					rowArray = rand() % 9;	//characterToInteger(rowCoord) - 97;
					colArray = rand() % 9;	//characterToInteger(colCoord);

					//checking to see if chosen location has already been chosen
					while (playerOneBoard[rowArray][colArray] >= 100)
					{
						rowArray = rand() % 9;	//characterToInteger(rowCoord) - 97;
						colArray = rand() % 9;	//characterToInteger(colCoord);
					}

					//adding 100 to the chosen coordintes indicating a bomb has landed there
					playerOneBoard[rowArray][colArray] += 100;

					//converting the array coordinates to their corresponding character names
					rowCoord = rowIntegerToCharacter(rowArray);
					colCoord = colIntegerToCharacter(colArray);

					//zeroing out the ship variables
					playerOneCarr = 0;
					playerOneBatt = 0;
					playerOneSub = 0;
					playerOneDes = 0;
					playerOnePat = 0;

					//scanning the player board
					for (int row = 0; row < ROWS; row++)
					{
						for (int col = 0; col < COLS; col++)
						{
							if (playerOneBoard[row][col] == 101)
								playerOneCarr++;
							if (playerOneBoard[row][col] == 102)
								playerOneBatt++;
							if (playerOneBoard[row][col] == 103)
								playerOneSub++;
							if (playerOneBoard[row][col] == 104)
								playerOneDes++;
							if (playerOneBoard[row][col] == 105)
								playerOnePat++;
						}
					}

					//annoucing hit or miss
					system("cls");
					showLogo();
					showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
						playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

					cout << "\nThe computer has chosen " << rowCoord << ":" << colCoord;
					showHitMiss(rowCoord, colCoord, rowArray, colArray, currentPlayer, playerOneBoard, playerTwoBoard);

					//looking for a winner
					if (playerOneCarr == 5 && playerOneBatt == 4 && playerOneSub == 3 && playerOneDes == 3 && playerOnePat == 2)
						player2Wins = true;
					else					//changing current player
						currentPlayer = 1;
				}

			}

			//if all of player 2's ships are sunk
			if (player1Wins)
			{
				//setting the board visibility
				hidePlayer1 = false;					//player 1's board is visible
				hidePlayer2 = false;					//player 2's board is visible

				//announce player 1 is the winner
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
					playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << endl << fName1 << " has won the game!\n\n";

				//update stats for player one and player two here
				player[player1].wins++;
				player[player1].winPercent = ((double)player[player1].wins / (player[player1].wins + player[player1].losses)) * 100.0;

				player[player2].losses++;
				player[player2].winPercent = ((double)player[player2].wins / (player[player2].wins + player[player2].losses)) * 100.0;

				//opening the userData file in output mode
				userData.open("playerdata.dat", ios::out);

				//writing updated player stats to the userData file
				for (index = 0; index < count; index++)
				{

					//write the updated player array to the userData file
					userData << player[index].userName << "\n";
					userData << player[index].password << "\n";
					userData << player[index].firstName << "\n";
					userData << player[index].wins << "\n";
					userData << player[index].losses << "\n";
					userData << player[index].winPercent << "\n";

				}

				//closing the data file
				userData.close();

				system("pause");
			}
			else
			{
				//setting the board visibility
				hidePlayer1 = false;					//player 1's board is visible
				hidePlayer2 = false;					//player 2's board is visible

				//announce player 2 is the winner
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
					playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << endl << fName2 << " has won the game!\n\n";

				//update stats for player one and player two here
				player[player2].wins++;
				player[player2].winPercent = ((double)player[player2].wins / (player[player2].wins + player[player2].losses)) * 100.0;

				player[player1].losses++;
				player[player1].winPercent = ((double)player[player1].wins / (player[player1].wins + player[player1].losses)) * 100.0;

				//opening the userData file in output mode
				userData.open("playerdata.dat", ios::out);

				//writing updated player stats to the userData file
				for (index = 0; index < count; index++)
				{

					//write the updated player array to the userData file
					userData << player[index].userName << "\n";
					userData << player[index].password << "\n";
					userData << player[index].firstName << "\n";
					userData << player[index].wins << "\n";
					userData << player[index].losses << "\n";
					userData << player[index].winPercent << "\n";

				}

				//closing the data file
				userData.close();

				system("pause");
			}

			//after the game is finished, prompt for a re-match
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
			cout << "\nWould you like a re-match? (\"Y\" or \"N\"): ";
			cin >> playGame;

			while (toupper(playGame) != 'Y' && toupper(playGame) != 'N')
			{
				//user must choose Y or N to proceed
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << "Invalid selection!  You must enter only \"Y\" or \"N\".";
				cout << "\nWould you like a re-match? (\"Y\" or \"N\"): ";
				cout << "\a";
				cin >> playGame;
			}

			//resetting the game variables
			player1Wins = false;
			player2Wins = false;
			playerOneCarr = 0;
			playerOneBatt = 0;
			playerOneSub = 0;
			playerOneDes = 0;
			playerOnePat = 0;
			playerTwoCarr = 0;
			playerTwoBatt = 0;
			playerTwoSub = 0;
			playerTwoDes = 0;
			playerTwoPat = 0;

		}
	}
	else
	{
		cout << "\n\nYou need a validated player to play a game.\n\n"; //colorchange
		cout << "\a";
		system("pause");
		system("cls");
	}


	system("cls");
	showLogo();
	choice = showMainMenu();
}

//two-player game function
void twoPlayerGame(fstream& userData, char& choice, int count, UserAcct player[])
{
	string
		usernameOne,
		password1,
		fName1,
		usernameTwo,
		password2,
		fName2;
	bool
		found = false,
		valid1 = false,
		valid2 = false,
		hidePlayer1 = true,
		hidePlayer2 = true,
		player1Wins = false,
		player2Wins = false;
	int
		index = 1,
		player1,
		player2,
		playerOneBoard[ROWS][COLS],
		playerTwoBoard[ROWS][COLS],
		currentPlayer,
		playerOneCarr = 0,
		playerTwoCarr = 0,
		playerOneBatt = 0,
		playerTwoBatt = 0,
		playerOneSub = 0,
		playerTwoSub = 0,
		playerOneDes = 0,
		playerTwoDes = 0,
		playerOnePat = 0,
		playerTwoPat = 0,
		rowArray,
		colArray;
	char
		playGame = 'Y',
		rowCoord,
		colCoord;


	srand((time(NULL)));


	system("cls");
	showLogo();

	//prompting for a user name
	cout << "\nPlease enter a user name for Player 1: ";
	cin >> usernameOne;

	//searching the player array for the entered user name
	while (index < count && found == false)
	{
		if (usernameOne == player[index].userName)
		{
			found = true;
		}
		else
		{
			index++;
		}
	}

	//if the user entered a user name from the player array,
	//prompt for a matching password
	if (found)
	{
		system("cls");
		showLogo();
		cout << "\nPlease enter your password:";
		password1 = getPass(PASSWORD_WIDTH);

		//if the password matches, the player is validated
		if (password1 == player[index].password)
		{
			valid1 = true;

			//player 1 is announced and his position in the
			//player array is recorded in the player1 variable
			system("cls");
			showLogo();
			player1 = index;
			fName1 = player[index].firstName;
			cout << "\nPlayer 1 is " << fName1 << endl << endl;
		}

		//or the password didn't match and user is given three more attempts
		else
		{
			system("cls");
			showLogo();
			int attempts = 1;
			while (attempts <= 3 && !(valid1))
			{
				cout << "The password was incorrect." << "\nPlease re-enter password: "; //colorchange
				cout << "\a";
				password1 = getPass(PASSWORD_WIDTH);
				attempts++;
				if (password1 == player[index].password)
				{
					valid1 = true;

					system("cls");
					showLogo();
					player1 = index;
					fName1 = player[index].firstName;
					cout << "\nPlayer 1 is " << fName1 << endl << endl;
				}

				//if the password can't be matched to the user account
				//the player is not validated and the function returns
				//to the main menu
				else
				{
					system("cls");
					showLogo();

					if (attempts > 3)
					{
						system("cls");
						showLogo();
						cout << "\nPlayer 1 could not be validated.\n\n"; //colorchange
						cout << "\a";
					}
				}
			}
		}

	}

	//if the entered user name is not in the player array
	//the function returns to the main menu
	else
	{
		cout << "\nThat user name cannot be found!\n"; //colorchange
		cout << "\a";
	}

	if (valid1)
	{
		found = false;
		index = 1;

		//prompt for a user name
		system("cls");
		showLogo();
		cout << "\nPlease enter a user name for Player 2: ";
		cin >> usernameTwo;

		//search the player array for the entered user name
		while (index < count && found == false)
		{
			if (usernameTwo == player[index].userName)
			{
				found = true;
			}
			else
			{
				index++;
			}
		}

		//if the user name is found, prompt for a password
		if (found)
		{
			system("cls");
			showLogo();
			cout << "\nPlease enter your password:";
			password2 = getPass(PASSWORD_WIDTH);

			//if the password matches the associated password for the username
			//player 2 has been validated
			if (password2 == player[index].password)
			{
				valid2 = true;

				//player 2 is announced
				system("cls");
				showLogo();
				player2 = index;
				fName2 = player[index].firstName;
				cout << "\nPlayer 2 is " << fName2 << endl << endl;
			}

			//if the password doesn't match, the user is given three
			//more chances
			else
			{
				system("cls");
				showLogo();
				int attempts = 1;
				while (attempts <= 3 && !(valid2))
				{
					cout << "The password was incorrect." << "\nPlease re-enter password: "; //colorchange
					cout << "\a";
					password2 = getPass(PASSWORD_WIDTH);
					attempts++;

					//if the password matches, player 2 is validated
					if (password2 == player[index].password)
					{
						valid2 = true;

						//player 2 is announced and his position in the 
						//player array is recorded in the player2 variable
						system("cls");
						showLogo();
						player2 = index;
						fName2 = player[index].firstName;
						cout << "\nPlayer 2 is " << fName2 << endl << endl;
					}

					//or the player could not be validated and the function returns
					//to the main menu
					else
					{
						system("cls");
						showLogo();

						if (attempts > 3)
						{
							system("cls");
							showLogo();
							cout << "\nPlayer 2 could not be validated.\n\n"; //colorchange
							cout << "\a";
						}
					}
				}
			}

		}

		//if the user name entered for player 2 is not in the player array
		//that announcement is made and the function returns to the main menu
		else
		{
			cout << "\nThat user name cannot be found!\n"; //colorchange
			cout << "\a";
		}
	}

	//if player 1 and player 2 have been validated, the main game loop is entered
	if (valid1 && valid2)
	{
		while (toupper(playGame) == 'Y')
		{
			system("cls");
			showLogo();
			cout << "\n\t\t\t\tThe game is on!" << "\n\n\t\tPlayer 1: " << fName1 << "\t\t\tPlayer 2: " << fName2; //colorchange


			//initialize game board arrays to 0
			for (int r = 0; r < ROWS; r++)
			{
				for (int c = 0; c < COLS; c++)
				{
					playerOneBoard[r][c] = 0;
					playerTwoBoard[r][c] = 0;
				}
			}

			//Player 1 places ships on the board
			hidePlayer1 = false;				//player 1 can see his ships
			hidePlayer2 = true;					//player 2's board is blank

			//this refreshes the screen and shows the game boards -- it is used
			//extensively during the ship placement and game play portions of the program
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//player 1 starts out placing ships on the player 1 board
			cout << endl << fName1 << "\'s turn to place ships on the board.\n";
			system("pause");

			//placing Carrier
			placeShip(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, "Carrier", 1,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//placing Battleship
			placeShip(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, "Battleship", 1,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//placing Submarine
			placeShip(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, "Submarine", 1,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//placing Destroyer
			placeShip(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, "Destroyer", 1,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//placing Patrol Boat
			placeShip(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, "Patrol Boat", 1,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);


			//Player 2 places ships on the board
			hidePlayer1 = true;					//player 1's board is blank
			hidePlayer2 = false;				//player 2 can see his ships

			//game board refresh
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//player 2 now places ships on the player 2 board
			cout << endl << fName2 << "\'s turn to place ships on the board.\n";
			system("pause");

			//placing Carrier
			placeShip(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, "Carrier", 2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//placing Battleship
			placeShip(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, "Battleship", 2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//placing Submarine
			placeShip(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, "Submarine", 2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//placing Destroyer
			placeShip(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, "Destroyer", 2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//placing Patrol Boat
			placeShip(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2, "Patrol Boat", 2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);


			//start of actual game play
			hidePlayer1 = true;					//player 1's board is blank
			hidePlayer2 = true;					//player 2's board is blank

			//game board refresh
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

			//randomly choosing which player to go first
			currentPlayer = 1 + rand() % 2;

			//first player to start is announced
			if (currentPlayer == 1)
				cout << endl << fName1 << " has randomly been chosen to go first.\n\n";
			else
				cout << endl << fName2 << " has randomly been chosen to go first.\n\n";
			system("pause");

			//start game loop -- continues until a winner is determined
			while (!(player1Wins || player2Wins))
			{
				if (currentPlayer == 1)
				{
					system("cls");
					showLogo();
					showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
						playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

					//getting the coordinates from the player to bomb
					cout << endl << fName1 << ", ";
					rowCoord = getRowCoord(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
						playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
					cout << endl << "Now, ";
					colCoord = getColCoord(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
						playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

					//converting the coordinates to integers for use with the gameboard
					rowArray = characterToInteger(rowCoord) - 97;
					colArray = characterToInteger(colCoord);

					//checking to see if chosen location has already been chosen
					while (playerTwoBoard[rowArray][colArray] >= 100)
					{
						system("cls");
						showLogo();
						showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
							playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
						cout << "Those coordinates have already been chosen.  Please choose again."; //colorchange
						cout << "\a";

						//getting the coordinates from the player to bomb
						cout << endl << fName1 << ", ";
						rowCoord = getRowCoord(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
							playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
						cout << endl << "Now, ";
						colCoord = getColCoord(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
							playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

						//converting the coordinates to integers for use with the gameboard
						rowArray = characterToInteger(rowCoord) - 97;
						colArray = characterToInteger(colCoord);
					}

					//adding 100 to the chosen coordintes indicating a bomb has landed there
					playerTwoBoard[rowArray][colArray] += 100;

					//zeroing out the ship variables

					playerTwoCarr = 0;
					playerTwoBatt = 0;
					playerTwoSub = 0;
					playerTwoDes = 0;
					playerTwoPat = 0;

					//scanning the players boards
					for (int row = 0; row < ROWS; row++)
					{
						for (int col = 0; col < COLS; col++)
						{
							if (playerTwoBoard[row][col] == 101)
								playerTwoCarr++;
							if (playerTwoBoard[row][col] == 102)
								playerTwoBatt++;
							if (playerTwoBoard[row][col] == 103)
								playerTwoSub++;
							if (playerTwoBoard[row][col] == 104)
								playerTwoDes++;
							if (playerTwoBoard[row][col] == 105)
								playerTwoPat++;
						}
					}

					//annoucing hit or miss
					system("cls");
					showLogo();
					showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
						playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

					showHitMiss(rowCoord, colCoord, rowArray, colArray, currentPlayer, playerOneBoard, playerTwoBoard);

					//looking for a winner
					if (playerTwoCarr == 5 && playerTwoBatt == 4 && playerTwoSub == 3 && playerTwoDes == 3 && playerTwoPat == 2)
						player1Wins = true;
					else					//changing current player
						currentPlayer = 2;
				}
				else						//current player is Player 2
				{
					system("cls");
					showLogo();
					showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
						playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

					//getting the coordinates from the player to bomb
					cout << endl << fName2 << ", ";
					rowCoord = getRowCoord(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
						playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
					cout << endl << "Now, ";
					colCoord = getColCoord(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
						playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

					//converting the coordinates to integers for use with the gameboard
					rowArray = characterToInteger(rowCoord) - 97;
					colArray = characterToInteger(colCoord);

					//checking to see if chosen location has already been chosen
					while (playerOneBoard[rowArray][colArray] >= 100)
					{
						system("cls");
						showLogo();
						showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
							playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
						cout << "Those coordinates have already been chosen.  Please choose again."; //colorchange
						cout << "\a";

						//getting the coordinates from the player to bomb
						cout << endl << fName2 << ", ";
						rowCoord = getRowCoord(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
							playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
						cout << endl << "Now, ";
						colCoord = getColCoord(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
							playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

						//converting the coordinates to integers for use with the gameboard
						rowArray = characterToInteger(rowCoord) - 97;
						colArray = characterToInteger(colCoord);
					}

					//adding 100 to the chosen coordintes indicating a bomb has landed there
					playerOneBoard[rowArray][colArray] += 100;

					//zeroing out the ship variables
					playerOneCarr = 0;
					playerOneBatt = 0;
					playerOneSub = 0;
					playerOneDes = 0;
					playerOnePat = 0;

					//scanning the player board
					for (int row = 0; row < ROWS; row++)
					{
						for (int col = 0; col < COLS; col++)
						{
							if (playerOneBoard[row][col] == 101)
								playerOneCarr++;
							if (playerOneBoard[row][col] == 102)
								playerOneBatt++;
							if (playerOneBoard[row][col] == 103)
								playerOneSub++;
							if (playerOneBoard[row][col] == 104)
								playerOneDes++;
							if (playerOneBoard[row][col] == 105)
								playerOnePat++;
						}
					}

					//annoucing hit or miss
					system("cls");
					showLogo();
					showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
						playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);

					showHitMiss(rowCoord, colCoord, rowArray, colArray, currentPlayer, playerOneBoard, playerTwoBoard);

					//looking for a winner
					if (playerOneCarr == 5 && playerOneBatt == 4 && playerOneSub == 3 && playerOneDes == 3 && playerOnePat == 2)
						player2Wins = true;
					else					//changing current player
						currentPlayer = 1;
				}

			}

			//if all of player 2's ships are sunk
			if (player1Wins)
			{
				//setting the board visibility
				hidePlayer1 = false;					//player 1's board is visible
				hidePlayer2 = false;					//player 2's board is visible

				//announce player 1 is the winner
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
					playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << endl << fName1 << " has won the game!\n\n";

				//update stats for player one and player two here
				player[player1].wins++;
				player[player1].winPercent = ((double)player[player1].wins / (player[player1].wins + player[player1].losses)) * 100.0;

				player[player2].losses++;
				player[player2].winPercent = ((double)player[player2].wins / (player[player2].wins + player[player2].losses)) * 100.0;

				//opening the userData file in output mode
				userData.open("playerdata.dat", ios::out);

				//writing updated player stats to the userData file
				for (index = 0; index < count; index++)
				{

					//write the updated player array to the userData file
					userData << player[index].userName << "\n";
					userData << player[index].password << "\n";
					userData << player[index].firstName << "\n";
					userData << player[index].wins << "\n";
					userData << player[index].losses << "\n";
					userData << player[index].winPercent << "\n";

				}

				//closing the data file
				userData.close();

				system("pause");
			}
			else
			{
				//setting the board visibility
				hidePlayer1 = false;					//player 1's board is visible
				hidePlayer2 = false;					//player 2's board is visible

				//announce player 2 is the winner
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
					playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << endl << fName2 << " has won the game!\n\n";

				//update stats for player one and player two here
				player[player2].wins++;
				player[player2].winPercent = ((double)player[player2].wins / (player[player2].wins + player[player2].losses)) * 100.0;

				player[player1].losses++;
				player[player1].winPercent = ((double)player[player1].wins / (player[player1].wins + player[player1].losses)) * 100.0;

				//opening the userData file in output mode
				userData.open("playerdata.dat", ios::out);

				//writing updated player stats to the userData file
				for (index = 0; index < count; index++)
				{

					//write the updated player array to the userData file
					userData << player[index].userName << "\n";
					userData << player[index].password << "\n";
					userData << player[index].firstName << "\n";
					userData << player[index].wins << "\n";
					userData << player[index].losses << "\n";
					userData << player[index].winPercent << "\n";

				}

				//closing the data file
				userData.close();

				system("pause");
			}

			//after the game is finished, prompt for a re-match
			system("cls");
			showLogo();
			showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
				playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
			cout << "\nWould you like a re-match? (\"Y\" or \"N\"): ";
			cin >> playGame;

			while (toupper(playGame) != 'Y' && toupper(playGame) != 'N')
			{
				//user must choose Y or N to proceed
				system("cls");
				showLogo();
				showBoard(playerOneBoard, playerTwoBoard, hidePlayer1, hidePlayer2, fName1, fName2,
					playerOneCarr, playerOneBatt, playerOneSub, playerOneDes, playerOnePat, playerTwoCarr, playerTwoBatt, playerTwoSub, playerTwoDes, playerTwoPat);
				cout << "\nInvalid selection!  You must enter only \"Y\" or \"N\"."; //colorchange
				cout << "\nWould you like a re-match? (\"Y\" or \"N\"): ";
				cout << "\a";
				cin >> playGame;
			}

			//resetting the game variables
			player1Wins = false;
			player2Wins = false;
			playerOneCarr = 0;
			playerOneBatt = 0;
			playerOneSub = 0;
			playerOneDes = 0;
			playerOnePat = 0;
			playerTwoCarr = 0;
			playerTwoBatt = 0;
			playerTwoSub = 0;
			playerTwoDes = 0;
			playerTwoPat = 0;

		}
	}
	//this will execute if one player or the other are not validated
	else
	{
		cout << "\n\nYou need two validated players to play a game.\n\n"; //colorchange
		cout << "\a";
		system("pause");
		system("cls");
	}


	//this displays the main menu
	system("cls");
	showLogo();
	choice = showMainMenu();
}



