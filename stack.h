//Yunsung Choi
//stack ADT for ints

#ifndef STACK_H
#define STACK_H

class Stack
{
public:

    class EmptyStack{};
    //exception class thrown when attemp made to pop from empty stack

    explicit Stack(int size = 50);
    // constructor

    Stack(const Stack& s);
    // copy constructor

    Stack& operator=(const Stack& rhs);
    // overloaded assignment operator

    ~Stack();
    // destructor

    void push(int data);
    // adds data to stack
    // if data is not prime, the value will be rejected.
    //

    int pop();
    // remove and return data from stack
    // can throw Empty exception

    bool isEmpty() const;
    // returns status of stack

private:
    int* list; //stack
    int max; //size of stack
    int top; // top of stack

    void resize();
    //allocates more stack memory

    bool isPrime(int val);
    // determine the prime number

};

#endif