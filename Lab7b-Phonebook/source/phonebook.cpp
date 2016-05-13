#include "phonebook.h"


void getPhoneNumbers(string numbers[], string file){
  ifstream infile(file);
  string line;
  int count = 1;
  int size = 0;

  while(getline(infile,line)){
    if (!(count % 2)){
      if (regex_match(line, PHONEREG) ){
        numbers[size] = line;
        size++;
      } else {
        cout << "<!> Invalid Phone Number on line " << count << endl;
        break;
      }
    }
    count++;
  }
}


void getNames(string names[], string file){
  ifstream infile(file);
  string line;
  int count = 1;
  int size = 0;

  while(getline(infile,line)){
    if (count % 2){
      names[size] = line;
      size++;
    }
    count++;
  }
}


void printPhonebook(string numbers[], string names[]){
  for (int i = 0; i < BOOKSIZE; i++){
    if (!names[i].empty() && !numbers[i].empty()){
      cout << names[i] << ": " << numbers[i] << endl;
    } else {
      break;
    }
  }

  cout << "\n";
}


void numberLookup(string name, string names[], string numbers[]){
  for (int i = 0; i < BOOKSIZE; i++){
    if (!names[i].empty()){
      if(names[i] == name){
        cout << numbers[i] << endl;
      }
    } else {
      break;
    }
  }
}


void nameLookup(string number, string names[], string numbers[]){
  for (int i = 0; i < BOOKSIZE; i++){
    if(numbers[i] == number){
      cout << names[i] << endl;
    }
  }
}
