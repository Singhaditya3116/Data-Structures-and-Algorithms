#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    int smalloutput = fact(n-1);
    return n*smalloutput;
}

int main()
{
    int n;
    cin >> n;
    int output = fact(n);
    cout << output;
    return 0;
}
