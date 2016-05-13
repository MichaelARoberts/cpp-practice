#include "autoshop.h"

void displayMessage(int messageCode){
  cout << "<!> ";
  switch(messageCode){
    case 0:
      cout << "No Error" << endl;
      break;
    case 1:
      cout << "Invalid Selection" << endl;
      break;
    case 2:
      cout << "System Shutting Down" << endl;
      break;
    case 3:
      cout << "Invalid Phone Number" << endl;
      break;
    case 4:
      cout << "Invalid Name" << endl;
      break;
    case 5:
      cout << "Invalid Address" << endl;
      break;
    case 6:
      cout << "Invalid Make" << endl;
      break;
    case 7:
      cout << "Invalid Model" << endl;
      break;
    case 8:
      cout << "Invalid Year" << endl;
      break;
    case 9:
      cout << "Invalid Liscense Plate" << endl;
      break;
    case 10:
      cout << "No Opening Slot" << endl;
      break;
    case 11:
      cout << "No Such Car" << endl;
      break;
    case 12:
      cout << "Client File Does Not Exsist" << endl;
      break;
    case 13:
      cout << "Make File Does Not Exsist" << endl;
      break;
    case 14:
      cout << "Model File Does Not Exsist" << endl;
      break;
    case 15:
      cout << "Car is Not Yet Ready" << endl;
      break;
    case 16:
      cout << "Car is Ready" << endl;
      break;
    case 17:
      cout << "Car Already in Queue" << endl;
      break;
    case 18:
      cout << "Car is Checked-Out" << endl;
      break;
  }
}
