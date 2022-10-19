#include<bits/stdc++.h>
using namespace std;

void merge1(int A[],int si,int mid,int end)
{

    int temp[end-si+1];
    int i=si,j=mid+1,k=0;
    while(i<=mid && j<=end)
    {
        if(A[i]<A[j])
        {
            temp[k]=A[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=A[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        temp[k]=A[i];
        i++;
        k++;
    }
    while(j<=end)
    {
        temp[k]=A[j];
        k++;
        j++;
    }
    for(int i=si;i<=end;i++)
    {
        A[i]=temp[i-si];
    }


}

void mergesort(int A[],int si,int end)
{
    if(si>=end)
    {
        return ;
    }
    int mid = (si+end)/2;
    mergesort(A,si,mid);
    mergesort(A,mid+1,end);
    merge1(A,si,mid,end);
}

int main()
{
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin >>A[i];
    }
    mergesort(A,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout << A[i]<< " ";
    }
    return 0;
}






