//Yunsung Choi
//p2.cpp 
// test the functionality of stack class that accept only prime number.

#include <iostream>
#include "stack.h"
using namespace std;

int main(){

    cout << "Create a new stack of size 5. " << endl;
    Stack s1(5);

    cout << "Push some prime values into the stack: ";
    cout << "[2, 3, 5, 7, 11]" << endl;
    s1.push(2);
    s1.push(3);
    s1.push(5);
    s1.push(7);
    s1.push(11);

    cout << "Attempt to push a non-prime value: [12, 1]" << endl;
    s1.push(12);
    s1.push(1);

    cout << "Attempt to pop some values from the stack. " << endl;
    cout << s1.pop() << ",   ";
    cout << s1.pop() << endl;

    cout << "Copy constructor check. " << endl;
    Stack s2(s1);

    cout << "Push more prime numbers into the original stack: ";
    cout << "[13, 17]" << endl;
    s1.push(13);
    s1.push(17);

    cout << "Popping a value from the copy stack. " << endl;
    cout << s2.pop() << endl;

    cout << "Checking contents of the original stack. " << endl;
     while (!s1.isEmpty()){
        cout << s1.pop() << "  ";
    }
    cout << endl;

    cout << "Check if the stack is empty. " << endl;
    cout << "Stack is empty: " << s1.isEmpty() << endl << endl;
    
    cout << "Checking contents of the copy stack. " << endl;
     while (!s2.isEmpty()){
        cout << s2.pop() << "  ";
    }
    cout << endl;
    
    cout << "Trying to throw an exception. " << endl;
    try {
        s1.pop();
    } catch (Stack::EmptyStack e){
        cout << "Exception: EmptyStack e thrown. "<< endl << endl;
    }

    cout << "Test assignment operator";
    cout << " with size 3 and push more than 3 values";
    cout << " [2, 3, 5, 7, 11, 23,29]. " << endl;
    Stack s3(3);
    s3.push(2);
    s3.push(3);
    s3.push(5);
    s3.push(7);
    s3.push(11);
    s3.push(23);
    s3.push(29);


    cout << "checking the contents of it. " << endl;
    while (!s3.isEmpty()){
        cout << s3.pop() << "  ";
    }
    cout << endl;

    cout << "Done Testing the stack class. " << endl;
    

    return 0;
}