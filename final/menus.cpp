#include "autoshop.h"

string phoneNumbers[SLOTS];
string addresses[SLOTS];
string names[SLOTS];
string licensePlates[SLOTS];
string makes[SLOTS];
string models[SLOTS];
bool readys[SLOTS];
int years[SLOTS];

void displayQueue(string pnums[] = phoneNumbers,
  string addrs[] = addresses,
  string nms[] = names,
  string lps[] = licensePlates,
  string mks[] = makes,
  string mdls[] = models,
  int yrs[] = years){

    for (int i = 0; i < SLOTS; i++){
      cout <<  lps[i] << " " << mks[i] << " " << mdls[i] << " " << yrs[i] << " " <<
      nms[i] << " " <<  pnums[i] << endl;
    }

}

void addData(string phoneNumber, string address, string name,
  string licensePlate, string make, string model, int year){

  ofstream clientFile;
  clientFile.open("data.client", std::ofstream::out | std::ofstream::app);
  clientFile << name << "\n";
  clientFile << address << "\n";
  clientFile << phoneNumber << "\n";
  clientFile << licensePlate << "\n";
  clientFile << make << "\n";
  clientFile << model << "\n";
  clientFile << year << "\n";
  clientFile.close();
}

void loadData(int index, string searchKey, string pnums[] = phoneNumbers,
  string addrs[] = addresses,
  string nms[] = names,
  string lps[] = licensePlates,
  string mks[] = makes,
  string mdls[] = models,
  int yrs[] = years){

    ifstream client("data.client");
    string line;

    string fName;
    string fAddress;
    int count = 1;

    while(getline(client,line)){
      switch (count){
        case 1:
          fName = line;
          count++;
          break;
        case 2:
          fAddress = line;
          count++;
          break;
        case 3:
          if (searchKey == line){
            pnums[index] = line;
            nms[index] = fName;
            addrs[index] = fAddress;
            getline(client,line);
            lps[index] = line;
            getline(client,line);
            mks[index] = line;
            getline(client,line);
            mdls[index] = line;
            getline(client,line);
            yrs[index] = stoi(line);
            count = 0;
          }
          break;
      }
    }

}

void checkInCar(string pnums[] = phoneNumbers,
  string addrs[] = addresses,
  string nms[] = names,
  string lps[] = licensePlates,
  string mks[] = makes,
  string mdls[] = models,
  int yrs[] = years){

  }

void checkOutCar(string pnums[] = phoneNumbers,
  string addrs[] = addresses,
  string nms[] = names,
  string lps[] = licensePlates,
  string mks[] = makes,
  string mdls[] = models,
  int yrs[] = years, bool rdys[] = readys){

  }

char mainMenu(){
  char choice;

  while ( choice != 's'  && choice != 'm' && choice != 'q'){
    cout <<  "Please Choose an Option:" << endl;
    cout << string(24, '-') << endl;
    cout << "[S] Staff's Operations" << endl;
    cout << "[M] Mechanics's Operations" << endl;
    cout << "[Q] Terminate the System" << endl;
    cout << "[?] ";
    cin >> choice;
    choice = tolower(choice);
    cout << endl;
  }
  return choice;
}

char mechanicMenu(){
  char choice;

  while ( choice != 'd'  && choice != 'o' && choice != 'r'){
    cout <<  "Please Choose an Option:" << endl;
    cout << string(24, '-') << endl;
    cout << "[D] Display all cars in queue" << endl;
    cout << "[O] Check-out a car" << endl;
    cout << "[R] Return to main menu" << endl;
    cout << "[?] ";
    cin >> choice;
    choice = tolower(choice);
    cout << endl;
  }
  return choice;
}

char staffMenu(){
  char choice;

  while ( choice != 'i'  && choice != 'o' && choice != 's' && choice != 'd' && choice != 'r'){
    cout <<  "Please Choose an Option:" << endl;
    cout << string(24, '-') << endl;
    cout << "[I] Check a new car into queue" << endl;
    cout << "[O] Check-out a car" << endl;
    cout << "[S] Check the status of a car" << endl;
    cout << "[D] Display all cars in queue" << endl;
    cout << "[R] Return to main menu" << endl;
    cout << "[?] ";
    cin >> choice;
    choice = tolower(choice);
    cout << endl;
  }
  return choice;
}

void staffNexus(){
  string address;
  string make;
  string model;
  string name;
  string phoneNumber;
  string plate;
  int year;
  char schoice;

  schoice = staffMenu();
  string key;
  int index;

  switch(schoice){
    case 'i':
      promptAll(address,make,model,name,phoneNumber,plate,year);
      addData(phoneNumber,address,name,plate,make,model,year);
    case 'o':
      break;
    case 's':
      break;
    case 'd':
      initalizeArray(addresses);
      initalizeArray(makes);
      initalizeArray(models);
      initalizeArray(names);
      initalizeArray(phoneNumbers);
      initalizeArray(licensePlates);
      initalizeArray(years);
      index = findNextOpeningSlot(phoneNumbers);
      key = promptPhoneNumber();
      loadData(index,key);
      displayQueue();
    case 'r':
      menuNexus();
      break;
  }
}

void mechanicNexus(){
  string address;
  string make;
  string model;
  string name;
  string phoneNumber;
  string plateNumber;

  char mchoice;
  string key;
  int index;
  mchoice = mechanicMenu();

  switch(mchoice){
    case 'd':
      initalizeArray(addresses);
      initalizeArray(makes);
      initalizeArray(models);
      initalizeArray(names);
      initalizeArray(phoneNumbers);
      initalizeArray(licensePlates);
      initalizeArray(years);
      index = findNextOpeningSlot(phoneNumbers);
      key = promptPhoneNumber();
      loadData(index,key);
      displayQueue();
      break;
    case 'o':
      break;
    case 'r':
      menuNexus();
      break;
  }
}

void menuNexus(){
  char choice = mainMenu();

  switch (choice) {
    case 's':
      staffNexus();
      //break;
    case 'm':
      mechanicNexus();
      //break;
    case 'q':
      exit(0);
      //break;
  }
}
