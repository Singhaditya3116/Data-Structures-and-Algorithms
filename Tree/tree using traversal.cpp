#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *lchild=NULL;
    struct Node *rchild=NULL;
};
struct Node *root=NULL;
int preindex=0;
int searchindex(int *inorder,int value)
{
    int i=0;
    while(inorder[i]!=value)
    {
        i++;
    }
    return i;
}

Node *buildtree(int *preorder,int *inorder,int si,int end)
{
    if(si > end)
    {
        return NULL;
    }
    int value=preorder[preindex];
    preindex++;
    //cout << "value" <<value <<endl;
    struct Node *newnode =new Node;
    newnode->data=value;

    if(root == NULL) root=newnode;

    int index=searchindex(inorder,value);
    //cout <<"si " <<index <<endl;
    newnode->lchild= buildtree(preorder,inorder,si,index-1);
    newnode->rchild = buildtree(preorder,inorder,index+1,end);
    //return newnode;
}

void preorder1(Node *p)
{
    if(p == NULL)
    {
        return;
    }
    cout << p->data << " ";
    preorder1(p->lchild);
    preorder1(p->rchild);
}

int main()
{
    int preorder[]={4,7,9,6,3,2,5,8,1};
    int inorder[]={7,6,9,3,4,5,8,2,1};

    int size=sizeof(preorder)/sizeof(int);
    buildtree(preorder,inorder,0,size-1);
    cout << "preorder is ";
    preorder1(root);
    return 0;
}
