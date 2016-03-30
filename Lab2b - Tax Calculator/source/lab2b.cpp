/*
Author: Michael Roberts
Class: CSI-140-52
Assignment: Lab 2
Date Assigned: 2/18/16
Due Date: 2/23/16

Description:
  This program is intended to be used to determine the amount taxes owed by the user, and what
  percent of their taxable is being taxed. This is done by an nput of total
  taxable income, and calculated based on current US tax standards.

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

int main(int argc, char const *argv[]) {

  // Users taxable income, will be an input (dollars)
  float taxableIncome = 0.00;

  // Amount owed by user, will be an output (dollars)
  float owed = 0.00;

  // What percent of your salary is taken for taxes, calculated
  float percentOf = 0.00;

  // Tax brackets, with their corresponding max dollar value in their range
  const int LEVEL1_MAX = 13150;
  const int LEVEL2_MAX = 50200;
  const int LEVEL3_MAX = 129600;
  const int LEVEL4_MAX = 209850;
  const int LEVEL5_MAX = 411500;
  const int LEVEL6_MAX = 439000;

  cout << "[!] Welcome to the Tax Calculator" << endl;
  cout << "[?] Please enter your taxable income in dollars: " << endl;
  cin >> taxableIncome;

  if (taxableIncome <= 0) {
    cout << "[!] You did enter a valid value, or did not make enough to be taxed." << endl;
    return 0;
  }

  // each level compares the max level for an income bracket. as well as the
  // max for of the next lower bracket. If it is between these two values
  // run the forumla for the bracket
  if (taxableIncome > LEVEL6_MAX) {
    owed = (.396 * (taxableIncome-439000))+125362;
  } else if (taxableIncome <= LEVEL6_MAX && taxableIncome > LEVEL5_MAX) {
    owed = (.35 * (taxableIncome-411500))+115737;
  } else if (taxableIncome <= LEVEL5_MAX && taxableIncome > LEVEL4_MAX) {
    owed = (.33 * (taxableIncome-209850))+49192.50;
  } else if (taxableIncome <= LEVEL4_MAX && taxableIncome > LEVEL3_MAX) {
    owed = (.28 * (taxableIncome-129600))+26772.50;
  } else if (taxableIncome <= LEVEL3_MAX && taxableIncome > LEVEL2_MAX) {
    owed = (.25 * (taxableIncome-50200))+6872.50;
  } else if (taxableIncome <= LEVEL2_MAX && taxableIncome > LEVEL1_MAX) {
    owed = (.15 * (taxableIncome-13150))+1315;
  } else {
    owed = taxableIncome * 0.10;
  }

  // Calculate what percent of your taxable income you lose
  percentOf = 100 * (owed/taxableIncome);

  // Set precision to display cents following owed amount
  cout.setf(ios::fixed);
  cout.precision(2);

  cout << "Your total amount of taxes owed is $" << owed << fixed << "." << endl;
  cout << "This amount is " << percentOf << " percent of your total taxable income." << endl;

  return 0;
}
