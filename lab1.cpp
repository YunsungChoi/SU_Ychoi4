// YunsungChoi

// lab1.cpp

#include <iostream>
using namespace std;

const int SIZE = 11;
const int MIN = 15;
const int MAX = 100;

// prototype functions
int findMaxValue(int arr[]); 
int promptUser();
bool repeatAttempt();

// simplified main func
int main()
{
    
    cout <<  "Welcome!" << endl;
    while (repeatAttempt()){
        promptUser();
    }
    cout << endl << " End of Lab1 Program. Thank you :)" << endl;
    return 0;
  
}

// find max value from given array
int findMaxValue(int arr[])
{
    int maxValue =arr[0];
    //initialize

    for( int i = 1; i < SIZE; i++){
        if (arr[i] > maxValue){
            maxValue = arr[i]; 
        }
    }
    
    return maxValue;
}

// seemed it was repeating so created a seperate class
int promptUser()
{
    
    int list[SIZE];
    int count = 0; 
    int inputNum;

    while(count < SIZE)
    {
        cout << "Please type 11 odd numbers between " << MIN << " and " << MAX << ": ";
        cin >> inputNum;
        
        //store input numbers
        if( inputNum % 2 != 0 && inputNum >= MIN && inputNum <= MAX){
            list[count] = inputNum;
            count++;
        }
    }
    
    // println all the values with index
    for (int i = 0; i < SIZE; i++)
    {
        cout << "[Index: " << i << ", and Value: " << list[i] <<"]"<< endl;
        
    }
    
    // at the end print max value
    cout << "[The max Value is:  " << findMaxValue(list) << "]"<<endl;
    return 0;
}

// c++ : main() cannot be called within main() function
// created a seperate class
bool repeatAttempt(){
    
    char answer;
    
    cout << "Countinue? [Y/N]" << endl;
    cin >> answer;
    
    if (answer == 'y' || answer == 'Y')
    { return true;}
    else if (answer =='n' || answer =='N')
    { return false;}
    else{
        cout << "Invalid input. Y or N. It's that simple." << endl;
        return repeatAttempt();
    }

}






