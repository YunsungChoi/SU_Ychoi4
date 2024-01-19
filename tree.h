//Yunsung Choi
//tree.h
//Tree ADT for ints

#ifndef BST_H
#define BST_H

class BST
{
private:
    struct TreeNode{

    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val)
    {
        key=val;
        left=nullptr; 
        right=nullptr;
    };
};

public:

    BST();
    //constructor

    BST(const BST& other);
    //copy constructor

    BST& operator=(const BST& other);
    //overloaded assignment operator

    ~BST();
    //destructor

    bool insertNode(int val);
    // insert a node into the tree. refuse duplicate values

    bool findKey (int val) const;
    // return bool indicating if value is present in tree

    int findHeight () const;
    // return total height of the tree

    void postOrderPrint ();
    // traversal done recursively and print key value to the screen

    void inOrderPrint ();
    // traversal done iteratively, using STL stack,to print key value

    int countLeaves () const;
    // return number of leaves in tree

    int countFullNode () const;
    // return number of full node in tree

    void deleteNode(int val);
    // delete a single node with no children, one and two children.

private:
    TreeNode* root;

    //below are all private helper methods for public functions
    void copyNode(TreeNode*& originalNode, TreeNode* newNode); //

    bool insertNode(TreeNode*& root, int val); //

    bool findKey (TreeNode* root, int val) const;//
    
    int findHeight (TreeNode* root) const;//
   
    void postOrderPrint (TreeNode* root);//

    void inOrderPrint (TreeNode* root);

    int countLeaves (TreeNode* root) const;//

    int countFullNode (TreeNode* root) const;//

    void deleteNode(TreeNode*& root, int val);//

    void destroyNode(TreeNode*& root);//

};

#endif // BST_H