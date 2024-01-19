//Yunsung Choi
//lab4.cpp
// BST

#include <iostream>
using namespace std;


struct Node{
    int key;
    Node* left;
    Node* right;
};

// not allowing duplicates, smaller left, bigger right.
void insertNode(Node*& root, int val);
void deleteAllNode(Node*& root);
void traverseInorder(Node* root);
void traversePreorder(Node* root);
void traversePostorder(Node* root);

const int SIZE = 10;

int main(){
    Node* root = nullptr;
    int random;
    srand(time(0));

    for(int i = 1; i < SIZE; i++){
        random = rand() % 100;
        cout << "Attempting to add " << random << endl;
        insertNode(root, random);
    }

    cout << "Attempting to add " << random;
    insertNode(root, random);
    cout << " second time " << endl << endl;

    cout << "Printing in order: " << endl;
    traverseInorder(root);
    cout << endl;

    cout << "Printing pre-order: " << endl;
    traversePreorder(root);
    cout << endl;

    cout << "Printing post-order: " << endl;
    traversePostorder(root);
    cout << endl;

    // delete the entire node
    deleteAllNode(root);
}


void insertNode(Node*& root, int val){
    if( root == nullptr ){
        root = new Node;
        root->key = val;
        root->left = nullptr;
        root->right = nullptr;
    }else if (val < root->key){
        insertNode(root->left, val);
    }else if(val > root->key){
        insertNode(root->right, val);
    }
}

void traverseInorder(Node* root){
    if( root != nullptr ){
        traverseInorder(root->left);
        cout << root->key << " ";
        traverseInorder(root->right);
    }
}

void traversePreorder(Node* root){
    if (root != nullptr){
        cout << root->key << " ";
        traversePreorder(root -> left);
        traversePreorder(root -> right);
    }
}

void traversePostorder(Node* root){
    if (root != nullptr){
        traversePostorder(root->left);
        traversePostorder(root->right);
        cout << root -> key << " ";
    }
}

void deleteAllNode(Node*& root){
    if (root != nullptr){
        deleteAllNode(root->left);
        deleteAllNode(root->right);
        delete root;
        root = nullptr;
    }
}

