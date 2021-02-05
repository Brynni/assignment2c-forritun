#include <iostream>
using namespace std;

bool checkIndexArray(int num, int arr[], int arrSize){
    for (int i = 0; i<arrSize; i++){
        if(arr[i] == num){
            return true;
        }
    }

    return false;
};


// bool isLetterAtCorrectIndex(char letter, char arr[], int index ) {
//     if(arr[index]==letter){
//         return true;
//     }
//     return false;
// }



int main() {
    char myArr[8];
    myArr[0] = 'a';
    myArr[1] = 'b';
    myArr[2] = 'c';
    myArr[3] = 'd';   
    myArr[4] = 'd';   
    myArr[5] = 'a';
    myArr[6] = 'a';
    myArr[7] = 'a';

    int rand_index_array[sizeof(myArr)];
    char scrambled_arr[sizeof(myArr)];

    for (int i=0; i<sizeof(myArr);i++){

        int randomNum = rand() % sizeof(myArr);
        char letter = myArr[randomNum];

        // Should check if the index has already been added
        // If it hasn't been added -> check if the original array has the same letter at the index i
        // If it doesn't have the same character there AND it doesn't have the index already in the rand_index array
        // it should add the character to the scrambled array

        // so far it almost works...
        while(checkIndexArray(randomNum, rand_index_array, sizeof(myArr)) && (letter == myArr[i])){
            int randomNum = rand () % sizeof(myArr);
            char letter = myArr[randomNum];
            checkIndexArray(randomNum,rand_index_array, sizeof(myArr));
        };

        rand_index_array[i] = randomNum;
        scrambled_arr[i] = myArr[randomNum];
        cout << "Scrambled  : " << scrambled_arr[i] << endl;
        cout << "Correct    : " << myArr[i] << endl;
    };

    for (int i=0; i < sizeof(myArr); i++){
        cout << myArr[rand_index_array[i]];
    }




};