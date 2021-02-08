//Programming Rules
//1. You can NOT use std::string or any STL data structure, e.g. std::vector, std::set, std::list


//PART 1 60%
//TODO Take a word from wordlist X
//TODO Scramble word X
//TODO Show scrambled word X
//TODO Allow user to guess the word X 
//TODO Loop until user wants to stop X

//PART 2 80%
//TODO User can ask for a hint X 
//TODO The word is shown with dasches, but one random letter is in the correct place. X
//TODO For each hint, one correct letter is added. X 
//TODO User starts with 10 points and loses one point for each hint. X
//TODO Implement game rules where 
//Game is either:
//How many words can you guess before you have 0 points. X
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
#include <iomanip>

#include "randGen.h"
#include "player.h"
#include "highscores.h"

using namespace std;

int main() {
    
    int numberOfLines = 0;

    bool gameQuit = false;
    bool hintActivated = false;
    bool hintAskedFor = false;
    bool fileChosen = false;
    bool correctGuess;
    
    char nameOfFile[128];

    char* quitGameArray = new char[4];
    quitGameArray[0] = 'q';
    quitGameArray[1] = 'u';
    quitGameArray[2] = 'i';
    quitGameArray[3] = 't';
    quitGameArray[4] = '!';

    char* hintGameArray = new char[4];
    hintGameArray[0] = 'h';
    hintGameArray[1] = 'i';
    hintGameArray[2] = 'n';
    hintGameArray[3] = 't';
    hintGameArray[4] = '!';

    Player *player;
    player = new Player();
    player -> pointCount = 0;
    player -> amountOfLives = 10;

    FILE *word_file_read;
    FILE *word_file_read_amount_lines;
    while (gameQuit == false)
    {
        if (player -> amountOfLives != 0)
        {
            if (fileChosen == false)
            {
                cout << "Please enter a filename: "; // Ask user for name of file
                cin >> setw(127) >>nameOfFile; // Get their input
                strcat(nameOfFile, ".txt"); // Add txt ending 
                
            }
            
            if (nameOfFile[0] == quitGameArray[0] && nameOfFile[1] == quitGameArray[1] && nameOfFile[2] == quitGameArray[2] && nameOfFile[3] == quitGameArray[3] && nameOfFile[4] == quitGameArray[4])
                {
                    gameQuit = true;
                }
            
            cout << "Game Rules: " << endl;
            cout << "You start the game with 10 lives, for each hint that you take you loose a live " << endl;
            cout << "You have unlimmited guesses to guess each word but you can always get a hint by typing: hint!" << endl;
            cout << "Upon reaching 0 lives you will start a new game" << endl;
            cout << "However you can always type: quit! to stop playing" << endl;
            cout << "   " << endl;
            cout << "   " << endl;
            cout << "   " << endl;
 
            //Setup the word which will be on the stack
            char word[50];
            char i;
            char randNum;
            i = 0;
            //Generate seed and generate the random num
            srand (time(NULL));

            word_file_read = fopen(nameOfFile, "r+");

            if (word_file_read == NULL && gameQuit != true)
            {
                cout << "Cant find the file! \n"; // Ask user for name of file
            }
            else
            {
                word_file_read_amount_lines = fopen(nameOfFile, "r+");
                while (fscanf(word_file_read_amount_lines, "%s", word) != EOF)
                {
                    numberOfLines++;
                }
                randNum = rand()%numberOfLines;
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
                        while (correctGuess == false && gameQuit == false && player -> amountOfLives > 0){
                            cout << "\nPlease Enter a guess : ";
                            cin >> usersGuess;
                            bool matchingElems = true;
                            for (int k = 0;k < b; k++)
                            {
                                //Check if the input is "hint!"
                                //If hint, mark as hint and generate hint
                                if (k == 0 && usersGuess[0] == hintGameArray[0] && usersGuess[1] == hintGameArray[1] && usersGuess[2] == hintGameArray[2] && usersGuess[3] == hintGameArray[3] && usersGuess[4] == hintGameArray[4])
                                {
                                    hintAskedFor = true;
                                    k = b;
                                    matchingElems = false;
                                    player -> amountOfLives --;
                                    // Call the new function. See this for example scrambledWord->scrambledArrPointer=ScrambleArray(scrambledWord);
                                    scrambledWord->generateHints(scrambledWord);
                                    cout << scrambledWord->scrambledArrPointer << "\n";
                                    // but with the hint thingy rather
                                    if(hintActivated == false)
                                    {
                                        hintActivated = true;
                                    }
                                }
                                
                                //Check if input is "quit!"
                                //If input is == quit then mark the counter as finished and change the quit bool to true
                                if (k == 0 && usersGuess[0] == quitGameArray[0] && usersGuess[1] == quitGameArray[1] && usersGuess[2] == quitGameArray[2] && usersGuess[3] == quitGameArray[3] && usersGuess[4] == quitGameArray[4])
                                {
                                    gameQuit = true;
                                    k = b;
                                }
                                
                                //Check if the char matches the correct string char
                                //If it fails output the message alerting of the players failure and mark the matching elems as false;
                                if (usersGuess[k] != scrambledWord->arrPointer[k] && gameQuit != true && hintAskedFor == false)
                                {
                                    cout << "wrong guess dude, try again \n" << scrambledWord->scrambledArrPointer << "\n";
                                    k = b;
                                    matchingElems = false;
                                } 
                                
                                //If this not here it 
                                else{
                                    hintAskedFor = false;
                                }

                            }
                            if (matchingElems == true)
                            {
                                correctGuess = true;
                                hintActivated = false;
                                player -> pointCount ++;
                            }
                            if (hintActivated == true)
                            {
                                for (int i = 0; i<scrambledWord->length;i++){
                                        cout << scrambledWord->hintArr[i];
                                    }
                                    cout << "   " << endl;
                            }
                            cout << "Lives left: " << player -> amountOfLives << endl ;
                            cout << "Current score: "<< player -> pointCount << endl;
                        }
                        delete scrambledWord;
                        delete usersGuess;
                    }
                    i++;
                }
            
            }
        }
        else {
            cout << "Gameover Bucko!" << endl;
            cout << player -> pointCount  << endl;
            player->PlayerName = new char[3];


            cout << "Enter name for highscore table: ";
            cin >> player->PlayerName;
            Scores userscore = Scores();
            userscore.score = player->pointCount;
            userscore.username = player->PlayerName;
            FILE *highscore_file_read;
            FILE *highscore_read_amount_lines;
            char high_score_file[50];
            char line [50];
            int hs_number_of_lines = 0;
            
            cout << "Please enter a filename: "; // Ask user for name of file
                cin >> setw(127) >>high_score_file; // Get their input
                strcat(high_score_file, ".txt"); // Add txt ending 
            cout << high_score_file;
    	    highscore_file_read = fopen(high_score_file, "r+");
            highscore_read_amount_lines = fopen(high_score_file, "r+");
                while (fscanf(highscore_read_amount_lines, "%s", line) != EOF)
                {
                    hs_number_of_lines++;
                };
            
            // creates an array of struts of the wished for size
            // the size is /2 cuz we always get an even number size 
            // because every line contains two lines or something, the socre and the name

            Scores *allHighscores  = new Scores[hs_number_of_lines/2];

            // even numbers are names
            // odd numbers are the score
            
            for (int i=0; i<hs_number_of_lines; i=i+2){
                
                cout << "creating obj number: " << i;
                // TODO
                // Here we should create the structs and add it to the Scores Array 
                // should be doing something like :
                // struct tmp = new struct()
                // tmp.name = line[i] or something
                // tmp.int = int(line [i+1])
            };

            // so we need to create a struct for each obj
            // each struct consists of name and score

            // TODO
            // Here we would put the new score in its correct position


            //TODO 
            // Write the new arr to the file


            // TODO maybe add a way for the user to see all the highscores in the file?


            
            cout << endl;
            player -> pointCount = 0;
            player -> amountOfLives = 10;
            system("pause");
            
        }
    }
    fclose(word_file_read);
            
    cout << "exiting game...." << endl;
    delete quitGameArray;
    delete hintGameArray;
    return 0;
}