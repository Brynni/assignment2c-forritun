#include <iostream>
#include <fstream>
using namespace std;




#ifndef HIGHSCORES221
#define HIGHSCORES221

struct Scores{
    public:
        char *username;
        int score;
        void Set_usrname(char usrname[3], Scores score) {
            score.username = usrname;
        };

        void Set_score(int points, Scores score){
            score.score = points;
        };
    private:
        bool compareHighScores(Scores score1, Scores score2);

        
        

};

int findIndex(Scores arr[], Scores score, int arrSize);
void putScoreInRightPlace(Scores arr[], Scores userscore, int index);
void moveElemToRight(Scores arr[], int higher, int lower);
void moveElements (Scores arr[], int index, Scores tmp);
void driverCodeForOrdering(Scores userscore, Scores arr[], int arrLength);
#endif