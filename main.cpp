//Programming Rules
//1. You can NOT use std::string or any STL data structure, e.g. std::vector, std::set, std::list


//PART 1 60%
//TODO Take a word from wordlist X
//TODO Scramble word
//TODO Show scrambled word
//TODO Allow user to guess the word
//TODO Loop until user wants to stop

//PART 2 80%
//TODO User can ask for a hint
//TODO The word is shown with dashes, but one random letter is in the correct place.
//TODO For each hint, one correct letter is added.
//TODO User starts with 10 points and loses one point for each hint.
//TODO Implement game rules where 
//Game is either:
//How many words can you guess before you have 0 points.
//or:
//How many points do you have left after 7 words.

//5% BONUS
//The time elapsed since the jumble is shown until the answer is correct is also a factor, deducting points.  
//Find a way to make this work in the overall point calculation.  You can re-invent the entire point calculation if you want.

//PART 3 100%
//TODO Add time as a factor (see 5% bonus on v.B)
//TODO Add highscore table
//TODO For the highscores to be interesting add more ways to calculate scores.  Longer streaks, speed bonuses, etc.
//TODO Store highscores in file.
//TODO Allow user to choose to see top 5 scores or full table.

//5-10% BONUS
// Add extra mode crossword jumble


#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

#include "randGen.h"

using namespace std;

int main() {
    
    bool gameQuit = false;
    bool fileChosen = false;
    bool correctGuess;
    char nameOfFile[32];

    char* quitGameArray = new char[4];
    quitGameArray[0] = 'q';
    quitGameArray[1] = 'u';
    quitGameArray[2] = 'i';
    quitGameArray[3] = 't';
    quitGameArray[4] = '!';
    while (gameQuit == false)
    {
        
        cout << "Please enter a name: "; // Ask user for name of file
        cin >> nameOfFile; // Get their input
        
        
        if (nameOfFile[0] == quitGameArray[0] && nameOfFile[1] == quitGameArray[1] && nameOfFile[2] == quitGameArray[2] && nameOfFile[3] == quitGameArray[3] && nameOfFile[4] == quitGameArray[4])
            {
                gameQuit = true;
                
            }

        
        strcat(nameOfFile, ".txt"); // Add txt ending 
        FILE *word_file_read;
        char word[50];
        char i;
        char randNum;
        i = 0;

    

    
        
        srand (time(NULL));
        randNum = rand()%606;
        char dest[40];



        


        word_file_read = fopen(nameOfFile, "r+");

        if (word_file_read == NULL && gameQuit != true)
        {
            cout << "Cant find the file! \n"; // Ask user for name of file
        }
        else
        {
            fileChosen = true;
            while (fscanf(word_file_read, "%s", word) != EOF)
            {
                if (i == randNum && gameQuit == false)
                {   
                    correctGuess = false;
                    int i = 0;
                    int b = 0;
                    for (b = 0;word[b] != '\0'; b++)
                    {
                        //Mhm counting letters. Maybe use a built in function
                    }
                    
                    i=0;
                    WordScramble *scrambledWord;
                    scrambledWord = new WordScramble();
                    scrambledWord->length = b;
                    char* usersGuess = new char[b];
                    scrambledWord->arrPointer = word;
                    
                    scrambledWord->scrambledArrPointer=ScrambleArray(scrambledWord);
                    cout << scrambledWord << endl;
                    while (correctGuess == false && gameQuit == false){
                        cout << "\nPlease Enter a guess : ";
                        cin >> usersGuess;
                        bool matchingElems = true;
                        for (int k = 0;k < b; k++)
                        {
                            if (k == 0 && usersGuess[0] == quitGameArray[0] && usersGuess[1] == quitGameArray[1] && usersGuess[2] == quitGameArray[2] && usersGuess[3] == quitGameArray[3] && usersGuess[4] == quitGameArray[4])
                            {
                                gameQuit = true;
                                k = b;
                            }
                            if (usersGuess[k] != scrambledWord->arrPointer[k] && gameQuit != true)
                            {
                                cout << "wrong guess dude, try again \n" << scrambledWord->scrambledArrPointer << "\n";
                                k = b;
                                matchingElems = false;
                            } 
                            if (gameQuit == true){
                                cout << "exiting game....";
                            }
                        }
                        if (matchingElems == true)
                        {
                            correctGuess = true;
                        }
                    }
                    delete scrambledWord;
                    delete usersGuess;
                }
                i++;
            }
            fclose(word_file_read);
            
            cout << "were done here!\n";
            delete quitGameArray;
        }
    }
    return 0;
}