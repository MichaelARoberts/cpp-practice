/*
Author: Michael Roberts
Class: CSI-140-52
Assignment: Lab 1
Date Assigned: 2/11/16
Due Date: 2/16/16

Description:
  This program is used to convert miles to gallons via a user input of the amount of gallons
	a car can hold, and the maximum distance it travelled (miles)

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may,
for the purpose of assessing this assignment:
  - Reproduce this assignment and provide a copy to another member of academic staff; and/or
  - Communicate a copy of this assignment to a plagiarism checking service
    (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/

#include <iostream>

using namespace std;

float tankCapacity;
float carRange;
float mpg;

// Entrance Function
int main(int argc, char const *argv[])
{
	// Get fuel capacity, and max range of the car (gallons and miles)
	cout << "[?] What is the fuel capacity of your vehicle in gallons?" << endl;
	cin >> tankCapacity;
	cout << "[?] What is the range of your vehicle in miles?" << endl;
	cin >> carRange;

	//Calculate the MPG
	mpg = carRange/tankCapacity;

	//Set the precision
	cout.precision(4);

	//Display the amount
	cout << "[!] The MPG of your car is " <<  mpg << endl;
	return 0;
}
