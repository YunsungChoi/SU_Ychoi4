//Yunsung Choi
// lab2.cpp

#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int firstExample(int n);
int secondExample(int n);

const int MULTIPLIER = 10;
const int FIRST_N = 100000000;
const int SECOND_N = 30;


int main(){
    steady_clock::time_point start;
    steady_clock::time_point end;
    duration<double> elpSeconds;

    cout.setf(ios::fixed);// fixed digit numbers after decimal point.
    cout.precision();// specify the digit numbers for example, cout.precision(8) then 8 digits after decimal point. for this lab, I haven't specify.

    cout << endl << endl;
    cout << "Sample 1:  O(n)" << endl;
    start = steady_clock::now();
    cout << "firstExample("<< FIRST_N << ") =" << firstExample(FIRST_N) << endl;
    end = steady_clock::now();
    elpSeconds = end-start;
    cout << "elapsed time:  " << elpSeconds.count() << endl;
    start = steady_clock::now();
    cout << "firstExample("<< FIRST_N * MULTIPLIER << ") =" << firstExample(FIRST_N * MULTIPLIER) << endl;
    end = steady_clock::now();
    elpSeconds = end - start;
    cout << "elapsed time:  " << elpSeconds.count() << endl;
    cout << "Yes, it is O(n)" << endl;


    cout << endl << endl;
    cout << "Sample 2:  O(n^4)" << endl;
    start = steady_clock::now();
    cout << "secondExample("<< SECOND_N << ") =" << secondExample(SECOND_N) << endl;
    end = steady_clock::now();
    elpSeconds = end-start;
    cout << "elapsed time:  " << elpSeconds.count() << endl;
    start = steady_clock::now();
    cout << "secondExample("<< SECOND_N * MULTIPLIER << ") =" << secondExample(SECOND_N * MULTIPLIER) << endl;
    end = steady_clock::now();
    elpSeconds = end - start;
    cout << "elapsed time:  " << elpSeconds.count() << endl;
    cout << "No, it is actually O(n^5)" << endl;



}

int firstExample(int n){

    int sum=0;
    for(int i =0; i<n; i++){
        sum++;
    } return sum;
}

int secondExample(int n){
    int sum=0;
    for(int i=0; i<n; i++){
        for (int j=0; j<i*i; j++){
            for(int k = 0; k<j; k++){
                sum++;
            }
        }
    } return sum;
}
