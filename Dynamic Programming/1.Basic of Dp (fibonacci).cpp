#include<bits/stdc++.h>
using namespace std;


int fib(int n) //Normal exponential approach -- 2^N Time complexity
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }

    int smalloutput = fib(n-1) + fib(n-2);
    return smalloutput;
}

int fib2(int n,int * arr) // DP approach (storing the work which is repeated) --O(2*N) Time complexity
{
    if(n==0)
    {
        arr[0]=0;
        return 0;
    }
    if(n==1)
    {
        arr[1]=1;
        return 1;
    }

    if(arr[n] > 0) // Checking if value present
    {
        return arr[n]; // if present return the value and not do any work below;
    }

    int smalloutput = fib2(n-1,arr) + fib2(n-2,arr);
    arr[n]=smalloutput; //storing the work which is done
    return arr[n];
}




int main()
{
    int n;
    cin >> n;
    //cout << fib(n);
    int arr[n+1]={};
    cout << fib2(n,arr);


    return 0;
}


