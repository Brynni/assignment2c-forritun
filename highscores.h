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

};




#endif