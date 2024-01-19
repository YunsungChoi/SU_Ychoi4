//Yunsung Choi
//p5.cpp
//Hashing, Hash Table, seperate chaining practice.
//
//This Program reads words from  Ulyss12.txt files, process and hash the words,
//And finally insert the words to hashTable.
//
//This Program also prints out statistics such as load factors,
//Number of unique words, number of collisions and number of occurrences
//of words given by user.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//table size 33149, 33161, 33169...
const int TABLE_SIZE = 33161;
const string FILE_NAME = "ulyss12.txt";
const char CONTINUE = 'y';

struct wordNode{
    string word; //word
    int count;  // occurences of word
    wordNode* next; // link to the next word
};

class HashTable{
    private:
    unsigned int totalCollision;
    wordNode* table[TABLE_SIZE];

    //SDBMHash Function from 
    //GeneralHashFunctions.cpp from 
    //General purpose Hash Function Algorithm website
    unsigned int SDBMHash(const std::string& str){
        unsigned int hash = 0;

        // string class uses unsigned type for length and indexing
        for(unsigned i = 0; i < str.length(); i++)
        {
            // ASCII value of the current character + 
            // left shift operation on the hash value by 6 bits
            // + left shift operation on the hash value by 16 bits - 0
            hash = str[i] + (hash << 6) + (hash << 16) - hash;
        }
        return hash;
    }

    public:
    //constructor; initialize the hash table to nullptr
    HashTable(){
        for (int i =0; i < TABLE_SIZE; i++){
            table[i] = nullptr;
        }
    }
    
    // hash and insert a word into the hashTable
    void insert(const string& word){
        // create a node with following information
        // to insert the node to hashTable
        unsigned int strIndex = SDBMHash(word);
        unsigned int tableIndex = strIndex % TABLE_SIZE;
        unsigned int tempCollision =0;

        wordNode* newNode = new wordNode;
        newNode->word = word;
        newNode->count = 1;
        newNode->next = nullptr;

        // if no node was previously inserted at the chosen index
        if (table[tableIndex] == nullptr){
            //insert
            table[tableIndex] = newNode;
        }else{
            // otherwise declare current and previous ptr
            wordNode* current = table[tableIndex];
            wordNode* prev = nullptr;

            while (current != nullptr){
                // if already exist, delete the node and increase the count
                if (current->word == word){
                    current->count++;
                    delete newNode;
                    return;
                }
                // move to the next node and find if word exist
                prev = current;
                current = current->next;
                tempCollision++;
            }
            // if not found, insert the new node
            prev->next = newNode;
            totalCollision += tempCollision;
        }
    }
    // getting number of occurrences of a word
    int getCount(const string& word){
        //hash the word
        unsigned int strIndex = SDBMHash(word);
        //index of hashed word
        unsigned int tableIndex = strIndex % TABLE_SIZE;
        //pointer to the calculated index where the word is supposed to be
        wordNode* current = table[tableIndex];

        while (current !=nullptr){
            // if the node is found return its count
            if (current->word == word){
                return current->count;
            }
            // otherwise move to the next node
            current = current->next;
        }
        return 0;
    }

    // this function will print out all the statistic.
    void printStatistics(){
    int uniqueWords = 0;
    int totalWords = 0;

    for (int i = 0; i < TABLE_SIZE; i ++){
        wordNode* current = table[i];
        //count unique words and total words
        while(current != nullptr){
            uniqueWords++;
            totalWords += current->count;
            current = current->next;  

        }
    }


    cout << "Load Factor:   " << static_cast<double>(uniqueWords)/TABLE_SIZE << endl;
    cout << "Number of Collisions:     " << totalCollision << endl;
    cout << "Number of Unique Words:    " << uniqueWords << endl;
    cout << "Total number of Words:     " << totalWords << endl;
    } 

    string processWord(const string& word){
        string processedWord;
        //for every single character of the word (-std=c++11)*
        for (char c : word){
            //capture only string characters, remove everything else
            if (isalpha(c)){
                //and store them in processedword
                processedWord += tolower(c);
            }
        }
        // since A word is defined as a series of alphabetic characters 
        // of length > 5, if a word is <= 5, return empty string.
        if (processedWord.length() <= 5) return "";
        //otherwise return processedWord
        else return processedWord;
    }
};

int main(){
    ifstream inputFile(FILE_NAME);
    // if file is not opened, printout error message and exit
    if (!inputFile.is_open()){
        cout << "Failed to open file" << endl;
        return 1;
    }

    HashTable wordTable;
    string word;
    
    while(inputFile >> word){
        //process the word first
        word = wordTable.processWord(word);
        //check the length of the processed word
        if (word.length() > 5){
            // if all conditions is satisfied, insert.
            // the function will hash the word before insert
            wordTable.insert(word);
        }
    }

    //print out all the statistic
    wordTable.printStatistics();

    string query;
    //prompt user to type a word to see occurences of it
    //repeat until user asks to quit
    do{
        cout << "Enter a word [or 'q' to quit]:  ";
        cin >> query;
        if (query != "q"){
            // check the occurences
            if (query.length() > 5){
            // when getCount is called, the program will hash the word
            int count = wordTable.getCount(query);
            cout << "Word:   " << query  << "    " << "Occurence:  " << count << endl;
            }else{
                cout << "Only strings that is greater than 5 characters. " << endl;
            }
        }

    }while (query != "q");
    inputFile.close();
    return 0;
}


