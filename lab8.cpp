//Yunsung Choi
//Lab8.cpp
//improves understanding of using iterators and the STL

#include <iostream>
#include <iomanip>
#include <random>
#include <vector>

using namespace std;

const int MAX_SIZE = 500;
const int RANDOM_MIN = 1;
const int RANDOM_MAX = 1000;
const int WIDTH = 4;
const int ROW_MAX = 20;

int main(){
    srand(time(0));
    //using sequence container: vector
    vector<int> numbers;
    int count = 0;

    //Generating and storing 500 random ints.
    for(int i = 0; i < MAX_SIZE; i ++){
        //random numbers range between 100 - 999
        int value = RANDOM_MIN + rand() % (RANDOM_MAX - RANDOM_MIN);
        //insert() = push_back()
        numbers.push_back(value);
    }
    cout << "Original Numbers:      " << endl;
    //auto keyword for iterator
    for (auto it = numbers.begin(); it != numbers.end(); it++){
        count++;
        cout <<setw(WIDTH) << right << *it;
        if (count % ROW_MAX == 0){
            count = 0;
            cout <<endl;
        }
    }
    count = 0;
    cout << endl;

    cout << "Removing multiples of 5...     \n";
    //define an iterator compatible with vector<int>
    vector<int>::iterator it = numbers.begin();
    while(it != numbers.end()){
        // if multiple of 5, then remove.
        if (*it % 5 == 0){
            it = numbers.erase(it);
            //or numers.erase(it);  it--;
            
        // otherwise move to the next val.
        } else{
            ++it;
        }
    }

    // print all the values
    cout << "After removing multiples of 5:     \n";
    cout << "Vector contains " << numbers.size() << " elements. \n";
    for (auto it = numbers.begin(); it != numbers.end(); it++){
        count++;
        cout  <<setw(WIDTH) << right << *it ;
        if (count % ROW_MAX == 0){
            count = 0;
            cout <<endl;
        }
    }

    count = 0;
    cout << endl;
    return 0;
}