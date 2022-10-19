#include<iostream>

using namespace std;

int findSum(int *arr,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        //cout <<arr[i] << " ";
        sum+=arr[i];
    }
    return sum;
}

int main()
{
    int n,l,r;
    cin >> n >> l >>r;
    int minarr[n],maxarr[n];

    int number=1;
    int count=0;
    int min=1;
    for(int i=0;i<n;i++)
    {
        if(count >= l)
        {
            minarr[i]=min;
        }
        else
        {
            minarr[i]=number;
            number*=2;
            count++;
        }
    }

    count=0;
    number=1;
    int max1=1;
    for(int i=0;i<n;i++)
    {
        if(count >=r)
        {
            maxarr[i]=max1;
        }
        else
        {
            max1=max(max1,number);
            maxarr[i]=number;
            count++;
            number=number*2;
        }
    }

    cout <<findSum(minarr,n) << " " <<findSum(maxarr,n) <<endl;

    return 0;
}
