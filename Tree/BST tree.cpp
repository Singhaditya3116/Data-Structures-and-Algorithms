#include<bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *lchild=NULL;
    int data=0;
    struct Node *rchild=NULL;
};
struct Node *root=NULL;

void create() //crearing BST iteratively.
{
    while(true)
    {
        int x,flag=0;
        cout << "Enter the node value ";
        cin >> x;
        if(x==0) break;
        Node *newnode = new Node;
        newnode->data=x;
        if(root == NULL)
        {
            root=newnode;
            continue;
        }
        struct Node *temp=root;
        struct Node *tail=root; //storing tail
        while(temp!=NULL)
        {
            tail=temp;
            if(x > (temp->data))
            {
                temp=temp->rchild;
            }
            else if(x < (temp->data))
            {
                temp=temp->lchild;

            }
            else
            {
                flag=1;
                break; //if trying to insert duplicate items;
            }
        }
        if(flag == 1)
        {
            continue;
        }
        if(x > tail->data)
        {
            tail->rchild=newnode;
        }
        else
        {
            tail->lchild=newnode;
        }
    }
}

Node *insertRecur(Node *p,int value) //insert recursively in the BST
{
    if(p == NULL)
    {
        Node *newnode = new Node;
        newnode->data=value;
        return newnode;
    }
    if(value > p->data)
    {
        p->rchild=insertRecur(p->rchild,value);
    }
    else if(value < p->data){
        p->lchild=insertRecur(p->lchild,value);
    }
}

Node *inoPredecessor(Node *p) //find the maxium value from the right subtree.
{
    Node *temp=p;
    while(p!=NULL)
    {
        temp=p;
        p=p->rchild;
    }
    return temp;
}


struct Node *deleteNode(struct Node *root,int value)
{
    if(root == NULL) return root;
    else if(value > root->data) root->rchild=deleteNode(root->rchild,value);
    else if(value < root->data) root->lchild=deleteNode(root->lchild,value);
    else // when root->data becomes same as value
    {
        // case 1: no child;
        if(root->lchild == NULL && root->rchild == NULL)
        {
            delete root;
            root=NULL;
            return root;
        }
        else
        {
            if(root->lchild == NULL) //case 2: if only one child present;
            {
                Node *temp=root;
                root=root->rchild;
                delete temp;
                return root;
            }
            else
            {
                if(root->rchild == NULL)
                {
                    Node *temp=root;
                    root=root->lchild;
                    delete  temp;
                    return root;
                }
                else  //case 3: two child present
                {
                    Node *temp =inoPredecessor(root->lchild);
                    root->data=temp->data;
                    root->lchild=deleteNode(root->lchild,temp->data);
                    return root;
                }
            }
        }
    }
    return root;
}


void Inorder(Node *p)
{
    if(p == NULL)
    {
        return;
    }
    Inorder(p->lchild);
    cout << p->data <<  " ";
    Inorder(p->rchild);
}

string searchvalue(Node *p)
{
    int val;
    cout << "Enter the value to be searched";
    cin >> val;
    while(p!=NULL)
    {
        if(val == p->data)
        {
            return "Value found";
        }
        if(val > p->data)
        {
            p=p->rchild;
        }
        else
        {
            p=p->lchild;
        }
    }
    return "Value not found";
}
int main()
{
    create(); // inserting in BST iterative
    //recursive insert -------------------------------------
   /*
   root=insertRecur(root,25); // Inserting in BSt recursively
    insertRecur(root,2);
    insertRecur(root,15);
    insertRecur(root,29);
    insertRecur(root,45);
    insertRecur(root,10);
    insertRecur(root,67);
    insertRecur(root,89);
    */
    //------------------------------------------------------
    cout << searchvalue(root) <<endl;
    Inorder(root);
    root = deleteNode(root,15);
    cout << endl;
    Inorder(root);
    return 0;
}
