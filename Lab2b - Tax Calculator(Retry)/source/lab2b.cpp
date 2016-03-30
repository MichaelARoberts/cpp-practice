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

  // Each Tax brackets max dollar value in their range
  const int BRACKET1_MAX = 13150;
  const int BRACKET2_MAX = 50200;
  const int BRACKET3_MAX = 129600;
  const int BRACKET4_MAX = 209850;
  const int BRACKET5_MAX = 411500;
  const int BRACKET6_MAX = 439000;

  // Each Tax brackets percentages
  const float ELSE_PERC = 0.10;
  const float BRACKET1_PERC = 0.15;
  const float BRACKET2_PERC = 0.25;
  const float BRACKET3_PERC = 0.38;
  const float BRACKET4_PERC = 0.33;
  const float BRACKET5_PERC = 0.35;
  const float BRACKET6_PERC = 0.396;

  // Each Tax bracket's minimum payment
  const float BRACKET1_MIN_PAYMENT = 125362;
  const float BRACKET2_MIN_PAYMENT = 115737;
  const float BRACKET3_MIN_PAYMENT = 49192.50;
  const float BRACKET4_MIN_PAYMENT = 26772.50;
  const float BRACKET5_MIN_PAYMENT = 6872.50;
  const float BRACKET6_MIN_PAYMENT = 1315;

  // max value in a bracket (You at least need 1 dollar)
  float bracket_max = 1;

  // percentage to take out of taxable income
  float bracket_percent = 0.0;

  // minimum payment that each bracket needs you to pay
  float min_payment = 0;

  cout << "[!] Welcome to the Tax Calculator" << endl;
  cout << "[?] Please enter your taxable income in dollars: " << endl;
  cin >> taxableIncome;

  if (taxableIncome <= 0) {
    cout << "[!] You did enter a valid value, or did not make enough to be taxed." << endl;
    return 0;
  }

  // each level compares the max level for an income bracket. as well as the
  // max for of the next lower bracket. If it is between these two values
  // set the corresponding brackets max, percentage, and minimum payment.
  if (taxableIncome > BRACKET6_MAX) {
    bracket_max     = BRACKET6_MAX;
    bracket_percent = BRACKET6_PERC;
    min_payment     = BRACKET6_MIN_PAYMENT;
  } else if (taxableIncome <= BRACKET6_MAX && taxableIncome > BRACKET5_MAX) {
    bracket_max     = BRACKET5_MAX;
    bracket_percent = BRACKET5_PERC;
    min_payment     = BRACKET5_MIN_PAYMENT;
  } else if (taxableIncome <= BRACKET5_MAX && taxableIncome > BRACKET4_MAX) {
    bracket_max     = BRACKET4_MAX;
    bracket_percent = BRACKET4_PERC;
    min_payment     = BRACKET4_MIN_PAYMENT;
  } else if (taxableIncome <= BRACKET4_MAX && taxableIncome > BRACKET3_MAX) {
    bracket_max     = BRACKET3_MAX;
    bracket_percent = BRACKET3_PERC;
    min_payment     = BRACKET3_MIN_PAYMENT;
  } else if (taxableIncome <= BRACKET3_MAX && taxableIncome > BRACKET2_MAX) {
    bracket_max     = BRACKET2_MAX;
    bracket_percent = BRACKET2_PERC;
    min_payment     = BRACKET2_MIN_PAYMENT;
  } else if (taxableIncome <= BRACKET2_MAX && taxableIncome > BRACKET1_MAX) {
    bracket_max     = BRACKET1_MAX;
    bracket_percent = BRACKET1_PERC;
    min_payment     = BRACKET1_MIN_PAYMENT;
  } else {
    bracket_percent = ELSE_PERC;
  }

  // Calulate the amount owed
  owed = ((bracket_percent * (taxableIncome - bracket_max)) + bracket_max);

  // Calculate what percent of your taxable income you lose
  percentOf = 100 * (owed/taxableIncome);

  // Set precision to display cents following owed amount
  cout.setf(ios::fixed);
  cout.precision(2);

  cout << "Your total amount of taxes owed is $" << owed << fixed << "." << endl;
  cout << "This amount is " << percentOf << " percent of your total taxable income." << endl;

  return 0;
}
