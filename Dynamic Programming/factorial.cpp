#include<bits/stdc++.h>
using namespace std;

//---------------------------------Normal Fibonacci code 2^N complexity------------------------------------
int fibonacci(int n)
{
    if(n==0| n==1)
    {
        return 1;
    }
    int smallpart = fibonacci(n-1)+fibonacci(n-2);
    return smallpart;

}

int fib(int n,int *arr)
{
    if(n==0 || n==1)
    {
        return 1;
    }

    if(arr[n]!=0)
    {
        return arr[n];
    }

    int output =fib(n-1,arr)+fib(n-2,arr);

    arr[n]=output;
    return output;
}

int main()
{
    int n;
    cin >>n;
    int arr[n+1]={0};

    //int output=fibonacci(n);

    int output = fib(n,arr);
    cout << output;


    return 0;
}
