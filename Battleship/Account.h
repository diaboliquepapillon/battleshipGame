#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <time.h>

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

bool userCheck(UserAcct player[], string uName, int count);
char showAcctMenu();
void createNewAcct(fstream& userData, UserAcct player[], char& choice, int& count);
void accountSettings(fstream& userData, UserAcct player[], char& mnChoice, int& count);
void showUsers(UserAcct player[], char& choice, int count);
void editAcct(fstream& userData, UserAcct player[], char& choice, int& count);
void deleteAcct(fstream& userData, UserAcct player[], char& choice, int& count);