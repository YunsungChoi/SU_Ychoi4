//Yunsung Choi
//heap.h
//heap ADT

#ifndef HEAP_H
#define HEAP_H

class Heap
{
public:
class EmptyHeap{};
 // thrown when trying to remove from an empty heap 
Heap(); 
// constructor

Heap(const Heap &other);
//copy constructor

Heap& operator=(const Heap &other);
// overloaded assignment operator

~Heap();
//destructor

void insert(int key); 
// duplicates allowed

int deleteMin();
// delete root

bool isEmpty();
// true if empty otherwise false

bool flushAll(int key); 
// remove all duplicates

private:
static const int DEFAULT = 10; 
// default size of a heap array

int* heapArray; 
//heap array

int size;       
// current array size

int capacity;   
// capacity the heap's dynamic array max elements the heap can hold

int remove(int index); 
// remove value at given index

void reSize(); 
//resize to 1.5 times bigger array 

void percolateDown(int index);  
// rearrange the heap
};
#endif