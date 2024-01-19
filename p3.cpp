//Yunsung Choi
//p3.cpp
//test the functionality of BST

#include <iostream>
#include <ctime>
#include "tree.h"

using namespace std;


const int MAX_SIZE = 25;
const int TEST_SET[] = {11, 13, 17, 21, 29, 31, 35, 39, 44, 48,
                    51, 66, 69, 73, 77, 79,  80, 84, 88, 91,
                    95};
                    
const int TEST_NUM = 3;
const int TEST_NUM_MAX = 97;

int main(){
    BST tree;

    srand(time(0));

    for (int i=0; i< MAX_SIZE; i++){
        int val = rand()%100 + 10;
        tree.insertNode(val);
    }
    tree.insertNode(TEST_NUM_MAX);

    //Assignment operator
    BST tree_new = tree;
    
    //Test findkey
    cout << "Finding Key  [" << TEST_NUM_MAX << "]  :" <<
    (tree.findKey(TEST_NUM_MAX) ? "Found" : "Not found" ) << endl;

    cout << "Finding Key   [" << TEST_NUM << "]  :" << 
    (tree.findKey(TEST_NUM) ? "Found" : "Not found" ) << endl;

    //Test FindHeight
    cout << endl <<"The Height of the tree is :" << tree.findHeight() << endl;
    
    //Test PostOrderPrint
    cout << endl << "Post Order Print:   " << endl;
    tree.postOrderPrint();

    //Test InOrderPrint
    cout << endl << "In Order Traversal:   ";
    tree_new.inOrderPrint();

    //Test countLeaves
    cout << "Number of leaves are :" << tree.countLeaves() << endl;

    //Test countFullNode
    cout << "Number of Full Nodes are :" << tree.countFullNode() << endl;

    //Test copy constructor
    BST tree_copy(tree);
    cout << endl << "Copy constructor Post Order Print:   " << endl;
    tree_copy.postOrderPrint();
    cout << endl << "(The Result Must be the same as the first output)" << endl;

    //Test deleteNode
    cout << "Try to delete number doesn't exist  [" << TEST_NUM
    << "] "<< endl;
    tree_copy.deleteNode(TEST_NUM);
    cout << "Trey to delete number that does exist  [" << TEST_NUM_MAX
    << "] "<< endl;
    tree_copy.deleteNode(TEST_NUM_MAX);
    tree_copy.postOrderPrint();


}