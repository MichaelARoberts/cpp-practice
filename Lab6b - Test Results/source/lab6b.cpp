#include <iostream>
#include <string>

using namespace std;

const int SIZE = 20;
int scores[SIZE] = {};
string students[SIZE] = {};

// Amount of times we've accepted input(we can up to 20, but this is the TRUE amount)
int inputTimes = 0;

void getScores(int min, int max){

  // Amount of scores/students
  int count = 0;

  // Score we will be asking the user for
  string score;

  // The score in integer form
  int scoreInt;

  // The students name
  string student;

  while(count <= SIZE){
    cout  << "Student " << count + 1 << endl;
    cout  << "-------" << endl;

    // Get the students name
    cout << "Student's Name: ";
    cin >> student;

    // If the user wants to end, break
    if (student == "END"){
      break;
    }

    // Get the score
    cout << "Score: ";
    cin >> score;

    // If the user wants to end, break
    if (score == "END"){
      break;
    }

    inputTimes++;

    // Covert score to int via character string function
    scoreInt = atoi(score.c_str());

    while (scoreInt < min || scoreInt > max){
        cout << "<!> ERROR: Enter a number between 0 an 100" << endl;
        cin >> scoreInt;
        cout << endl;
    }

    scores[count] = scoreInt;
    students[count] = student;
    // Reset score for while loop
    count++;

    //Add another line to make the output pretty
    cout << endl;
  }
}

int getPerfectScores(){
  // Starting with zero scores
  int perfectScores = 0;

  // Go through all scores, see if any of them are 100s
  for(int i = 0; i < SIZE; i++){
    if(scores[i] == 100){
        perfectScores++;
    }
  }

  // Return the amount
  return perfectScores;
}

// Get the average of the score dataset
int getAverageScore(){
  int average = 0;
  int scoreTotal = 0;

  for(int i = 0; i < inputTimes; i++){
    scoreTotal += scores[i];
  }

  average = scoreTotal/inputTimes;
  return average;
}

// Returns the index of the lowest score
int getLowestScoreIndex(){
  int index = 0;
  int lowest = 0;

  for(int i = 0; i < inputTimes; i++){

    // Set inital as lowest
    if (i == 0 ){
      lowest = scores[i];
    }

    // if lower than previous
    if (scores[i] < lowest){
      lowest = scores[i];
      index = i;
    }
  }

  return index;
}

// Returns the index of the highest score
int getHighestScoreIndex(){
  int index = 0;
  int highest = 0;

  for(int i = 0; i < inputTimes; i++){

    // Set inital as highest
    if (i == 0 ){
      highest = scores[i];
    }

    // if larger than previous
    if (scores[i] > highest){
      highest = scores[i];
      index = i;
    }
  }

  return index;
}

// Turns an int between 0 and 100 into a letter grade
char getLetterGrade(int score){
  char grade;

  // Cutoffs for each letter grade
  const int A_MIN = 90;
  const int B_MIN = 80;
  const int C_MIN = 70;
  const int D_MIN = 60;

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

  return grade;
}

int main(int argc, const char * argv[]) {
  // Welcome Message
  cout << "Welcome to GradeLogger 1.0" << endl;
  cout << "END: Stops the Program" << endl;
  cout << "--------------------------\n" << endl;

  //Fetch our Scores
  getScores(0,100);

  // Get total amount of perfect scores
  int perfectScores = getPerfectScores();
  cout << "\nYou have " << perfectScores << " perfect scores." << endl;

  // Get average as points and grade
  int averageScore = getAverageScore();
  char averageGrade = getLetterGrade(averageScore);
  cout << "The Average is " << averageScore << ", or a " << averageGrade << "." << endl;

  // Get the high and lows of the exam
  int lowestIndex = getLowestScoreIndex();
  int lowestScore = scores[lowestIndex];
  int highestIndex = getHighestScoreIndex();
  int highestScore = scores[highestIndex];

  // Print the highs and the lows
  cout << "The lowest score is " << lowestScore << ", or a " << getLetterGrade(lowestScore) << "." << endl;
  cout << "The highest score is " << highestScore << ", or a " << getLetterGrade(highestScore) << "." << endl;

  cout << "\n===========" << endl;
  cout << "EXAM REPORT" << endl;
  cout << "-----------" << endl;
  // Output all the students results
  for(int i = 0; i < inputTimes; i++){
    cout << "Name: ";
    cout << students[i] << endl;
    cout << "Score: ";
    cout << scores[i] << endl;
    cout << "Grade: ";
    cout << getLetterGrade(scores[i]) << endl;
    cout << endl;
  }

  return 0;
}
