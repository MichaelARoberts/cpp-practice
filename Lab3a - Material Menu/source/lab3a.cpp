/*
Author: Michael Roberts
Class: CSI-140-52
Assignment: Lab 3
Date Assigned: 2/25/16
Due Date: 3/1/16

Description:
  This program is intended to be used to determine the amount of seconds it will
  take to permeate certain types of meterials based on the input of the distance
  (thickness) of the material

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may,
for the purpose of assessing this assignment:
  - Reproduce this assignment and provide a copy to another member of academic staff; and/or
  - Communicate a copy of this assignment to a plagiarism checking service
    (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/


// Air   = 1100 FPS
// Water = 4900 FPS
// Steel = 16,400 FPS


#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

  // Constants
  const int AIR = 1100;
  const int WATER = 4900;
  const int STEEL = 16400;

  char materialInput;
  double distance;
  double seconds;

  // Output material menu, then accept letter as char, then make it uppercase.
  cout << "[!] Please enter a material: " << endl;
  cout << "   [A] Air" << endl;
  cout << "   [B] Water" << endl;
  cout << "   [C] Steel" << endl;
  cout << "   [?] ";
  cin >> materialInput;
  materialInput = toupper(materialInput);

  while (distance < 0){
    cout << "\n[!] Please enter the distance the sound will travel through the material: " << endl;
    cout << "   [?] ";
    cin >> distance;
  }

  // Calulate the amount of seconds it takes to permeate each material
  switch(materialInput){
    case 'A'  : seconds = distance/AIR; // If Air
                break;
    case 'B'  : seconds = distance/WATER;  // If Water
                break;
    case 'C'  : seconds = distance/STEEL; // If Steel
                break;
    default   : cout << "Invalid Material Choice";
                break;
  }

  cout << "The time it will take " << seconds << " seconds to travel through the material." << endl;

  return 0;
}
