#include "highscores.h"
#include <iostream>
using namespace std;
    
//Function for comparing highscores. 
//If the first highscore passed in is bigger than the next the function returns true
//Else false 
bool compareHighScores(Scores score1, Scores score2){
    if (score1.score > score2.score){
        return true;
    }
    return false;
};


//Find the index of the first number that the passed in score is larger than
int findIndex(Scores arr[], Scores score, int arrSize){
    int counter = 0;
    for(counter; counter < arrSize; counter++){
        if (score.score>arr[counter].score){
            return counter;
        };
    };
    return counter;
};


// This essentially swaps the elements and set tmp to the next one
void moveElements (Scores arr[], int index, Scores tmp){
    Scores next_tmp = arr[index];
    arr[index] = tmp;
    tmp = next_tmp;
};


//Places a score in the correct postition within the leaderboard
void putScoreInRightPlace(Scores arr[], Scores userscore, int index, int arrLength){
    Scores *tmp = new Scores[arrLength];
    for (int i=0; i< arrLength; i++){
        if(i==index){
            tmp[index] = userscore;
            i++;
        };
        if(i<index){
            tmp[i] = arr[i];
        }

        if (i>index){
            tmp[i] = arr[i-1];
        }
    };
    for (int i=0; i< arrLength; i++){
        arr[i] = tmp[i];
    }

};


void driverCodeForOrdering(Scores userscore, Scores arr[], int arrLength) {
    // start by checking if the lowest score in the array is smaller then the new score
    //if its empty beforehand
    if (arrLength == 1){
        arr[0] = userscore;
        return;
    }
    if(!compareHighScores(userscore, arr[arrLength-2])){
        arr[arrLength-1] = userscore;
        return;
    };

    // finding the index
    int index = findIndex(arr, userscore, arrLength);

    // and moving the rest of the array
    putScoreInRightPlace(arr, userscore, index, arrLength);
};