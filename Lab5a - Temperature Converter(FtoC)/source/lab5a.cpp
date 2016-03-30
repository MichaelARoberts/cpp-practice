/*
Author: Michael Roberts
Class: CSI-140-52
Assignment: Lab 5a
Date Assigned: March 22, 2016
Due Date: March 29, 2016

Description:
	This program converts the temperature from Fahrenheit to Celsius, as long as the
	temperature is above absolute zero.

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

#include<iostream>

using namespace std;

// Variables
const int F_TO_C_OFFSET = 32;
const double F_TO_C_RATIO = 5.0 / 9.0;
const double MIN_F = -459.67;

// Prototypes
void displayWelcomeMessage();
double fahrenheitToCelcius(double F);
double getFahrenheit();

int main()
{
	// the temperature in degrees Fahrenheit and Celcius (initial values are so it won't complain when first run)
	displayWelcomeMessage();
	double degrees_F = getFahrenheit();
	double degrees_C = fahrenheitToCelcius(degrees_F);
	cout << degrees_F << " Fahrenheit is " << degrees_C << " Celcius" << endl;
	return 0;
}

/* Purpose: Display a message to inform the user of the purpose of this program
   Pre: none
   Post: welcome message is output to the console; user feels welcome and informed
*/
void displayWelcomeMessage()
{
	// output a welcome message to the
	cout << "Welcome to the temperature converter!" << endl;
	cout << "This program will: " << endl;
	cout << "\t - Convert from Fahrenheit to Celsius" << endl;
	cout << "\t - Convert any tempeature above absolute zero" << endl;
	cout << "\t - Convert only once, then exit" << endl;

}


// Get users input, returns it as temperature Fahrenheit
double getFahrenheit()
{
	// Declaure fahrenheit
	double degrees_F = 0;

	// Fetch user input, and check validity
	cout << "\nEnter a temperature in degrees Fahrenheit: ";
	cin >> degrees_F;

	while (degrees_F < MIN_F)
	{
		cout << "That's below absolute zero!" << endl;
		cout << "Enter a temperature in degrees Fahrenheit: ";
		cin >> degrees_F;
	}

	// Return back the temperature
	return degrees_F;
}

// Converts fahrenheit temperature paramter, to celsisus return
double fahrenheitToCelcius(double F)
{
	// Celsisus local variable, and conversion, then returning it
	double C = (F - F_TO_C_OFFSET)/F_TO_C_RATIO;
	return C;
}
