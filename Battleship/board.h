#pragma once
#include <iostream>
#include <string>
#include <fstream> 
#include <string.h>
#include <time.h>

using namespace std;

const int COLS = 9;

void onePlayerGame(fstream& userData, char& choice, int count, UserAcct player[]);
void twoPlayerGame(fstream& userData, char& choice, int count, UserAcct player[]);
void showBoard(int playerOneBoard[][COLS], int playerTwoBoard[][COLS], bool hidePlayer1, bool hidePlayer2, string fName1, string fName2, int c1, int b1, int s1, int d1, int playerOne, int c2, int b2, int s2, int d2, int playerTwo);
void placeShip(int playerOneBoard[][COLS], int playerTwoBoard[][COLS],
	bool hidePlayer1, bool hidePlayer2, string fName1, string fName2, string shipName, int currentPlayer, int playerOneCarr, int playerOneBatt, int playerOneSub, int playerOneDes, int playerOnePat,
	int playerTwoCarr, int playerTwoBatt, int playerTwoSub, int playerTwoDes, int playerTwoPat);
void autoPlaceShip(int playerOneBoard[][COLS], int playerTwoBoard[][COLS],
	bool hidePlayer1, bool hidePlayer2, string fName1, string fName2,
	string shipName, int currentPlayer, int playerOneCarr, int playerOneBatt, int playerOneSub, int playerOneDes, int playerOnePat,
	int playerTwoCarr, int playerTwoBatt, int playerTwoSub, int playerTwoDes, int playerTwoPat);
void showHitMiss(char rowCoord, char colCoord, int rowArray, int colArray, int currentPlayer, int playerOneBoard[][COLS], int playerTwoBoard[][COLS]);



char showHidden(int coordinate);
char showVisible(int coordinate);
char getOrientation(int playerOneBoard[][COLS], int playerTwoBoard[][COLS], bool hidePlayer1, bool hidePlayer2,
	string fName1, string fName2, string shipName, int playerOneCarr, int playerOneBatt, int playerOneSub, int playerOneDes, int playerOnePat,
	int playerTwoCarr, int playerTwoBatt, int playerTwoSub, int playerTwoDes, int playerTwoPat);
char getRowLocation(int playerOneBoard[][COLS], int playerTwoBoard[][COLS], bool hidePlayer1, bool hidePlayer2, string fName1, string fName2, string shipName, char orient, int playerOneCarr, int playerOneBatt, int playerOneSub, int playerOneDes, int playerOnePat, int playerTwoCarr, int playerTwoBatt, int playerTwoSub, int playerTwoDes, int playerTwoPat);
char getColLocation(int playerOneBoard[][COLS], int playerTwoBoard[][COLS], bool hidePlayer1, bool hidePlayer2, string fName1, string fName2, string shipName, char orient, int playerOneCarr, int playerOneBatt, int playerOneSub, int playerOneDes, int playerOnePat, int playerTwoCarr, int playerTwoBatt, int playerTwoSub, int playerTwoDes, int playerTwoPat);
char getRowCoord(int playerOneBoard[][COLS], int playerTwoBoard[][COLS], bool hidePlayer1, bool hidePlayer2, string fName1, string fName2, int playerOneCarr, int playerOneBatt, int playerOneSub, int playerOneDes, int playerOnePat, int playerTwoCarr, int playerTwoBatt, int playerTwoSub, int playerTwoDes, int playerTwoPat);
char getColCoord(int playerOneBoard[][COLS], int playerTwoBoard[][COLS], bool hidePlayer1, bool hidePlayer2, string fName1, string fName2, int playerOneCarr, int playerOneBatt, int playerOneSub, int playerOneDes, int playerOnePat, int playerTwoCarr, int playerTwoBatt, int playerTwoSub, int playerTwoDes, int playerTwoPat);
char rowIntegerToCharacter(int num);
char colIntegerToCharacter(int num);
string showNeutralGround(int rowNumber, int c1, int b1, int s1, int d1, int playerOne, int c2, int b2, int s2, int d2, int playerTwo);
int characterToInteger(char ch);
bool overlappingHShips(int board[][COLS], int rowCoordinate, int colCoordinate, string shipName);
bool overlappingVShips(int board[][COLS], int rowCoordinate, int colCoordinate, string shipName);