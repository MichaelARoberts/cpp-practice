#include "autoshop.h"


bool isMakeExist(string make){
  ifstream contract("data.contract");
  string line;
  while(getline(contract,line)){
    if (strstr(line.c_str(),make.c_str())){
      //cout << "Found the Make" << endl;
      return true;
    }
  }

  return false;
}

bool isModelExist(string model){
  ifstream contract("data.contract");
  string line;
  while(getline(contract,line)){
    if (strstr(line.c_str(),model.c_str())){
      //cout << "Found the Model" << endl;
      return true;
    }
  }
  return true;
}
