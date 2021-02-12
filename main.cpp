//Programming Rules
//1. You can NOT use std::string or any STL data structure, e.g. std::vector, std::set, std::list

#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include <iomanip>
#include <chrono>


#include "randGen.h"
#include "player.h"
#include "highscores.h"

using namespace std;

int main() {
    
    int numberOfLines = 0;
    bool gameQuit = false;
    bool gameStarted = false;
    bool hintActivated = false;
    bool hintAskedFor = false;
    bool fileChosen = false;
    bool fileRead = false;
    bool correctGuess;
    time_t start,end;
    
    char nameOfFile[128];

    char* quitGameArray = new char[5];
    quitGameArray[0] = 'q';
    quitGameArray[1] = 'u';
    quitGameArray[2] = 'i';
    quitGameArray[3] = 't';
    quitGameArray[4] = '!';
    quitGameArray[5] = '\0';

    char* hintGameArray = new char[5];
    hintGameArray[0] = 'h';
    hintGameArray[1] = 'i';
    hintGameArray[2] = 'n';
    hintGameArray[3] = 't';
    hintGameArray[4] = '!';
    hintGameArray[5] = '\0';

    Player *player;
    player = new Player();
    player -> pointCount = 0;
    player -> amountOfLives = 10;
    player -> comboCount = 0;

    FILE *word_file_read;
    FILE *word_file_read_amount_lines;
    while (gameQuit == false)
    {
        if (player -> amountOfLives != 0)
        {
            if (fileChosen == false)
            {
                cout << "Please enter a filename: "; // Ask user for name of file
                cin >> setw(122) >>nameOfFile; // Get their input
                cin.ignore(1000,'\n');
                strcat(nameOfFile, ".txt\0"); // Add txt ending 
                fileChosen = true;
            }
            
            if (nameOfFile[0] == quitGameArray[0] && nameOfFile[1] == quitGameArray[1] && nameOfFile[2] == quitGameArray[2] && nameOfFile[3] == quitGameArray[3] && nameOfFile[4] == quitGameArray[4])
                {
                    gameQuit = true;
                }

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
                fileChosen = false;
            }
            else
            {

                word_file_read_amount_lines = fopen(nameOfFile, "r+");
                if (fileRead == false)
                {
                    while (fscanf(word_file_read_amount_lines, "%s", word) != EOF)
                    {
                        numberOfLines++;
                    }
                    fileRead = true;
                }
                
                randNum = rand()%numberOfLines;
                if (gameStarted == false)
                    {
                        
                        cout << "Game Rules: " << endl;
                        cout << "You start the game with 10 lives, for each hint that you take you loose a live " << endl;
                        cout << "You have unlimmited guesses to guess each word but you can always get a hint by typing 'hint!'" << endl;
                        cout << "Upon reaching 0 lives you will start a new game" << endl;
                        cout << "However you can always type: quit! to stop playing" << endl;
                        cout << "Solve the word within in 30 seconds for a speed bonus!" << endl;
                        cout << "Combo bonuses stack! So try to be fast!" << endl;
                        cout << "   " << endl;
                        cout << "   " << endl;
                        // To allow the player to read the rules
                        system("pause");
                        gameStarted = true;

                    }
                while (fscanf(word_file_read, "%s", word) != EOF)
                {
                    if (i == randNum && gameQuit == false)
                    {   
                        time (&start);
                        correctGuess = false;
                        int i = 0;
                        int b = 0;
                        for (b = 0;word[b] != '\0'; b++)
                        {
                            //Mhm counting letters. Maybe use a built in function
                        }
                        
                        //Create a word scramble
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
                            cin.ignore(1000,'\n');
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
                                    matchingElems = false;
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
                                player -> pointCount = player -> pointCount + player -> comboCount + 1;
                                time (&end);
                            }
                            if (hintActivated == true)
                            {
                                for (int i = 0; i<scrambledWord->length;i++){
                                        cout << scrambledWord->hintArr[i];
                                    }
                                    cout << "   " << endl;
                            }
                            cout << player;
                            
                        }
                        double dif = difftime (end,start);
                        
                        if(dif < 30 && gameQuit == false){
                            player -> comboCount ++;
                            cout << "Speed bonus! COMBO! X" << player -> comboCount << " points!" << endl;
                            if (player -> comboCount > 2){
                                cout << "You're on fire!!! KEEP GOING!" << endl;
                            }
                        }
                        else{
                            player -> comboCount = 0;
                            cout << "You're too slow! COMBO LOST!" << endl;
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
            player->PlayerName = new char[4];


            cout << "Enter 3 Initials for highscore table: ";
            cin >> setw(4) >> player->PlayerName;
            cin.ignore(1000,'\n');
            player->PlayerName[4] = '\0';
            
            Scores userscore = Scores();
            userscore.score = player->pointCount;
            userscore.username = player->PlayerName;
            cout << userscore.username << endl;
            FILE *highscore_file_read, *highscore_read_amount_lines, *hs_fr, *hs_all_scores;
            char high_score_file[180];
            char line [50];
            int hs_number_of_lines = 0;
            
            
            cout << "Please enter a filename if in terminal type hs else copy paste full path : "; // Ask user for name of file
                cin >> setw(127) >>high_score_file; // Get their input
                
                strcat(high_score_file, ".txt"); // Add txt ending 
    	    highscore_file_read = fopen(high_score_file, "r+");
            highscore_read_amount_lines = fopen(high_score_file, "r+");

            // Getting number of lines in highscore file
            while (fscanf(highscore_read_amount_lines, "%s", line) != EOF)
            {
                hs_number_of_lines++;
            };

            

            Scores *all_high_scores = new Scores[(hs_number_of_lines/2)+1];

            
            int counter = 0;
            int arrIndex = 0;
            int *highscores = new int[(hs_number_of_lines/2)];
            hs_fr = fopen(high_score_file, "r+");
            hs_all_scores = fopen(high_score_file, "r+");


            // Creates an array of Score structs
            while (fscanf(hs_all_scores, "%s", line) != EOF)
            {
                Scores *tmp = new Scores();
                if (counter % 2 == 0){
                    char *usrname = new char[4];
                    int a = 0;
                    while(line[a] != '\0'){
                        usrname[a] = line[a];
                        a++;
                    };
                    usrname[3] ='\0';
                    tmp->username = usrname;
                    all_high_scores[arrIndex] = *tmp;
                }


                // read the ints
                else{
                    char* scoreing  = new char[30];
                    int a = 0;
                    while(line[a] != '\0'){
                        scoreing[a] = line[a];
                        a++;
                    };
                    int score  = atoi(scoreing);
                    all_high_scores[arrIndex].score = score;
                    delete scoreing;
                    arrIndex ++;
                }
                counter++;
            };

            fclose(highscore_file_read);
            fclose(hs_fr);
            // Here we would put the new score in its correct position
            driverCodeForOrdering(userscore, all_high_scores, (hs_number_of_lines/2)+1);

            // Great now we need to write it to the text file which for some reason isn't working

            ofstream fout;
            fout.open(high_score_file);
            for (int i= 0; i<hs_number_of_lines/2 +1; i++){
                if (i < hs_number_of_lines/2){
                    fout << all_high_scores[i].username << ' ' << all_high_scores[i].score << '\n';
                }
                else{
                    fout << all_high_scores[i].username << ' ' << all_high_scores[i].score;
                }
                
            }
            fout.close();
            char input [1];

            cout << "Would you like to: " << endl;
            cout << "1. See all highscores " << endl;
            cout << "2. See top five scores " << endl;
            cout << "3. Don't see anything: " << endl;

            cin >> setw(2) >> input;
            cin.ignore(1000,'\n');

            if (input[0] == '1'){
                for (int i = 0; i<hs_number_of_lines/2 + 1; i++){
                    cout << i+1 <<". USERNAME: " << all_high_scores[i].username << '\t' << "SCORE: " <<   all_high_scores[i].score << endl;
                };
            };

            if(input[0] == '2'){
                if (hs_number_of_lines/2+1 < 5){
                    cout << "TOP " <<  hs_number_of_lines/2 +1 << "SCORES: " << endl;
                    for (int i=0; i < hs_number_of_lines/2 + 1; i++) {
                        cout << i+1 <<". USERNAME: " << all_high_scores[i].username << '\t' << "SCORE: " <<   all_high_scores[i].score << endl;
                    }
                }

                else {
                    cout << "TOP 5 SCORES: " << endl;
                    for (int i=0; i < 5; i++) {
                    cout << i+1 <<". USERNAME: " << all_high_scores[i].username << '\t' << "SCORE: " <<   all_high_scores[i].score << endl;
                }
            }
        }


            delete all_high_scores;

            cout << endl;
            player -> pointCount = 0;
            player -> amountOfLives = 10;
            player -> comboCount = 0;
            system("pause");
            
        }
    }
    fclose(word_file_read);
            
    cout << "exiting game...." << endl;
    delete quitGameArray;
    delete hintGameArray;
    delete player;
    return 0;
}