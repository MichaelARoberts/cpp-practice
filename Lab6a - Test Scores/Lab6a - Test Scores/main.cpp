//
//  main.cpp
//  Lab6a - Test Scores
//
//  Created by Michael Roberts on 4/7/16.
//  Copyright © 2016 Michael Roberts. All rights reserved.
//

#include <iostream>

using namespace std;

int testScores[20] = {};
const int SIZE = 20;

void getScores(int min, int max){
    
    int score = -1;
    
    for (int i = 0; i < SIZE; i++){
        cout  << "Score " << i + 1 << endl;
        cout  << "-------" << endl;
        while (score < min || score > max){
            cout << "What is the score?" << endl;
            cin >> score;
            cout << endl;
        }
        
        testScores[i] = score;
        
        // Reset score for while loop
        score = -1;
    }
}

int totalPerfectScores(){
    int perfectScores = 0;
    for(int i = 0; i < SIZE; i++){
        if(testScores[i] == 100){
            perfectScores++;
        }
    }
    return perfectScores;
}

int main(int argc, const char * argv[]) {
    getScores(0,100);
    int perfectScores = totalPerfectScores();
    
    cout << "You have " << perfectScores << " perfect scores." << endl;
    return 0;
}
