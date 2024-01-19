//Yunsung Choi
//CPSC2600 hw2 Programming Problem

#include <iostream>
using namespace std;

int main(){

    // using bitwise operation to set particular bit
    // in binary representation of int variable in set A
    int setA = 0;
    cout << "Enter elements of set A [from 0 to 9, -1 to stop]: ";
    int userInput;
    while (cin >> userInput && userInput != -1){
        setA |= (1<< userInput);
    }

    // do same as above for setB
    int setB = 0;
    cout << "Enter elements of set B [from 0 to 9, -1 to stop]: ";
    while (cin >> userInput && userInput != -1){
        setB |= (1<< userInput);
    }

    // print all the values in setA
    cout << "Set A = {";
    for(int i =0; i< 10; i++){
        if (setA & (1<< i)){
            cout << i << " ";
        }
    }
    cout << "}" << endl;

    // print all values in setB
    cout << "Set B = {";
    for(int i =0; i< 10; i++){
        if (setB & (1<< i)){
            cout << i << " ";
        }
    }
    cout << "}" << endl;

    // compute and printout A union B
    int unionAB = setA | setB;
    cout << "A union B [A U B] = {";
    for (int i=0; i<10; i++){
        if (unionAB & (1 << i)){
            cout << i << " ";
        }
    }
    cout << "}" << endl;

    //compute and printout A intersect B
    int intersectAB = setA & setB;
    cout << "A intersect B [A n B] = {";
    for (int i=0; i<10; i++){
        if (intersectAB & (1 << i)){
            cout << i << " ";
        }
    }
    cout << "}" << endl;

    //compute and printout A difference B
    int differenceAB = setA & ~setB;
    cout << "A difference B [A n B] = {";
    for (int i=0; i<10; i++){
        if (differenceAB & (1 << i)){
            cout << i << " ";
        }
    }
    cout << "}" << endl;

    return 0;
}