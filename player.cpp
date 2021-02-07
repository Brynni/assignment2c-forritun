#include <time.h> 
#include "player.h"
using namespace std;

//Overide out<< operator to output the entire data bank of the word
ostream& operator<<(ostream& out, Player *player){
    out << "These are your points bucko! " << player->pointCount;
    return out;
}


