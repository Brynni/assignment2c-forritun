#ifndef RANDGEN_ASSIGNMENT2
#define RANDGEN_ASSIGNMENT2

#include <iostream>

using namespace std;

class WordScramble{
    public:
        int length;
        char* arrPointer;

        friend ostream& operator<<(ostream& out, WordScramble *wordscramble);
};

#endif //RANDGEN_ASSIGNMENT2