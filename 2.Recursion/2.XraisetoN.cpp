#include<bits/stdc++.h>
using namespace std;

int power(int x,int n)
{
    if(n==0)
    {
        return 1;
    }

    int smallportion=power(x,n-1);
    return  x*smallportion;
}

int main()
{
    int x,n;
    cin >> x >>n;
    int output=power(x,n);
    cout << output;
    return 0;
}
