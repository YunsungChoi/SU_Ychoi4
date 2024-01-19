//lab5.cpp                                                                      
//Yunsung Choi                                                                  
//practice to create heap to implement priority queue                           

#include <iostream>
#include <cstdlib>
using namespace std;

//prototype functions                                                           
void swap(int &a, int &b);
void heapUp(int heap[], int size);
void heapDown(int heap[], int size, int index);
void insert(int heap[], int& size, int val);
int remove(int heap[], int& size);

int main(){
    int max_size = 25;
    int *heap = new int[max_size];
    srand(time(0));
    int size = 0;
    cout << "First set: "<< endl;
    for (int i=0; i<20; i++){
        int val = rand()%100;
        insert(heap, size, val);
        cout << val << " ";
    }
    cout << endl << endl;

    cout << "Removed values: " << endl;
    while (size > 0){
	for (int i=0; i<5 && size >0; i++){
            cout << remove(heap, size) << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Second set: " << endl;
    for (int i=0; i<17; i++){
        int val = rand()%100;
        insert(heap, size, val);
        cout << val << " ";
    }
    cout << endl<< endl;

    cout << "Removed values: " << endl;
    while (size > 0){
	for (int i=0; i<5 && size >0; i++){
            cout << remove(heap, size) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void heapUp(int heap[], int index)
{
    if (index == 0) return;
    int child = index - 1;
    int parent = child /2;
    if (heap[child]<heap[parent]){
        swap(heap[child], heap[parent]);
        heapUp(heap, parent);
    }
}

void heapDown(int heap[], int size, int index)
{
    int leftChild = 2 * index +1;
    int rightChild = 2 * index + 2;
    int minIndex = index;

    if (leftChild < size && heap[leftChild]< heap[minIndex]){
        minIndex = leftChild;
    }
    if (rightChild < size && heap[rightChild] < heap[minIndex]){
        minIndex = rightChild;
    }
    if (minIndex != index){
        swap(heap[index], heap[minIndex]);
        heapDown(heap, size, minIndex);
    }
}

void insert(int heap[], int& size, int val)
{
    if(size >= 25){
        return;
    }
    heap[size++] = val;
    heapUp(heap,size);
}

int remove(int heap[], int& size){
    if (size ==0) return -1;
    int min = heap[0];
    heap[0] = heap[--size];
    heapDown(heap, size, 0);
    return min;
}
