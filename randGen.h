#ifndef RANDGEN_ASSIGNMENT2
#define RANDGEN_ASSIGNMENT2

#include <iostream>

using namespace std;

class WordScramble{
    public:
        int length;
        char* arrPointer;
        char* scrambledArrPointer;

        friend char* ScrambleArray(WordScramble *wordscramble);
        friend ostream& operator<<(ostream& out, WordScramble *wordscramble);

        ~WordScramble() {
        cout << "Object is being deleted" << endl;
    }
};

#endif //RANDGEN_ASSIGNMENT2