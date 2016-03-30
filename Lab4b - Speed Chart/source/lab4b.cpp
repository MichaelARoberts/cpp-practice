/*
Author: Michael Roberts
Class: CSI-140-52
Assignment: Lab 4b
Date Assigned: March 3, 2016
Due Date: March 8, 2016

Description:
Tis program converts MPG to KPG by asking for the user's input of MPG, converts it,
and prints the result in KPG in a chart.

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

int main(int argc, char const *argv[]) {

  double kph;
  double mph = 0;

  while (mph <= 0){
    cout << "What is the MPH?" << endl;
    cin >> mph;
  }

  // The chart base
  cout << "Speed Conversion Chart" << endl;
  cout << "======================" << endl;
  cout << "    KPH    |    MPH   " << endl;
  cout << "----------------------" << endl;

  // Do the conversion formula
  kph = mph * 1.609344;
  cout.setf(ios::fixed);
  cout.precision(2);

  // The data for the chart
  cout << "   " << kph << "      " << mph << endl;

  return 0;
}
