#include<bits/stdc++.h>
using namespace std;

void buildtree(int *arr,int *tree,int start,int end,int treenode)
{
    if(start == end)
    {
        tree[treenode]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    buildtree(arr,tree,start,mid,2*treenode);
    buildtree(arr,tree,mid+1,end,2*treenode+1);
    //cout << "hello " <<2*treenode<< " " << 2*treenode+1 << " " <<treenode <<" " << start<<" " <<end <<endl;
    tree[treenode]=tree[2*treenode]+tree[(2*treenode)+1];
}

void update(int *arr,int *tree,int start,int end,int treenode,int index,int value)
{
    if(start == end)
    {
        arr[start]=value;
        tree[treenode]=value;
        return;
    }

    int mid=(start+end)/2;
    if(index <= mid)
    {
        update(arr,tree,start,mid,2*treenode,index,value);
    }
    else
    {
       update(arr,tree,mid+1,end,(2*treenode)+1,index,value);
    }
    tree[treenode]=tree[2*treenode] + tree[2*treenode+1];
}

int main()
{
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin >> A[i];
    }
    int tree[2*n]={0};

    buildtree(A,tree,0,n-1,1);

    for(int i=1;i<2*n;i++)
    {
        cout << tree[i] <<endl;
    }
    update(A,tree,0,n-1,1,3,3);
    cout <<endl;
    for(int i=1;i<2*n;i++)
    {
        cout << tree[i] <<endl;
    }


    return 0;
}
