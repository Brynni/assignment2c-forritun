#ifndef PLAYER_ASSIGNMENT2
#define PLAYER_ASSIGNMENT2

#include <iostream>

using namespace std;

class Player{
    public:
        int amountOfLives;
        int pointCount;
        int comboCount;
        char* PlayerName; //For the c requirement

        friend ostream& operator<<(ostream& out, Player *player);
};

#endif //PLAYER_ASSIGNMENT2