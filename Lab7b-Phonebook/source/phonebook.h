#ifndef __PHONEBOOK_H_INCLUDED__
#define __PHONEBOOK_H_INCLUDED__

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

using namespace std;

// Maximum phonebook size
const int BOOKSIZE = 100;

// Regex for a proper US Phone Number
const regex PHONEREG("^(\\+0?1\\s)?\\(?\\d{3}\\)?[\\s.-]\\d{3}[\\s.-]\\d{4}$");

// Gets all users name records
void getNames(string names[], string file);

// Gets all users phone records, also determines if phonenumber is valid
void getPhoneNumbers(string numbers[], string file);

// prints the entire phonebook as name: phonenumber
void printPhonebook(string numbers[], string names[]);

// Finds a users name from a number
void nameLookup(string name, string names[], string numbers[]);

// Finds a users number from a name
void numberLookup(string number, string names[], string numbers[]);

#endif
