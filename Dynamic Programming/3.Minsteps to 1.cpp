#include<bits/stdc++.h>
using namespace std;

//Brute force approach
int minsteps(int n)
{
    if(n == 1)
    {
        return 0;
    }

    int option1 = minsteps(n-1);
    int option2=INT_MAX,option3=INT_MAX;

    if(n%2 == 0)
    {
        option2 = minsteps(n/2);
    }

    if(n%3 == 0)
    {
        option3 = minsteps(n/3);
    }
    return min(option1,min(option2,option3)) + 1;
}

//Memoization

int minsteps_better(int n,int *arr)
{
    if(n == 1)
    {
        return 0;
    }

    if(arr[n] != -1) //If i have already computed
    {
        return arr[n];
    }

    int option1=INT_MAX,option2=INT_MAX,option3=INT_MAX;
    option1 = minsteps_better(n-1,arr);
    if(n%2 == 0)
    {
        option2 = minsteps_better(n/2,arr);
    }

    if(n%3 == 0)
    {
        option3 = minsteps_better(n/3,arr);
    }
    int output = min(option1,min(option2,option3)) + 1;
    arr[n]=output;
    return output;
}

int minsteps_better(int n)
{
    int *arr = new int[n+1];
    for(int i=0;i<=n;i++)
    {
        arr[i]=-1;
    }
    return minsteps_better(n,arr);
}

//Iterative
int minsteps_dp(int n)
{
    int arr[n+1];
    arr[1]=0;
    for(int i=2;i<=n;i++)
    {
        int option1 = arr[i-1];
        int option2 = INT_MAX,option3 = INT_MAX;
        if(i%2 == 0)
        {
            option2 = arr[i/2];
        }

        if(i%3 == 0)
        {
            option3 = arr[i/3];
        }
        arr[i]=min(option1,min(option2,option3)) + 1;
    }
    return arr[n];
}


int main()
{
    int n;
    cin >> n;
    cout <<minsteps(n)<<endl;
    cout <<minsteps_better(n)<<endl;
    cout <<minsteps_dp(n) <<endl;
}
