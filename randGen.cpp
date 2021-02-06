#include <time.h> 
#include "randGen.h"
using namespace std;

//Overide out<< operator to output the entire data bank of the word
ostream& operator<<(ostream& out, WordScramble *wordscramble){
    out << "This is the length: " << wordscramble->length << " This is the word: " << wordscramble->arrPointer << " This is the scrambled word: " << wordscramble->scrambledArrPointer;
    return out;
}

// Iterates over the index array and checks if the randNum has already come up before
// returns false if it hasn't
bool checkIndexArray(int num, int arr[], int arrSize){
    for (int i = 0; i<arrSize; i++){
        if(arr[i] == num){
            return true;
        }
    }

    return false;
};


bool checkCharAtIndex(char letter, char arr[], int index){
    if(arr[index]==letter){
        return true;
    }
    return false;
}
 

char* ScrambleArray(WordScramble *wordscramble) {
      
    char* myWord = wordscramble->arrPointer;
    int arrLength = wordscramble->length;
    int arrMaxPos = arrLength -1;
    int highRoll = arrLength;

    int* rand_index_array = new int[arrLength]; //Make sure to delete dead arrays after running
    char* scrambled_arr = new char[arrLength];
    int* used_ind = new int[arrLength];
    
    for (int i=0; i<arrLength;i++){

        int randomNum = rand()%arrMaxPos;
        char letter = myWord[randomNum];

        // checks if index is in the array
        bool indexInArray = checkIndexArray(randomNum, rand_index_array, arrMaxPos);

        // check space is occupied
        // due to random being not so random, just rotate the letter until a space is found   
        while(indexInArray){ 
            if (randomNum == arrMaxPos)
            {
                randomNum = 0;
                indexInArray = checkIndexArray(randomNum, rand_index_array, arrMaxPos);
            }
            else{
                randomNum++;
                indexInArray = checkIndexArray(randomNum, rand_index_array, arrMaxPos);
            }
        };  
        cout << randomNum << endl;
        // Finally write the new index to rand_index_array and the scrambled letter to the scrambled letter array
        rand_index_array[i] = randomNum;
        scrambled_arr[i] = myWord[randomNum];
    };

    wordscramble->scrambledArrPointer = scrambled_arr;
    delete rand_index_array;
    delete used_ind;
    
    return scrambled_arr;
    
};