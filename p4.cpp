//Yunsung Choi
//p4.cpp
//exercises understanding of Heaps(Priority Queues) and dynamic memory in C++

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "heap.h"
using namespace std;

const int TESTNUM = 15;
const int RANDOM_MIN = 10;
const int RANDOM_MAX = 100;

int main(){
    srand(time(0));

    cout << "Press Enter to Test Heap functions... \n ";
    cin.ignore();
    cout << "Testing Heap functions \n";

    Heap minHeap;

    int value;
    for (int i = 0; i < TESTNUM; i++){
        value = RANDOM_MIN + rand() % (RANDOM_MAX - RANDOM_MIN + 1);
        minHeap.insert(value);
    }
    cout << endl;

    // test Overloaded Assignment operator
    cout << "overloaded assignment operator: copyHeap = minHeap..." << endl;
    Heap copyHeap = minHeap;

    int minValue;
    cout << "Testing isEmpty() and deleteMin() function:    " << endl;
    while (!copyHeap.isEmpty()){
        minValue = copyHeap.deleteMin();
        cout << minValue << "   ";
    }
    cout << endl;

    cout << "Try to insert more values including multiple 20s ... " << endl;
    
    minHeap.insert(10);
    minHeap.insert(15);
    minHeap.insert(20);
    minHeap.insert(20);
    minHeap.insert(25);
    minHeap.insert(30);
    minHeap.insert(40);
    minHeap.insert(20);

    // test copy constructor
    cout << "Copy Constructor: cc(minHeap)      \n";

    Heap cc(minHeap);

    cout << "Check the values of the cc heap... " << endl;
    while(!cc.isEmpty()){
        minValue = cc.deleteMin();
        cout << minValue << "   ";
    }
    cout << endl;

    //test flushAll() function
    cout << "Testing FlushAll(20)...   " << endl;
    minHeap.flushAll(20);
    cout << "Then empty out the minHeap...     " << endl;
    while(!minHeap.isEmpty()){
        minValue = minHeap.deleteMin();
        cout << minValue << "   ";
    }
    cout << endl;

    cout << "Try to throw EmptyHeap exception...\n";
    try{
        minHeap.deleteMin();
    }catch(Heap::EmptyHeap){
        cout << "EmptyHeap Exception Caught! " << endl;
    }
    cout << endl;

    cout << "Testing complete. Thank you." << endl;









    
}



