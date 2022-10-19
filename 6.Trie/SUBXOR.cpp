#include<bits/stdc++.h>
using namespace std;

class trienode{
public:
    trienode* left;
    trienode* right;
    int leftleafnode=0;
    int rightleafnode=0;
};

int insertValue(int n /*which numerical value to insert*/,trienode* head)
{
    trienode* currnode=head;//temporary pointer.

    for(int i=31;i>=0;i--)
    {
        int b=(n>>i)&1; //IT gets the ith bit of the number n.

        if(b==0)
        {
            currnode->leftleafnode+=1;
            if(!currnode->left)//if leftnode not exist  create a left node.
            {
                currnode->left=new trienode();
            }
            currnode=currnode->left;

        }
        else
        {
            currnode->rightleafnode+=1;
            if(!currnode->right)//if right node not exist create right node.
            {
                currnode->right=new trienode();

            }
            currnode=currnode->right;
        }
    }
}

int SubXor(int xorvalue,trienode* head,int k)
{
    trienode* curr=head;
    int currentxor=0;

    for(int j=31;j>=0;j--)
    {
        int bit=(xorvalue>>j)&1;
        int kvalue=(k>>j)&1;

        if(kvalue==0 && bit==0)
        {
            if(!curr->left)
            {
                return currentxor;
            }
            curr=curr->left;
        }
        else
        {
            if(kvalue==1 && bit==1)
            {
                currentxor+=curr->rightleafnode;
                if(!curr->left)
                {
                    return currentxor;
                }
                curr=curr->left;
            }
            else
            {
                if(kvalue==0 && bit==1)
                {
                    if(!curr->right)
                    {
                        return currentxor;
                    }
                    curr=curr->right;
                }
                else
                {
                    if(kvalue==1 && bit==0)
                    {
                        currentxor+=curr->leftleafnode;
                        if(!curr->right)
                        {
                            return currentxor;
                        }
                        curr=curr->right;
                    }
                }
            }
        }
    }

    return currentxor;
}

int main()
{
    int testcase;
    cin>>testcase;
    while(testcase--)
    {
    int n,k;
    cin >>n>>k;

    trienode* head=new trienode();
    int* arr=new int[n];
    for(int i=0;i<n;i++)
    {
         cin>>arr[i];
    }
    int xorvalue=0;
    int count=0; //count the no of subarray
    for(int i=0;i<n;i++)
    {
        int currentxor=INT_MIN;
        xorvalue=xorvalue^arr[i];

        insertValue(xorvalue,head);

        currentxor=SubXor(xorvalue,head,k);
        cout<<currentxor<<endl;

        if(currentxor<k)
        {
            count++;
        }

    }
    cout<<count<<endl;
    }

    return 0;
}
