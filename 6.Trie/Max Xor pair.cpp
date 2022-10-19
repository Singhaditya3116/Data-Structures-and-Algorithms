#include<bits/stdc++.h>
using namespace std;

class trienode{
public:
    trienode* left;
    trienode* right;
};

int insertValue(int n /*which numerical value to insert*/,trienode* head)
{
    trienode* currnode=head;//temporary pointer.

    for(int i=31;i>=0;i--)
    {
        int b=(n>>i)&1; //IT gets the ith bit of the number n.

        if(b==0)
        {
            if(!currnode->left)//if leftnode not exist  create a left node.
            {
                 currnode->left=new trienode();
            }
            currnode=currnode->left;

        }else{
            if(!currnode->right)//if right node not exist create right node.
            {
                currnode->right=new trienode();
            }
            currnode=currnode->right;
        }
    }
}

int findMaxXorPair(trienode* head,int* arr,int arrsize)
{
    int max_xor=INT_MIN;
    for(int i=0;i<arrsize;i++)
    {
        trienode* curr=head;
        int value=arr[i];
        int curr_xor;
        curr_xor=0;

        for(int j=31;j>=0;j--)
        {
            int bit=(value>>j)&1;
            if(j==31)
            {
                cout<<bit<<endl;
            }

            if(bit==0)
            {
               if(curr->right)
               {
                   curr_xor+=pow(2,j);
                   cout <<value<<" "<<j<<" "<<curr_xor<<endl;
                   curr=curr->right;
               }
               else
               {
                   curr=curr->left;
               }

            }
            else
            {
                if(curr->left)
                {
                    curr_xor+=pow(2,j);
                    cout <<value<<" "<<j<<" "<<curr_xor<<endl;
                    curr=curr->left;
                }
                else
                {
                    curr=curr->right;
                }
            }
        }
        if(curr_xor>max_xor)
        {
            max_xor=curr_xor;
        }
        cout<<"max loop"<<max_xor<<endl;
    }

   return max_xor;
}



int main()
{
    int n;
    cin >>n;
    trienode* head=new trienode();
    int* arr=new int[n];
    for(int i=0;i<n;i++)
    {
         int x;
         cin>>x;
         arr[i]=x;
         insertValue(x,head);
    }
    cout<<"max"<<findMaxXorPair(head,arr,n);




    return 0;
}
