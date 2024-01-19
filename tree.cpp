//Yunsung Choi
//tree.cpp
//implementation for stack.h 

#include <iostream>
#include <iomanip>
#include <stack>

using namespace std;

#include "tree.h"

    // public
    BST::BST() : root(nullptr) {}
    BST::BST(const BST& other)
    {
        root = nullptr;
        copyNode(root, other.root);
    }
    BST& BST::operator=(const BST& other)
    {
        if( this != &other){
            destroyNode(root);
            copyNode(root, other.root);
        }
        return *this;
    }
    BST::~BST()
    {
        destroyNode(root);
    }

    bool BST::insertNode(int val)
    {
        return insertNode(root, val);
    }

    bool BST::findKey (int val) const
    {
        return findKey (root, val);
    }
    int BST::findHeight () const
    {
        return findHeight(root);
    }
    void BST::postOrderPrint ()
    {
        postOrderPrint(root);
    }

    void BST::inOrderPrint ()
    {
        inOrderPrint(root);
    }

    int BST::countLeaves () const
    {
        return countLeaves(root);
    }
    int BST::countFullNode () const
    {
        return countFullNode(root);
    }
    void BST::deleteNode(int val)
    {
        return deleteNode(root, val);
    }

    //private functions
    void BST::copyNode(TreeNode*& originalNode, TreeNode* newNode)
    {
        if (newNode == nullptr){
            originalNode = nullptr;
        }else{
            originalNode = new TreeNode(newNode->key);
            copyNode(originalNode->left, newNode->left);
            copyNode(originalNode->right,newNode->right);
        }
    }

    bool BST::insertNode(TreeNode*& root, int val)
    {
        if (root == nullptr){
            root = new TreeNode(val);
            return true;
        } else if (root->key == val) return false;
        else if (root->key > val) return insertNode(root->left, val);
        else return insertNode(root->right, val);
    }

    bool BST::findKey (TreeNode* root, int val) const
    {
        if (root == nullptr) return false;
        else if (root->key == val) return true;
        else if (root->key > val) return findKey(root->left, val);
        else return findKey(root->right, val);
    }
   
    int BST::findHeight (TreeNode* root) const
    {
        if (root==nullptr) return 0;
        else{
            int lHeight = findHeight(root->left);
            int rHeight = findHeight(root->right);
            if(lHeight > rHeight){
                return 1 + lHeight;
            }else{
                return 1 + rHeight;
            }
        }
    }
    
    void BST::postOrderPrint (TreeNode* root)
    {
        static int count = 0;
        if(root != nullptr){
            postOrderPrint(root->left);
            postOrderPrint(root->right);
            cout << root->key << " ";
            count ++;
            if (count%10 ==0){
                cout << endl;
            }
        
        }
    }

    void BST::inOrderPrint (TreeNode* root)
    {
        stack<TreeNode*> s;
        TreeNode* current = root;
        int count = 0;

        while(current!= nullptr || !s.empty()){
            while(current!=nullptr){
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();

            if (count % 10 ==0){
                cout << endl;
            }

            cout << current->key << " ";
            count++;
            current = current->right;
        }
        cout << endl;
    }

    int BST::countLeaves (TreeNode* root) const 
    {
        if (root == nullptr) return 0;
        else if (root->left == nullptr && root->right == nullptr) return 1;
        else return countLeaves(root->left) + countLeaves(root->right);
    }

    int BST::countFullNode (TreeNode* root) const
    {
        int countFull = 0;

        if (root == nullptr) return 0;
        else if(root->left != nullptr && root->right != nullptr){
            countFull = 1;
        }
        countFull += countFullNode(root->left) + countFullNode(root->right);
        return countFull;
    }

    void BST::deleteNode(TreeNode*& root, int val)
    {
        if (root == nullptr) return;
        else if (root->key > val) deleteNode(root->left, val);
        else if (root->key < val) deleteNode(root->right, val);
        else{
            //when the node has one or no child
            if (root->left==nullptr){
                TreeNode* temp = root->right;
                delete root;
                root = temp;
            } else if (root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                root = temp;
            }else{
                //when the node has two children
                TreeNode* temp = root->right;
                while(temp->left != nullptr){
                    temp = temp->left;
                }
                root->key = temp->key;
                deleteNode(root->right, temp->key);
            }
        }
    }

    void BST::destroyNode(TreeNode*& root)
    {
        if(root== nullptr)return;

        destroyNode(root->left);
        destroyNode(root->right);
        delete root;
        root = nullptr;
    }
    


