//Yunsung Choi
//lab7.cpp
//Practice merge sort on large data set.

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const string INPUTFILE = "/home/fac/sreeder/class/cs2430/countyPop.dat";
const int MAX = 3200;
const int MAX_PRINT = 10;
const int WIDTH = 8;

struct countyData{
    int populationCount;
    string countyName;
};

//prototypes
void merge(countyData arr[], int left, int mid, int right);
void mergeSort (countyData arr[], int left, int right);
void printBegEnd(const countyData arr[], int start, int end);

int main(){
    int count = 0;
    countyData list[MAX];
    //********************* read and copy the data 
    ifstream infile(INPUTFILE);
    while (infile >> list[count].populationCount){
        getline(infile, list[count].countyName);
        count++;
    }
    //*********************

    // Before merge sort 
    cout << endl <<"Before the Merge Sort begins...  " << endl;
    cout << "First 10 lists:    " << endl;
    printBegEnd(list, 0, 9);
    cout << endl << endl;
    cout << "Last 10 lists:     " << endl;
    printBegEnd(list, count-10, count-1);
    cout << endl << endl;

    // start sorting
    mergeSort(list, 0, count-1);

    // After merge sort
    cout << "After the Merge Sort is done..." << endl;
    cout << endl <<"First 10 lists:    " << endl;
    printBegEnd(list, 0, 9);
    cout << endl << endl;
    cout << "Last 10 lists:     " << endl;
    printBegEnd(list, count - 10, count -1);
    cout << endl << endl;

    return 0;
}

void mergeSort (countyData arr[], int left, int right){
    if (left < right){
        //find mid index
        int mid = left + (right - left) / 2;

        // divide left and right until the end
        mergeSort ( arr, left, mid);
        mergeSort ( arr, mid+1, right);
        
        //conquer
        merge(arr, left, mid, right);
    }
}

void merge(countyData arr[], int left, int mid, int right){
    //initialize values and determine the size 
    int i, j, k;
    int n1 = mid - left +1;
    int n2 = right - mid;
    
    //and create temp arrays !dynamic memory allocation
    countyData* leftTemp = new countyData[n1];
    countyData* rightTemp = new countyData[n2];
    
    //copy the values
    for (i=0; i < n1; i++){
        leftTemp[i] = arr[left+i];
    }
    for (j=0; j < n2; j++){
        rightTemp[j] = arr[mid +1 +j]; 
    }

    i = 0;
    j = 0;
    k = left;

    // compare values in left and right temp array and merge
    while (i < n1 && j < n2){
        if (leftTemp[i].populationCount <= rightTemp[j].populationCount)
        {
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

    //deallocate the right and left temp arrays
    delete[] leftTemp;
    delete[] rightTemp;
}

// print lines: range given
void printBegEnd(const countyData arr[], int start, int end){

    for (int i = start; i <= end; i++){
        cout << right << arr[i].populationCount << setw(WIDTH) 
        << left << arr[i].countyName << endl;
    }
    
}