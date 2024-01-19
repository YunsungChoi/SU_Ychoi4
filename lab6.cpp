//Yunsung Choi
// lab6.cpp
// practice hash and count number of collisions

#include<iostream>
using namespace std;


// prototypes
int hashF (int val);

const int SIZE = 10;
const int GLIST[] = {4371, 1323, 6173, 4199, 4344, 9679, 1989};
const int ARRSIZE = sizeof(GLIST) / sizeof(GLIST[0]);

int main(){
    int LinearTable[SIZE] = {0};
    int QuadraticTable[SIZE] = {0};
    int LinearCollision = 0;
    int QuadraticCollision = 0;
    int index;

    cout << "Result of Linear Probe:    " << endl;
    for (int i=0; i < ARRSIZE; i++){
        index = hashF(GLIST[i]);
        while(LinearTable[index] != 0){
            LinearCollision++;
            index = (index + 1) % SIZE;
        }
        LinearTable[index] = GLIST[i];
    }

    cout << "Linear Table" << endl;
    for(int i=0; i<ARRSIZE; i++){
        cout << "Index: " << i << "     Value: " << LinearTable[i] << endl;
    }
    cout << "There were " << LinearCollision << " collisions. " << endl;



    cout << "\nResult of Quadratic Probe:     " << endl;
    for (int j =0; j < ARRSIZE; j++){
        int index = hashF(GLIST[j]);
        int attempt = 1;

        while (QuadraticTable[index] != 0){
            QuadraticCollision++;
            index = (index + (attempt * attempt)) % SIZE;
            attempt++;
        }

        QuadraticTable[index] = GLIST[j];
    }

    cout << "Quadratic Table:  " << endl;
    for(int j =0; j<ARRSIZE; j++){
        cout << "Index: " << j << "     Value: " << QuadraticTable[j] <<endl;
    }
    cout <<endl;

    cout << "There were " << QuadraticCollision << " collisions. ";
    
}

int hashF (int val){
    return val % 10;
}