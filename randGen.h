#ifndef RANDGEN_ASSIGNMENT2
#define RANDGEN_ASSIGNMENT2

#include <iostream>

using namespace std;

class WordScramble{
    public:
        int length;
        char* arrPointer;
        char* scrambledArrPointer;
        char* hintPointer;
        char* hintArr;
        int numOfGuesses;
        int* guessIndexes;
        int numOfHints;
        void generateHints(WordScramble *wordscramble){
        if(wordscramble->numOfHints != wordscramble->length){
            int hintIndex = wordscramble->guessIndexes[wordscramble->numOfHints];
            char hintLetter = wordscramble->arrPointer[hintIndex];
            wordscramble->hintArr[hintIndex] = hintLetter;
            wordscramble->numOfHints++;
            }
        };
        

        friend char* ScrambleArray(WordScramble *wordscramble);
        friend ostream& operator<<(ostream& out, WordScramble *wordscramble);
        

        ~WordScramble() 
        {
            cout << "Object is being deleted" << endl;
        }
};

char* generateHintArray(char Word[]);
int* orderOfGuessesArr(char word[]);
void swap (int arr[], int n);
void randomize(int arr[], int n);
void fischerYates(int arr[], int arrLength);


#endif //RANDGEN_ASSIGNMENT2