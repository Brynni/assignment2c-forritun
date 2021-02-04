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

using namespace std;

int main() {
    

    char nameOfFile[32];
    cout << "Please enter a name: "; // Ask user for name of file
    cin >> nameOfFile; // Get their input
    strcat(nameOfFile, ".txt"); // Add txt ending 

    FILE *word_file_read;
    char word[50];
    char wordcopy[50];
    char i;
    char randNum;
    i = 0;
    randNum = 23;
    char dest[40];

    word_file_read = fopen(nameOfFile, "r+");

    if (word_file_read == NULL)
        cout << "Cant find the file"; // Ask user for name of file
    else
    {
        while (fscanf(word_file_read, "%s", word) != EOF)
        {
            if (i == randNum)
            {   
                int i = 0;
                char selectedWordArray [50];
                int b = 0;
                for (b = 0;word[b] != '\0'; b++)
                {
                    selectedWordArray[b] << word[b];
                    cout << word[b];
                    
                    
                }
                cout << "\nlength of string is : "<< b << "\n";
                i=0;
                break;
            }
            i++;
        }
        fclose(word_file_read);
        cout << "were done here!\n";
    }

    return 0;
}


/* 
std::ifstream fs;
    fs.open ("newwords.txt", ios::in);

    //fs >> " more lorem ipsum";
    char ch;
    char junkwords;
    char num;
    char i;
    num = 10;
    i = 0;
    while (i < num) {
        if (num == i)
        {
            fs >> ch;
            i = 0;
            break;
        }
        if(ch == ' ' || ch == '\n') 
		{ 
			printf("\n");  
		} 
        i++;
        fs >> junkwords;
        cout << junkwords;
    }
    
    cout << ch;
    std::cout << "\nHello World! A NEW FILE HAS BEEN BORN HALLELUJAH! \n";
    cout << junkwords;
    std::cout << "\nHello World! A NEW FILE HAS BEEN BORN HALLELUJAH! \n";
    fs.close(); */