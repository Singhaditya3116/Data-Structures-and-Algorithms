#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *lchild=NULL;
    Node *rchild=NULL;
    int height=0;
};
Node * root =NULL;

int nodeHeight(Node *p) // Calculating height of every node.
{
    int leftTreeHeight=0,rightTreeHeight=0;
    if(p != NULL && p->lchild != NULL) //IF left child  exist.
    {
        leftTreeHeight = p->lchild->height;
    }
    if(p!=NULL && p->rchild!=NULL)
    {
        rightTreeHeight=p->rchild->height;
    }
    return max(leftTreeHeight,rightTreeHeight) +1;
}

int balanceFactor(Node *p) //Calculating Balance factor.
{
    int heightOfLeftSubtree=0;
    int heightOfRightSubtree=0;
    if(p->lchild !=NULL)
    {
        heightOfLeftSubtree=p->lchild->height;
    }

    if(p->rchild!=NULL)
    {
        heightOfRightSubtree=p->rchild->height;
    }
    return heightOfLeftSubtree-heightOfRightSubtree;
}

//---Rotations------

Node *llRotation(Node *p)
{
    Node *pLchild = p->lchild; //assign to node
    Node *pLchildRchild = pLchild->rchild; //assign to node

    p->lchild = pLchildRchild; //Doing the rotation
    pLchild->rchild=p;          //Doing the rotation

    p->height = nodeHeight(p);  //While doing rotation the height will change.
    pLchild->height = nodeHeight(pLchild);

    if(root == p)
    {
        root = pLchild;
    }
    return pLchild;
}

Node *rrRotation(Node *p)
{
    Node *pRchild = p->rchild; //assigning of node.
    Node *pRchildLchild = pRchild->lchild;

    pRchild->lchild=p;  //Doing the appropriate rotation.
    p->rchild=pRchildLchild;

    p->height = nodeHeight(p);    //while doing the rotation the height will change
    pRchild->height = nodeHeight(pRchild);

    if(root == p)
    {
        root = pRchild;
    }
    return pRchild;
}

Node *lrRotation(Node *p)
{
    cout <<"hello" <<endl;
    Node *pLchild = p->lchild;
    Node *pLchildRchild = pLchild->rchild;

    pLchild->rchild=pLchildRchild->lchild; //Doing appropraite rotation
    p->lchild=pLchildRchild->rchild;

    pLchildRchild->lchild=pLchild;
    pLchildRchild->rchild=p;

    pLchild->height=nodeHeight(pLchild); //while doing rotation height will change.
    p->height=nodeHeight(p);
    pLchildRchild->height =nodeHeight(pLchildRchild);

    if(root == p)
    {
        root =pLchildRchild;
    }
    return pLchildRchild;
}

Node *rlRotation(Node *p)
{
    Node *pRchild = p->rchild;
    Node *pRchildLchild = pRchild->lchild;

    p->rchild=pRchildLchild->lchild; //Doing appropriate Rotation.
    pRchild->lchild=pRchildLchild->rchild;
    pRchildLchild->lchild=p;
    pRchildLchild->rchild=pRchild;

    p->height=nodeHeight(p); //While doing rotation height will change.
    pRchild->height = nodeHeight(pRchild);
    pRchildLchild->height=nodeHeight(pRchildLchild);

    if(root ==p)
    {
        root=pRchildLchild;
    }
    return pRchildLchild;
}

//----Rotation Over------
Node *createTree(Node *p,int value)
{
    if(p == NULL)
    {
        Node * newnode = new Node;
        newnode->data=value;
        newnode->height=1;

        return newnode;
    }

    if(value > p->data)
    {
        p->rchild=createTree(p->rchild,value);
    }
    else
    {
        p->lchild=createTree(p->lchild,value);
    }
    p->height = nodeHeight(p);

    if(balanceFactor(p)==2 && balanceFactor(p->lchild)==1) //condition to do LL rotation
    {
        return llRotation(p);
    }
    else if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==-1) //condition for RR rotation
        {
            return rrRotation(p);
        }
        else if(balanceFactor(p)==2 && balanceFactor(p->lchild)==-1) //condition for LR rotation
            {
                return lrRotation(p);
            }
            else if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==1) //condition for RL rotation
                {
                    return rlRotation(p);
                }
    return p;
}

void Inorder(Node *p)
{
    if(p == NULL)
    {
        return;
    }
    Inorder(p->lchild);
    cout << p->data <<" ";
    Inorder(p->rchild);

}
void level(Node *p)
{
    queue <Node *> q;
    q.push(p);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        cout << p->data << " ";
        if(p->lchild!=NULL)q.push(p->lchild);
        if(p->rchild!=NULL)q.push(p->rchild);
    }
}

int main()
{
    root =createTree(root,14);
    int value;
    while(true)
    {
        cout <<"Enter the value to be inserted ";
        cin >> value;
        createTree(root,value);
        level(root);
        cout <<endl;
    }
    return 0;
}
