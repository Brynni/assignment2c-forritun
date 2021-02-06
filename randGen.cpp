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

    int* rand_index_array = new int[arrLength]; //Make sure to delete dead arrays after running
    char* scrambled_arr = new char[arrLength];
    int* used_ind = new int[arrLength];
    // maybe this will make it faster idno
    for (int i=0; i<arrLength; i++){
        used_ind[i] = i;
        };

    for (int i=0; i<arrLength;i++){

        int randomNum = rand() % arrLength;
        
        char letter = myWord[randomNum];

        // checks if index is in the array
        bool indexInArray = checkIndexArray(randomNum, rand_index_array, arrLength);

        // check if myArr[i] contains the same letter
        //bool charInArr = checkCharAtIndex(letter, myWord, i);
        // While both are true generate a random number and check both again   
        while(indexInArray){ //|| charInArr){
            srand (time(NULL));
            randomNum = rand () % arrLength;
            
            letter = myWord[randomNum];
            indexInArray = checkIndexArray(randomNum, rand_index_array, arrLength);

            if(indexInArray && i==arrLength-1){
                // Okay this is just a shortcut for finding the last letter
                bool checker = false;
                while(!checker){
                    for(int j=0; j<arrLength; j++){
                        if(used_ind[j]!=100){
                            randomNum = used_ind[j];
                            indexInArray = false;
                            checker = true;
                        }
                    }
                } 

            };



            //charInArr = checkCharAtIndex(letter, myWord, i);
        };  
        cout << randomNum << endl;
        // Finally write the new index to rand_index_array and the scrambled letter to the scrambled letter array
        rand_index_array[i] = randomNum;
        scrambled_arr[i] = myWord[randomNum];
        //idno
        used_ind[randomNum] = 100;
        //cout << "used arr: "<<*used_ind;
    };

    scrambled_arr[arrLength] = '\0'; 
    wordscramble->scrambledArrPointer = scrambled_arr;
    delete rand_index_array;
    return scrambled_arr;
    
};