#include<bits/stdc++.h>
using namespace std;

void findmax(int *arr,int size,int &max1,int &max2,int &index1,int &index2)
{
    for(int i=1;i<size;i++)
    {
        if(arr[i] > max1)
        {
            max2=max1;
            index2=index1;
            max1=arr[i];
            index1=i;
        }
        else
        {
            if(arr[i] <=max1 && arr[i] >=max2 )
            {
                max2=arr[i];
                index2=i;
            }
        }
    }
}

int main()
{

    int a,b,c;
    int A[4];
    for(int i=1;i<4;i++)
    {
        cin >> A[i];
    }
    int bond12=0;
    int bond23=0;
    int bond31=0;
    while(a!=0 || b!=0 || c!=0)
    {
        int max1=0,index1=0;
        int max2=0,index2=0;
        findmax(A,4,max1,max2,index1,index2);
        if(index1+index2 == 3)
        {
            bond12++;
            A[1]--;
            A[2]--;
        }
    }
}
