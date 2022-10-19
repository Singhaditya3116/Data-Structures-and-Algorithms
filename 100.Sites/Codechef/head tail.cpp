#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int A[n]={0};
    for(int i=0;i<n;i++)
    {
        char input;
        cin >> input;
        if(input == 'H')
        {
            A[i]=1;
        }
        else
        {
            A[i]=0;
        }
    }
    int temp=0;
    while(temp!=k)
    {
        int value=A[n-temp-1];
        if(value == 1)
        {
            A[n-temp-1]=0;
            for(int j=n-temp-2;j>=0;j--)
            {
                if(A[j]==1)
                {
                    A[j]==0;
                }
                else
                {
                    A[j]==1;
                }
            }
        }
        temp++;
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==1)
        {
            count++;
        }
    }
    cout <<count<<endl;

}
