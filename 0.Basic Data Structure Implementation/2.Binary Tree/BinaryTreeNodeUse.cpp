#include<bists/stdc++.h>
#include "BinaryTreeNode.h"
#include "2.BinarySearchTree.h"
#include<queue>
using namespace std;

//print tree in depth wise
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

//print Levelwise
void printLevelWise(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(q.empty() != true)
    {
        BinaryTreeNode<int>* temp=q.front();
        q.pop();
        cout <<temp->data<<" : ";

        if(temp->left != NULL)
        {
            cout <<"L"<<temp->left->data<<" , ";
            q.push(temp->left);
        }

        if(temp->right != NULL)
        {
            cout <<"R"<<temp->right->data<<" ";
            q.push(temp->right);
        }
        cout<<endl;
    }
}

//take input Recursive
BinaryTreeNode<int>* takeInput(){

    int rootData;
    cout <<"Enter Data ";
    cin >>rootData;
    if(rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* lchild=takeInput();
    BinaryTreeNode<int>* rchild=takeInput();

    root->left=lchild;
    root->right=rchild;

    return root;
}

//take input Levelwise
BinaryTreeNode<int>* takeInputLevelwise()
{
    int rootData;
    cout <<"Enter root Data "<<endl;
    cin >>rootData;
    if(rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;

    pendingNodes.push(root);

    while(pendingNodes.empty()!=true)
    {
        BinaryTreeNode<int>* temp=pendingNodes.front();
        pendingNodes.pop();

        int leftData;
        cout <<"Enter left child of "<<temp->data<<endl;
        cin >>leftData;
        if(leftData != -1)
        {
            BinaryTreeNode<int>* lchild=new BinaryTreeNode<int>(leftData);
            temp->left=lchild;
            pendingNodes.push(lchild);
        }

        int rightData;
        cout <<"Enter right child of "<<temp->data<<endl;
        cin >>rightData;
        if(rightData != -1)
        {
            BinaryTreeNode<int>* rchild=new BinaryTreeNode<int>(rightData);
            temp->right=rchild;
            pendingNodes.push(rchild);
        }

    }

    return root;
}

//Number of nodes in a Binary Tree
int numNodes(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int count=0;
    count+=numNodes(root->left);
    count+=numNodes(root->right);
    return count+1;
}

//maximum node in a Binary Tree
int maxNodeValue(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int maxvalue=0;
    maxvalue=max(maxNodeValue(root->left),maxvalue);
    maxvalue=max(maxNodeValue(root->right),maxvalue);
    return max(maxvalue,root->data);
}

//Height of a binary Tree
int heightOfTree(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int height=0;
    height=max(height,heightOfTree(root->left));
    height=max(height,heightOfTree(root->right));
    return height+1;
}

//Traversals;
void inorder(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout <<root->data<<" ";
    inorder(root->right);
}

void preorder(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    cout <<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout <<root->data<<" ";
}

//---------------------------------------------Diameter--------------------

class both{
public:
    int diameter;
    int height;

    both()
    {
        diameter=0;
        height=0;
    }
};

both findDiameterAndHeight(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        both  x;
        x.diameter=0;
        x.height=0;
        return x;
    }

    both leftTask = findDiameterAndHeight(root->left);
    both rightTask = findDiameterAndHeight(root->right);

    both ans;
    ans.height = max(leftTask.height,rightTask.height) +1;
    ans.diameter = max(leftTask.height+rightTask.height,max(leftTask.diameter,rightTask.diameter));
    return ans;
}


int diameter(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return 0;
    }
    both ans = findDiameterAndHeight(root);
    return ans.diameter;
}

//--------------------------------------Diameter -----OVER-----------------

//-------------------------------Check if Binary Tree is BST--------------------


int maximum(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}

int minimum(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return INT_MAX;
    }
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}

bool isBST(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

    if(root->data <= leftMax || root->data > rightMin)
    {
        return false;
    }

    return isBST(root->left) && isBST(root->right);
}

////////////////optimal one---2nd method
class BSTcomponent{
    public:
        int maxValue;
        int minValue;
        bool isBSTvalue;

        BSTcomponent(){
            maxValue=INT_MIN;
            minValue=INT_MAX;
            isBSTvalue=true;
        }
};

BSTcomponent isBSToptimal(BinaryTreeNode<int>* root){
    if(root == NULL)
    {
        BSTcomponent b1;
        return b1;
    }
    BSTcomponent leftTree = isBSToptimal(root->left);
    BSTcomponent rightTree = isBSToptimal(root->right);

    BSTcomponent b2;
    int overallMin = min(root->data,min(leftTree.minValue,rightTree.minValue));
    int overallMax = max(root->data,max(leftTree.maxValue,rightTree.maxValue));
    b2.minValue=overallMin;
    b2.maxValue=overallMax;
    if((root->data <= leftTree.maxValue) || (root->data > rightTree.minValue) || (leftTree.isBSTvalue == false || (rightTree.isBSTvalue == false)))
    {
        b2.isBSTvalue=false;
    }
    return b2;
}

////3rd method

bool isBST3(BinaryTreeNode<int>* root,int low,int high)
{
    if(root == NULL)
    {
        return true;
    }

    if(root->data < low && root->data > high)
    {
        return false;
    }
    bool isLeftBst = isBST3(root->left,low,(root->data - 1));
    bool isRightBst = isBST3(root->right,root->data,high);
    return isLeftBst && isRightBst;
}

//-------------------------------Check if Binary Tree is BST  ----- OVER---------------


//--------------------Convert BST to sorted linked list ------------------
class linkedList{
    public:
        int data;
        linkedList *next;
        linkedList(int data)
        {
            this->data = data;
            next=NULL;
        }
};

class node{
    public:
        linkedList *head=NULL;
        linkedList *tail=NULL;
};
node *convertBSTtoLinkedlist(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        node *newnode =new node;
        return newnode;
    }
    node *left = convertBSTtoLinkedlist(root->left);
    linkedList *newnode = new linkedList(root->data);
    node *right = convertBSTtoLinkedlist(root->right);
    node *n2 =new node;
    if(left->head == NULL)
    {
        n2->head= newnode;
        n2->tail=newnode;
    }
    else
    {
        left->tail->next=newnode;
        n2->head=left->head;
        n2->tail=newnode;
    }

    if(right->head != NULL)
    {
        n2->tail->next=right->head;
        n2->tail=right->tail;
    }
    return n2;

}

//-----------------------------BST to sorted linked list OVER---------------



//1 2 3 4 5 6 -1 -1 -1 7 8 -1 -1 -1 -1 -1 -1
// 17 10 19 5 15 18 20 -1 -1 -1 -1 -1 -1 -1 -1
// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{

    /*
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1=new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2=new BinaryTreeNode<int>(3);
    root->left=node1;
    root->right=node2;
    printTree(root);
    */

    //BinaryTreeNode<int>* root=takeInput();
    //printTree(root);
    BinaryTreeNode<int>* root=takeInputLevelwise();
    printLevelWise(root);
    cout <<"Number of Nodes in a tree is "<<numNodes(root)<<endl;
    cout <<"Height of the tree is "<<heightOfTree(root)<<endl;
    cout <<"Maximum Value int the tree is "<<maxNodeValue(root)<<endl;
    cout <<"Inorder traversal of the tree is ";inorder(root);cout<<endl;
    cout <<"Preoder traversal of the tree is ";preorder(root);cout<<endl;
    cout <<"Postorder traversal of the tree is ";postorder(root);cout<<endl;
    cout <<"Diameter of a Binary tree is "<<diameter(root)<<endl;
    cout <<"IS this tree is a BST "<<isBST(root) <<endl;
    cout <<" Now optimal value "<<isBSToptimal(root).isBSTvalue<<" 3rd method "<<isBST3(root,INT_MIN,INT_MAX)<<endl;

    node *n =convertBSTtoLinkedlist(root);
    cout <<"head "<<n->head <<" "<<n->tail<<endl;
    linkedList *temp = n->head;
    while(temp!=NULL)
    {
        cout <<temp->data<<" ";
        temp=temp->next;
    }



    delete root;

    /*
    ------------------BST implementation-----------------
    BST b1;
    b1.insert(10);
    b1.insert(5);
    b1.insert(15);
    b1.insert(1);
    b1.insert(7);
    //b1.insert(13);
    cout <<b1.hasData(100)<<endl;
    b1.printTree();
    b1.deleteData(10);
    b1.printTree();
    */

    return 0;
}
