
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
    while(p!=NULL)
    {
        temp=p;
        if(value > p->data)
        {
            p=p->rchild;
        }else
		{
			if(value <= p->data)
			{
				p=p->lchild;
			}
		}
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
void insertPath(Node *p,vector<int> &v,int value)
{
    if(p == NULL)
    {
        return;
    }
    while(p->data != value)
    {
        v.push_back(p->data);
        if(value > p->data)
        {
            p=p->rchild;
        }
        else p=p->lchild;
    }
    v.push_back(p->data);
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

    int x,y;
    cin >> x >> y;
    vector<int> v1;
    vector<int> v2;
    insertPath(root,v1,x);
    insertPath(root,v2,y);
    vector<int> :: iterator it;
    vector <int> v;
    int i=0,j=0;
    for(i;v1[i]==v2[j];i++)
    {
        j++;
    }
    i--;
    j--;

    for(i;i<v1.size();i++)
    {
        v.push_back(v1[i]);
    }
    for(j;j<v2.size();j++)
    {
        v.push_back(v2[j]);
    }
    int temp=INT_MIN;
    for(int i=0;i<v.size();i++)
    {
        if(v[i] > temp) temp=v[i];
    }
    cout << temp <<endl;
}
