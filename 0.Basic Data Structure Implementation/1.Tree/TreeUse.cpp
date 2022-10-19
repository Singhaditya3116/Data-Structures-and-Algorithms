#include<iostream>
#include<queue>
#include<algorithm>
#include "TreeNode.h"

using namespace std;

//take input by levelwise
TreeNode<int> *takeInputLevelwise()
{
    queue<TreeNode<int>*> q;
    int data;
    cout <<"Enter the root Data ";
    cin >>data;
    TreeNode<int> *root=new TreeNode<int>(data);
    q.push(root);

    while(q.empty()!=true)
    {
        TreeNode<int> *temp=q.front();
        q.pop();
        int n;
        cout <<"How many children does "<<temp->data<<" have ";
        cin >>n;
        for(int i=0;i<n;i++)
        {
            cout <<"Enter the " <<i+1<<" th children of "<<temp->data<<endl;
            cin >>data;
            TreeNode<int> *child = new TreeNode<int>(data);
            //static allocation ---->>> TreeNode<int> child(data)
            //The problem with static allocation in next iteration the memory will be gone.
            temp->children.push_back(child);
            q.push(child);
        }

    }

    return root;
}

//take input by depth
TreeNode<int> *takeInput()
{
    int rootData;
    cout <<"Enter the Data ";
    cin >>rootData;
    TreeNode<int> *root=new TreeNode<int>(rootData);

    int n;
    cout <<"How many children does "<<rootData<<" have ?"<<endl;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        TreeNode<int> *child=takeInput();
        root->children.push_back(child);
    }
    return root;
}

//print tree by level order traversal
void printTreeLevelwise(TreeNode<int> *root)
{
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.empty()!=true)
    {
        TreeNode<int> *temp=pendingNodes.front();
        pendingNodes.pop();
        cout <<temp->data<<" : ";
        for(int i=0;i<temp->children.size();i++)
        {
            cout <<temp->children[i]->data<<" , ";
            pendingNodes.push(temp->children[i]);
        }
        cout<<endl;
    }
}

//print tree by depth
void printTree(TreeNode<int> *root)
{
    if(root==NULL) // It is not the base case , it is just a corner case if input comes as NULL.
    {
        return;
    }
    cout <<root->data <<" : ";
    for(int i=0;i<root->children.size();i++)
    {
        cout <<root->children[i]->data<<" , ";
    }
    cout <<endl;
    for(int i=0;i<root->children.size();i++)
    {
        printTree(root->children[i]);
    }
}

//count no of nodes in tree
int countTreeNode(TreeNode<int> *root)
{
    if(root==NULL) //This is corner case not the base case.
    {
        return 0;
    }
    int sum=0;
    for(int i=0;i<root->children.size();i++) //children.szie() is acting as a base case.
    {
        sum+=countTreeNode(root->children[i]);
    }
    return sum+1;
}

//sum of all nodes in tree
int sumOfNode(TreeNode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int sum=0;
    for(int i=0;i<root->children.size();i++)
    {
        sum+=sumOfNode(root->children[i]);
    }
    return sum+root->data;
}

//find the maximum value among the node
int maxNode(TreeNode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int maximumValue=root->data;
    for(int i=0;i<root->children.size();i++)
    {
        maximumValue=max(maximumValue,maxNode(root->children[i]));
    }
    return maximumValue;
}

//height of the tree
int heightOfTree(TreeNode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int height=0;
    for(int i=0;i<root->children.size();i++)
    {
        height=max(height,heightOfTree(root->children[i]));
    }
    return height+1;
}

//print node at depth d;
void printNodeAtDepth(TreeNode<int> *root,int depth)
{
    if(root==NULL) //corner case;
    {
        return;
    }
    if(depth==0)    //Base case
    {
        cout <<root->data<<" ";
        return;
    }
    for(int i=0;i<root->children.size();i++)
    {
        printNodeAtDepth(root->children[i],depth-1);
    }

}

//count no of leaf node in tree
int countLeafNode(TreeNode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->children.size()==0)
    {
        return 1;
    }
    int count=0;
    for(int i=0;i<root->children.size();i++)
    {
        count+=countLeafNode(root->children[i]);
    }
    return count;
}

//Preorder Traversal :Root Left Right
void preorderTraversal(TreeNode<int> *root)
{
    if(root==NULL)
    {
        return;
    }
    cout <<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    {
        preorderTraversal(root->children[i]);
    }
}

void postorderTraversal(TreeNode<int> *root)
{
    if(root==NULL)
    {
        return;
    }
    for(int i=0;i<root->children.size();i++)
    {
        postorderTraversal(root->children[i]);
    }
    cout <<root->data<<" ";
}

void deleteTree(TreeNode<int> *root)
{
    if(root==NULL)
    {
        return;
    }
    for(int i=0;i<root->children.size();i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}

//Tree Input is 1 3 2 3 4 2 5 6 0 0 0 0
int main()
{
    /*
    Manually making the tree

    TreeNode<int> *root=new TreeNode<int> (1);
    TreeNode<int> *node1=new TreeNode<int> (2);
    TreeNode<int> *node2=new TreeNode<int> (3);

    root->children.push_back(node1);
    *(root).children.push_back(node1);
    root->children.push_back(node2);
    */

    //TreeNode<int> *root=takeInput();
    TreeNode<int> *root=takeInputLevelwise();
    printTreeLevelwise(root);
    cout <<"Total number of nodes are "<<countTreeNode(root)<<endl;
    cout <<"Sum of all nodes is "<<sumOfNode(root)<<endl;
    cout <<"maximum value in tree is "<<maxNode(root)<<endl;
    cout <<"height of the tree is "<<heightOfTree(root)<<endl;
    cout <<"Node at depth d/Distance k=1 is ";printNodeAtDepth(root,1);cout<<endl;
    cout <<"Count of Leaf Node in this tree is "<<countLeafNode(root)<<endl;
    cout <<"Preorder Traversal of the tree is ";preorderTraversal(root);cout<<endl;
    cout <<"Postorder Traversal of the tree is ";postorderTraversal(root);cout<<endl;
    cout <<"TREE DELETED ";deleteTree(root);cout<<endl;
    //cout <<root->data<<" "<<root->children[0]->data<<endl;

    return 0;
}
