#include "autoshop.h"

bool isClientExist(string phoneNumber){
  ifstream contract("data.client");
  string line;
  while(getline(contract,line)){
    if (line.find(phoneNumber) == string::npos){
      //cout << "Found the Make" << endl;
      return true;
    }
  }
  return false;
}
