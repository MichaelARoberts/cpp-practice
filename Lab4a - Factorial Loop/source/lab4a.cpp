/*
Author: Michael Roberts
Class: CSI-140-52
Assignment: Lab 4a
Date Assigned: March 3, 2016
Due Date: March 8, 2016

Description:
A program to demonstrate loop types and their appropriate use.
	The program will:
		a. query the user for a number, num,  within a range, only continuing when an appropriate number is found
		b. calculate num!
		c. ask the user if they wish to continue and repeat if so


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

#include <iostream>

using namespace std;

const int MIN = 0;
const int MAX = 12;


int main(void)
{

	int num,fac;				// The number entered from the user and its factorial
	char answer = 'Y';	// the answer from the user if they want to continue again

	// first (outer) loop:
	// controls the whole operation, allowing repetition if the user decides to
  while (answer == 'Y')
	{

		// second loop (inside first)
		// requests a number between MIN and MAX (inclusive) and


		do
		{

      cout << "Please enter a number between 0 and 12" << endl;
      cin >> num;

		} while (num < MIN || num > MAX);

		// num is now a number between 0 and 100...

		// third loop (inside first)
		// calculates num!
    fac = 1;

    for(int j = 1; j <= num; j++)
		{
      fac *= j;
		}

    cout << "Your factorial of that number is " << fac << endl;

		// ask the user if they want to continue (Y or y => yes)
    cout << "Do you want to continue?" << endl;
    cin >> answer;
    answer = toupper(answer);


	}

	cout << "Thanks for using the tool!" << endl;
	return 0;
}
