#include "autoshop.h"

string promptAddress(){
  string address = "";
  cout << "Address: ";
  cin.ignore();
  getline(cin,address);
  return address;
}

bool promptMake(string &make){
  string cMake = "";
  cout << "Make: ";
  cin >> cMake;

  if(isMakeExist(cMake)){
    make = cMake;
    return true;
  } else {
    //displayMessage(6);
    return false;
  }
}

bool promptModel(string make, string &model){
  string cModel = "";
  cout << "Model: ";
  cin >> cModel;

  if(isModelExist(cModel) && isMakeExist(make)){
    model = cModel;
    return true;
  } else {
    //displayMessage(7);
    return false;
  }

}

string promptName(){
  string name = "";
  cout << "Name: ";
  cin.ignore();
  getline(cin,name);
  return name;
}

string promptPhoneNumber(){
  string number = "";
  cout << "Phone Number: ";
  cin >> number;
  return number;
}

string promptLicensePlate(){
  string number = "";
  cout << "Plate Number: ";
  cin.ignore();
  getline(cin,number);
  return number;
}

int promptYear(){
  int year = 0;

  // Check if the year is even possible
  while (year < 1900 && year > 2017){
    cout << "Manufacturing Year: ";
    cin >> year;
  }

  return year;
}

void promptAll(string &address,string &make, string &model, string &name,
  string &phoneNumber, string &plate, int &year){
  name = promptName();
  address = promptAddress();
  phoneNumber = promptPhoneNumber();
  if (promptMake(make) == false){
    return;
  } else {
    make = make;
  };
  if (promptModel(make, model) == false){
    make = make;
    return;
  } else {
    model = model;
  };
  plate = promptLicensePlate();
  year = promptYear();

}
