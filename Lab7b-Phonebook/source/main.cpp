/*
Author: Michael Roberts
Class: CSI-140-52
Assignment: Lab 6a
Date Assigned: April 14, 2016
Due Date: April 121, 2016

Description:
	This is a program that allows for the user to search for phonnumbers, and users
  phonenumbers, input of new numbers is done via text file.


Certification of Authenticity:
	I certify that this is entirely my own work, except where I have given fullydocumented
	references to the work of others. I understand the definition and
	consequences of plagiarism and acknowledge that the assessor of this assignment
	may, for the purpose of assessing this assignment:
		- Reproduce this assignment and provide a copy to another member of
		academic staff; and/or
		- Communicate a copy of this assignment to a plagiarism checking service
		(which may then retain a copy of this assignment on its database for
		the purpose of future plagiarism checking)
*/

#include "phonebook.h"

void eventLoop();

// Get info based on users choice
void getInfo(string numbers[], string names[], int choice){
  string userInput;

  switch(choice){
    // Print entire phonebook
    case 1:
      printPhonebook(numbers, names);
      cout << endl;
      eventLoop();
      break;

    // Get a name from a phonenumber
    case 2:
      cout << "What is the phonenumber: " << endl;
      cin.ignore();
      getline(cin, userInput);
      numberLookup(userInput, numbers, names);
      cout << endl;
      eventLoop();
      break;

    // Get a phonenumber from a name
    case 3:
      cout << "What is the name: " << endl;
      cin.ignore();
      getline(cin, userInput);
      nameLookup(userInput, numbers, names);
      cout << endl;
      eventLoop();
      break;

    // Exit
    case 4:
      break;
  }
}

// Main Loop that keeps getting called, contains the users choices.
void eventLoop(){
  // Arrays of all our data
  string phoneNumbers [BOOKSIZE];
  string names [BOOKSIZE];
  // Filling the arrays
  getPhoneNumbers(phoneNumbers, "../phones.txt");
  getNames(names, "../phones.txt");

  // The users choice
  int choice = 0;

  while(choice == 0){
    cout << "[1] Print Phonebook" << endl;
    cout << "[2] Get Name from Number" << endl;
    cout << "[3] Get Number from Name" << endl;
    cout << "[4] QUIT" << endl;
    cout << "[?] ";
    cin >> choice;
    cout << endl;
  }

  // Getting information based on choice
  getInfo(phoneNumbers, names, choice);
}

// Program entrance
int main(int argc, const char * argv[]) {

  eventLoop();
  return 0;
}
