#include "autoshop.h"

void initalizeArray(bool boolArray[]){
  for (int i = 0; i < SLOTS; i++){
    boolArray[i] = false;
  }
}

void initalizeArray(int intArray[]){
  for (int i = 0; i < SLOTS; i++){
    intArray[i] = 0;
  }
}

void initalizeArray(string stringArray[]){
  for (int i = 0; i < SLOTS; i++){
    stringArray[i] = "";
  }
}
