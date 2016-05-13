#include "autoshop.h"

void displayLogo() {

  // Types Champlain
  cout << " _____ _                           _       _       " << endl;
  cout << "/  __ \\ |                         | |     (_)      " << endl;
  cout << "| /  \\/ |__   __ _ _ __ ___  _ __ | | __ _ _ _ __  " << endl;
  cout << "| |   | '_ \\ / _` | '_ ` _ \\| '_ \\| |/ _` | | '_ \\ " << endl;
  cout << "| \\__/\\ | | | (_| | | | | | | |_) | | (_| | | | | |" << endl;
  cout << " \\____/_| |_|\\__,_|_| |_| |_| .__/|_|\\__,_|_|_| |_|" << endl;
  cout << "                            | |                    " << endl;
  cout << "                            |_|                    " << endl;

  // Types Garage
  cout << " _____                            " << endl;
  cout << "|  __ \\                           " << endl;
  cout << "| |  \\/ __ _ _ __ __ _  __ _  ___ " << endl;
  cout << "| | __ / _` | '__/ _` |/ _` |/ _ \\" << endl;
  cout << "| |_\\ \\ (_| | | | (_| | (_| |  __/" << endl;
  cout << " \\____/\\__,_|_|  \\__,_|\\__, |\\___|" << endl;
  cout << "                        __/ |     " << endl;
  cout << "                       |___/      " << endl;


}

void clearScreen() {
  cout << string(100, '\n');
}

void pauseSystem(){
  int exit;

  cout << "Press any Key to Continue...";
  cin >> exit;
}

int findNextOpeningSlot(string phoneNumbers[]){
  for (int i = 0; i < SLOTS; i++) {
    if (phoneNumbers[i] == ""){
      return i;
    }
  }

  return -1;

}
