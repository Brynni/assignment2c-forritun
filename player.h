#ifndef PLAYER_ASSIGNMENT2
#define PLAYER_ASSIGNMENT2

#include <iostream>

using namespace std;

class Player{
    public:
        int pointCount;
        char* PlayerName; //For the c requirement

        friend ostream& operator<<(ostream& out, Player *player);

        ~Player() 
        {
            cout << "Player is being deleted" << endl;
        }
};

#endif //PLAYER_ASSIGNMENT2