//Yunsung Choi
//hw3.cpp
// practice merge sort algorithm

#include <iostream>
using namespace std;

void mergeSort (int* arr, int left, int right);
void merge(int* arr, int left, int mid, int right);

int main(){
    int n;
    cout << "Number of Integer?:     " << endl;
    cin >> n;

    int* arr = new int[n];
    cout << "Enter the Int values:      " << endl;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << "Numers you enetered:   " << endl;
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, n-1);

    cout << "Sorted List:   " << endl;
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

}
void mergeSort (int* arr, int left, int right){
    if (left < right){
        //divide until the end
        int mid = left + (right - left) / 2;
        mergeSort ( arr, left, mid);
        mergeSort ( arr, mid+1, right);
        
        //conquer
        merge(arr, left, mid, right);
    }
}

void merge(int* arr, int left, int mid, int right){
    //determine the size 
    int n1 = mid - left +1;
    int n2 = right - mid;
    //and create temp arrays
    int* leftTemp = new int[n1];
    int* rightTemp = new int[n2];

    //copy the values
    for (int i=0; i< n1; i++){
        leftTemp[i] = arr[left+i];
    }
    for (int j =0; j < n2; j++){
        rightTemp[j] = arr[mid +1 +j]; 
    }

    int i, j, k;
    i =0;
    j = 0;
    k = left;

    // compare values in left and right temp array and merge
    while (i <n1 && j <n2){
        if (leftTemp[i] <= rightTemp[j]){
            arr[k] = leftTemp[i];
            i++;
        } else{
            arr[k] = rightTemp[j];
            j++;
        }
        k++;
    }

    // nothing to compare then just insert
    while (i < n1){
        arr[k] = leftTemp[i];
        i++;
        k++;
    }

    while (j<n2){
        arr[k] = rightTemp[j];
        j++;
        k++;
    }

}
