#include <iostream>
using namespace std;


// Iterates over the index array and checks if the randNum has already come up before
// returns false if it hasn't
bool checkIndexArray(int num, int arr[], int arrSize){
    for (int i = 0; i<arrSize; i++){
        if(arr[i] == num){
            return true;
        }
    }

    return false;
};


bool checkCharAtIndex(char letter, char arr[], int index){
    if(arr[index]==letter){
        return true;
    }
    return false;
}


int main() {
    char myArr[4];
    myArr[0] = 'a';
    myArr[1] = 'b';
    myArr[2] = 'b';
    myArr[3] = 'a';   
 



    int rand_index_array[sizeof(myArr)];
    char scrambled_arr[sizeof(myArr)];

    for (int i=0; i<sizeof(myArr);i++){

        int randomNum = rand() % sizeof(myArr);
        char letter = myArr[randomNum];

        // checks if index is in the array
        bool indexInArray = checkIndexArray(randomNum, rand_index_array, sizeof(myArr));

        // check if myArr[i] contains the same letter
        bool charInArr = checkCharAtIndex(letter, myArr, i);

        // While either one is true generate a random number and check both again      
        while(indexInArray || charInArr){
            randomNum = rand () % sizeof(myArr);
            letter = myArr[randomNum];
            indexInArray = checkIndexArray(randomNum, rand_index_array, sizeof(myArr));
            charInArr = checkCharAtIndex(letter, myArr, i);
        };

        // Finally write the new index to rand_index_array and the scrambled letter to the scrambled letter array
        rand_index_array[i] = randomNum;
        scrambled_arr[i] = myArr[randomNum];
    };

    cout << "THE OG ARRAY" << endl;
    for (int i = 0; i<sizeof(myArr); i++){
        cout << myArr[i];
    };

    cout << " " << endl;

    cout << "THE scrambled ARRAY" << endl;
    for (int i = 0; i<sizeof(scrambled_arr); i++){
        cout << scrambled_arr[i];
    };

    
 
};