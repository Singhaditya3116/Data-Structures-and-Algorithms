
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *lchild=NULL;
    struct Node *rchild=NULL;
};
struct Node *root=NULL;
int postindex=0;
int searchindex(int *inorder,int value)
{
    int i=0;
    while(inorder[i]!=value)
    {
        i++;
    }
    return i;
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

Node *buildtree(int *postorder,int *inorder,int si,int end)
{
    if(si > end)
    {
        return NULL;
    }
    struct Node *newnode=new Node;
    int value=postorder[postindex];
    postindex--;
    newnode->data=value;
    if(root==NULL) root=newnode;

    int index=searchindex(inorder,value);
    newnode->rchild=buildtree(postorder,inorder,index+1,end);
    newnode->lchild=buildtree(postorder,inorder,si,index-1);
}

int size=0;
int main()
{
    int postorder[]={6,3,9,7,8,5,1,2,4};
    int inorder[]={7,6,9,3,4,5,8,2,1};

    size=sizeof(postorder)/sizeof(int);
    postindex=size-1;
    buildtree(postorder,inorder,0,size-1);
    cout << "preorder is ";
    preorder1(root);
    return 0;
}
