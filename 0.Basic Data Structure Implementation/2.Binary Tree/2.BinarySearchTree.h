//#include "BinaryTreeNode.h"
#include<iostream>
using namespace std;

class BST{
private:
    BinaryTreeNode<int> *root;
public:
    BST()
    {
        root=NULL;
    }

private:
    bool hasData(int data,BinaryTreeNode<int>* node)
    {
        if(node == NULL)
        {
            return false;
        }

        if(node->data == data)
        {
            return true;
        }
        else if(data < node->data){
            return hasData(data,node->left);
        }
        else{
            return hasData(data,node->right);
        }
    }
public:

    bool hasData(int data)
    {
        return hasData(data,root);
    }

private:
    BinaryTreeNode<int>* insert(int data,BinaryTreeNode<int>* node)
    {
        if(node == NULL)
        {
            BinaryTreeNode<int>* newnode = new BinaryTreeNode<int>(data);
            return newnode;
        }

        if(data < node->data){
            BinaryTreeNode<int>* leftTree = insert(data,node->left);
            node->left=leftTree;
        }else{
            BinaryTreeNode<int>* rightTree = insert(data,node->right);
            node->right=rightTree;
        }
        return node;
    }

public:
    void insert(int data)
    {
        root = insert(data,root);
    }

private:

BinaryTreeNode<int>* deleteData(int data,BinaryTreeNode<int>* node)
{
    if(node == NULL)
    {
        return NULL;
    }
    if(node->data == data)
    {
        if(node->left == NULL && node->right == NULL)
        {
            delete node;
            return NULL;
        }else if(node ->left == NULL && node->right != NULL)
        {
            BinaryTreeNode<int>* newRoot = node->right;
            node->right=NULL;
            delete node;
            return newRoot;
        }else if(node->right == NULL && node->left != NULL)
        {
            BinaryTreeNode<int>* newRoot = node->left;
            node->left=NULL;
            delete node;
            return newRoot;
        }else
        {
            BinaryTreeNode<int>* rightMin = node->right;
            while(rightMin->left != NULL)
            {
                rightMin=rightMin->left;
            }
            node->data = rightMin->data;
            node->right = deleteData(rightMin->data,node->right);
            return node;
        }
    }

    if(data < node->data)
    {
        node->left = deleteData(data,node->left);
    }else
    {
        node->right = deleteData(data,node->right);
    }
    return node;
}


public:
    void deleteData(int data)
    {
        root = deleteData(data,root);
    }

private:
    void printTree(BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
            return;
        }
        cout <<root->data<<" : ";
        if(root->left != NULL)
        {
            cout <<"L"<<root->left->data<<" , ";
        }
        if(root->right!=NULL)
        {
            cout<<"R"<<root->right->data<<" ";
        }
        cout <<endl;
        printTree(root->left);
        printTree(root->right);
    }
public:
    void printTree()
    {
        printTree(root);
    }



};
