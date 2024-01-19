//Yunsung Choi
// implementation for stack.h


#include "stack.h"
using namespace std;

Stack::Stack(int size)
{
    if (size <3){
        size = 50;
    }
    max = size;
    list = new int[max];
    top = 0;
}

Stack::Stack(const Stack& s)
{
    max = s.max;
    list = new int[max];
    top = s.top;

    for (int i=0; i < top; i++){
        list[i] = s.list[i];
    }
}

Stack& Stack::operator=(const Stack& rhs)
{
    if (this != &rhs){
        delete [] list;
        max = rhs.max;
        list = new int[max];
        top = rhs.top;
        for (int i=0; i<top; i++){
            list[i] = rhs.list[i];
        }
    }
    return *this;
}

Stack::~Stack()
{
    delete[] list;
}

void Stack::push(int data)
{
    if(isPrime(data)){
        if(top == max){
            resize();
        }
        list[top] = data;
        top++;
    }
}

int Stack::pop()
{
    if (isEmpty()){
        throw EmptyStack();
    }else{
        top--;
        return list[top];
    }
}

bool Stack::isEmpty() const
{
    return top == 0;
}

void Stack::resize()
{
    int* temp;
    int larger = static_cast<int>(max * 1.5);
    temp = new int[larger];
    for(int i=0; i< top; i++){
        temp[i] = list[i];
    }
    delete [] list;
    list = temp;
    max = larger;
}

bool Stack::isPrime(int val)
{
    if (val <= 1) return false;
    for (int i=2; i<= val/2; ++i){
        if (val % i == 0) return false;
    }
    return true;
}