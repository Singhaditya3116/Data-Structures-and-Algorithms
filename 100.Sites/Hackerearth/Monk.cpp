#include<bits/stdc++.h>
using namespace std;

struct Node{
    struct Node *lchild=NULL;
    int data;
    struct Node *rchild=NULL;
};
struct Node *root=NULL;

void createBST(Node *p,int value)
{
    Node *newnode = new Node;
    newnode->data=value;
    if(root == NULL)
    {
        root=newnode;
        return;
    }
    Node *temp=p;
    int flag=0;
    while(p!=NULL)
    {
        temp=p;
        if(value > p->data)
        {
            p=p->rchild;
        }else
		{
			if(value < p->data)
			{
				p=p->lchild;
			}
			else
        	{
            	flag=1;
				break;
       		}
		}
    }
    if(flag == 1)
    {
        return;
    }
    if(value > temp->data)
    {
        temp->rchild=newnode;
    }
    else
    {
        temp->lchild = newnode;
    }
}

int height(Node *p)
{
    if(p == NULL)
    {
        return 0;
    }
    int option1=height(p->lchild);
    int option2=height(p->rchild);
    return (max(option1,option2)+1);
}


int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int value;
        cin >> value;
        createBST(root,value);
    }

    cout << height(root) ;
}
