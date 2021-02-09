#include <time.h> 
#include "player.h"
using namespace std;

//Overide out<< operator to output the entire data bank of the word
ostream& operator<<(ostream& out, Player *player){
    out << "Current score: " << player->pointCount << "\nLives left: " << player->amountOfLives << endl;
    return out;
}





