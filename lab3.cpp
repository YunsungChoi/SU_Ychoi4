//Yunsung Choi
//lab3.cpp
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
//prototypes functions
void printList(Node*& head);
void lastNeg(Node*& head, int& lastNegNum, bool& findNeg);
void insertNode(Node*& head, int value);
void deleteNode(Node *& head);

int main(){
    bool keep = true;
    char cont;
    int temp;
    int lastNegNum=0;
    bool findNeg = false;
    Node* head = new Node;

    // prompt users to input values and create linked list, unordered.
    while(keep){
        cout << "Value?: " << endl;
        cin >> temp;
        insertNode(head, temp);
        cout << "Continue? (Y/N)" << endl;
        cin >> cont;
        if (cont =='n' || cont =='N'){
            keep = false;
        }
    }
    printList(head);
    lastNeg(head, lastNegNum, findNeg);
    deleteNode(head);
}
//print all the values
void printList(Node*& head){
    Node* temp = head;
    cout << "List contains: " << endl;
    while(temp!=nullptr){
        cout << temp->data << "  ";
        temp = temp->next;
    }
}
// recursive function to print the last negative value.
void lastNeg(Node*& head, int& lastNegNum, bool& findNeg){

    if (head ==nullptr){
        if(!findNeg){
            cout << "No negative value." << endl;
        }else {
            cout << endl <<"The last negative value is:    " << lastNegNum << endl;
        }
        return;
    }
    if (head->data < 0){
        lastNegNum = head->data;
        findNeg = true;
    }
    lastNeg(head->next, lastNegNum, findNeg);
}
// insert input value to the head of the list.
void insertNode(Node*& head, int value){
    Node* temp = new Node;
    temp->data = value;
    temp->next = head;
    head = temp;
}
//delete the entire list.
void deleteNode(Node*& head){
    Node* temp = head;
    while( temp != nullptr){
        temp = head;
        head = head->next;
        delete temp;
    }
}
