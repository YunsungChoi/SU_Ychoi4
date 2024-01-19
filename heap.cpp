//Yunsung Choi
//heap.cpp
//Implementation of Heap

#include "heap.h"
#include <iostream>
using namespace std;

Heap::Heap()
{
    size = 0;
    capacity = DEFAULT;
    heapArray = new int[capacity];
}

Heap::Heap(const Heap& other)
{
    capacity = other.capacity;
    size = other.size;

    heapArray = new int[capacity];
    for (int i = 0; i <=size; i ++){
        heapArray[i] = other.heapArray[i];
    }
}

Heap& Heap::operator=(const Heap& other){
    if (this != &other){
        delete[] heapArray;
        capacity = other.capacity;
        size = other.size;

        heapArray = new int[capacity];
        for (int i = 0; i <=size; i ++){
            heapArray[i] = other.heapArray[i];
        }
    }
    return *this;
   
}

Heap::~Heap(){
    delete[] heapArray;
}

void Heap::insert(int key){ 
    if (size == capacity){
        reSize();
    }
    int hole = size;
    size++;
    while (hole > 0 && key < heapArray[(hole - 1)/2]){
        heapArray[hole] = heapArray[(hole - 1)/2];
        hole = (hole - 1)/2 ;
    }
    heapArray[hole] = key;
}

int Heap::deleteMin(){ 
    if (isEmpty()){
        throw EmptyHeap();
    }else{
        return remove(0);
    }
}
bool Heap::isEmpty(){
    return (size == 0);
}

bool Heap::flushAll(int key){
    int count =0;
    int writeIndex = 0;

    for (int readIndex = 0; readIndex < size; readIndex++){
        if(heapArray[readIndex] != key){
            heapArray[writeIndex++] = heapArray[readIndex];
        }else{
            count++;
        }
    }

    size = writeIndex;
    return (count > 0);
}

int Heap::remove(int index){
    if (size ==0){
        throw EmptyHeap();
    }else{
        int value = heapArray[index];
        heapArray[index] = heapArray[size -1];
        percolateDown(index);
        size--;
        return value;
    }
}

// private
void Heap::reSize(){
    int newCapacity = capacity * 1.5;
    int* temp = new int[newCapacity];
    for (int i = 0; i < size; i++){
        temp[i] = heapArray[i];
    }
    delete[] heapArray;
    heapArray = temp;
    capacity = newCapacity;
}

void Heap::percolateDown(int index){
    
    int value = heapArray[index];
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    
    while(leftChild <size){
        int child = leftChild;
        if (rightChild <= size && heapArray[leftChild] > heapArray[rightChild]){
            child = rightChild;
        }
        if(value <= heapArray[child]){
            heapArray[index] = value;
            return;
        }
        heapArray[index] = heapArray[child];
        index = child;
        leftChild = index * 2 + 1;
        rightChild = index * 2 + 2;
    }
    heapArray[index] = value;
}