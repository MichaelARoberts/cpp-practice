/*
Author: Michael Roberts
Class: CSI-140-52
Assignment: Lab 6a
Date Assigned: April 7, 2016
Due Date: April 13, 2016

Description:
	This program is a tool for teachers to record test grades.

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
#include <string>

using namespace std;

int testScores[20] = {};
const int SIZE = 20;

void getScores(int min, int max){

    // Amount of scores we have
    int scoresTotal = 0;

    // Score we will be asking the user for
    string score;
    // The score in integer form
    int scoreInt;

    while(scoresTotal <= SIZE){
        cout  << "Score " << scoresTotal + 1 << endl;
        cout  << "-------" << endl;

        // Get the score
        cout << "Score: ";
        cin >> score;

        // If the user wants to end, break
        if (score == "END"){
          break;
        }

        // Covert score to int via character string function
        scoreInt = atoi(score.c_str());

        while (scoreInt < min || scoreInt > max){
            cout << "<!> ERROR: Enter a number between 0 an 100" << endl;
            cin >> scoreInt;
            cout << endl;
        }

        testScores[scoresTotal] = scoreInt;

        // Reset score for while loop
        scoresTotal++;

        //Add another line to make the output pretty
        cout << endl;
    }
}

int totalPerfectScores(){

    // Starting with zero scores
    int perfectScores = 0;

    // Go through all scores, see if any of them are 100s
    for(int i = 0; i < SIZE; i++){
        if(testScores[i] == 100){
            perfectScores++;
        }
    }

    // Return the amount
    return perfectScores;
}

int main(int argc, const char * argv[]) {
  cout << "Welcome to GradeLogger 1.0" << endl;
  cout << "END: Stops the Program" << endl;
  cout << "--------------------------\n" << endl;
  getScores(0,100);
  int perfectScores = totalPerfectScores();
  //TODO : Add welcome and commands
  cout << "\nYou have " << perfectScores << " perfect scores." << endl;
  return 0;
}
