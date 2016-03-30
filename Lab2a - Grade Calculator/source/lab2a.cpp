/*
Author: Michael Roberts
Class: CSI-140-52
Assignment: Lab 2
Date Assigned: 2/18/16
Due Date: 2/23/16

Description:
  This program is intended to be used to determine the letter grade a student received. It does
  so by accepting an input by the user, in this case a percentage then campares that
  percentage to the given standards.

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

  double score;
  char grade;

  // Cutoffs for each letter grade
  const int A_MIN = 90;
  const int B_MIN = 80;
  const int C_MIN = 70;
  const int D_MIN = 60;

  // Get the users grade
  cout << "[!] Welcome to the score converter." << endl;
  cout << "[?] Plase Enter your score (0 to 100): " << endl;
  cin >> score;

  // Check if input is valid
  if (score > 100 || score < 0) {
    cout << "[!] Invalid score input" << endl;
    return 0;
  }

  // Evalute grade, determine letter based on value
  if (score > A_MIN ) {
    grade = 'A';
  } else if (score >= B_MIN && score < A_MIN) {
    grade = 'B';
  } else if (score >= C_MIN && score < B_MIN) {
    grade = 'C';
  } else if (score >= D_MIN) {
    grade = 'D';
  } else {
    grade = 'F';
  }

  // Output grade
  cout << "You grade is: " << grade << endl;
  return 0;
}
