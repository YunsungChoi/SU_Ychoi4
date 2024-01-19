// Yunsung Choi                                                                 
// p1.cpp                                                                       

#include <iostream>
#include <iomanip> // Given                                                     
#include <fstream>
#include <cstdlib>
using namespace std;

struct Node
{
  int num;
  Node* next;
};

//prototypes                                                                    
void traversePrint(Node*& head, string fileName);
void insert(Node*& head, int value);
void deleteNode(Node*& head, int value);

int main(){

    Node* head = nullptr;   // pointer for the head of the linked list          

    srand(time(nullptr));
    // generate size between 50 and 80                                          
    int size = 50 + rand() % 31;

    //create ordered linked list                                                
    for (int i =0; i<= size -1; i++){
        insert(head,rand() % 1000);
    }
    //traverse and print into Original.txt file                                 
    traversePrint(head,"Original.txt");
    cout << "Original.txt File has been create." << endl;

    //delete a node contains the smallest value which comes at first            
    deleteNode(head, head-> num);
    cout << "The Smallest value had been deleted." <<endl;

    //delete a node contains the largest value which comes at last
    Node* temp = head;
    //** access to the second last **                                           
    while(temp->next != nullptr && temp->next->next != nullptr){
        temp = temp->next;
    }

    deleteNode(head, temp->next->num);
    cout << "The Largest Value had been deleted." <<endl;

    //delete mid value                                                          
    int mid = size/2;
    temp = head;
    for (int i = 0; i < mid-1; i++){
    temp = temp->next;
    }
    deleteNode(head, temp->next->num);
    cout << "The Mid Value had been deleted." <<endl;

    //attempt to delete a value doesn't exist                                   
    deleteNode(head, -999);

    //updated.txt                                                               
    traversePrint(head, "Updated.txt");
    cout << "Updated file 'Updated.txt' had been created." << endl;

    //delete all                                                                
    while( head != nullptr){
        temp = head;
        head = head->next;
        delete temp;
    }
    cout << "All of the values had been deleted." <<endl;

}
void traversePrint(Node*& head, string fileName){
    ofstream outFile(fileName);
    if (head== nullptr){
        cout << "The List is empty" << endl;
        outFile.close();
        return;
    }

    int count = 0;
    Node* temp = head;
    // format                                                                   
    while( temp != nullptr){
        outFile << setw(5) << temp->num;
        temp = temp->next;
        count++;
        if(count% 5 ==0){
            outFile << endl;
        }
    }
    outFile.close();

}
void insert(Node*& head, int value){

    Node* newNode = new Node;
    newNode->num = value;
    newNode->next = nullptr;

    // if the list is empty, insert it into the first node                      
    if(head == nullptr || value <= head->num){
        newNode -> next = head;
        head = newNode;
        return;
    }
    Node* newNode2 = head;
    // find a place to insert the given value                                   
    while(newNode2->next != nullptr && value > newNode2->next->num){
        newNode2 = newNode2->next;
    }
    // insert             
    newNode->next = newNode2->next;
    newNode2->next = newNode;


}

void deleteNode(Node*& head, int value){

    if (head == nullptr){
        cout << "There's nothing to delete" << endl;
     return;
    }
    // delete the very first node (smallest)                                    
    if (head->num == value){
	Node* temp = head;
	head = head->next;
        delete temp;
	return;
    }


    // point to the previous node of what we wish to delete                     
    // and delete        
    Node* temp = head;
    while(temp->next != nullptr && temp->next->num != value){
        temp = temp->next;
    }
    if (temp->next != nullptr){
        Node* temp2 = temp->next;
        temp ->next = temp->next->next;
        delete temp2;
    }
    else{
        //cout << "The Number is not on the list." << endl;                     
    }
}
                 

