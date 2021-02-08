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
    int arrMaxPos = arrLength - 1;
    int* rand_index_array = new int[arrLength+1]; //Make sure to delete dead arrays after running
    char* scrambled_arr = new char[arrLength+1];
    wordscramble->numOfGuesses = 0;
    char* hintArr = new char[arrLength+1];
    int * guessArr = new int[arrLength+1];
    wordscramble->numOfHints = 0;

    for (int i=0; i<arrLength; i++){
        hintArr[i] = '-';
    };

    wordscramble->hintArr = hintArr;

    for (int i=0; i<arrLength; i++){
        guessArr[i] = i;
    };

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
        // Finally write the new index to rand_index_array and the scrambled letter to the scrambled letter array
        rand_index_array[i] = randomNum;
        scrambled_arr[i] = myWord[randomNum];
    };
    scrambled_arr[arrLength] = '\0';
    
    wordscramble->scrambledArrPointer = scrambled_arr;
    wordscramble->hintPointer = hintArr;
    fischerYates(guessArr, arrLength);
    // creates another randomized index array
    wordscramble->guessIndexes = guessArr;
    hintArr[arrLength] = '\0';


    delete rand_index_array;
    return scrambled_arr;

};


void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
};


void randomize(int arr[], int n){
    srand(time(NULL));

    for (int i= n-1; i>0; i--){
        int j = rand () % (i);

        swap(&arr[i], &arr[j]);
    }

};

// lets try out fischer-yates for this
void fischerYates(int arr[], int arrLength){
    int n = arrLength;
    randomize(arr, n);
    for(int i=0; i<arrLength; i++){
        cout << arr[i];
    }

};

