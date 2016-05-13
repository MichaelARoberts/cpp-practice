#ifndef __AUTOSHOP_H_INCLUDED__
#define __AUTOSHOP_H_INCLUDED__

#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <stdlib.h>
#include <cstring>

using namespace std;

const regex ADDRESS_REGEX("^\\s*\\S+(?:\\s+\\S+){2}");
const int SLOTS = 10;



// Shows shops logo, in Utility
// LOC: Utility
void displayLogo();

// Clears the console
// LOC: Utility
void clearScreen();

// Waits for users input / pauses
// LOC: Utility
void pauseSystem();

// Returns the first open slots index
// LOC: Utility
int findNextOpeningSlot(string phoneNumber[]);

// Displays Error Codes
// LOC: Error
void displayMessage(int messageCode);

// Displays Main Menu
// LOC: Menus
char mainMenu();

// Displays Mechanic  Menu
// LOC: Menus
char mechanicMenu();

// Displays Staff Menu
// LOC: Menus
char staffMenu();

// Controls all of the other menus, and the options coming in
// LOC: Menus
void menuNexus();

void staffNexus();

void mechanicNexus();

// Determines if user is a returning customer
// LOC: Clients
bool isClientExist(string phoneNumber);

// Determines if contract with auto maker exsists
// LOC: Cars
bool isMakeExist(string make);

// Determines if model is servicable
// LOC: Cars
bool isModelExist(string model);

// Gets the customers address, returns it as string
// LOC: Prompts
string promptAddress();

// Asks for a make, returns if true if it exsists, sets make in memory
// LOC: Prompts
bool promptMake(string &make);

// Asks for a model, returns if true if it exsists, sets model in memory
// LOC: Prompts
bool promptModel(string make, string &model);

// Gets the customers name, returns it as string
// LOC: Prompts
string promptName();

// Gets the users phonenumber, returns it as string
// LOC: Prompts
string promptPhoneNumber();

// Gets the users phonenumber, returns it as string
// LOC: Prompts
string promptLicensePlate();

// Gets the manufacturing year on card, Checks if valid
// LOC: Prompts
int promptYear();

// Combines all the prompts into one all call
// LOC: Prompts
void promptAll(string &address,string &make, string &model, string &name,
  string &phoneNumber, string &plate, int &year);

void initalizeArray(bool boolArray[]);

void initalizeArray(int intArray[]);

void initalizeArray(string stringArray[]);

#endif
