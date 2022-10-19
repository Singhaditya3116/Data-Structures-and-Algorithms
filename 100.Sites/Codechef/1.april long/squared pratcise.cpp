#include<bits/stdc++.h>
using namespace std;

bool isValid(long long int number)
{
    long long int root = sqrt(number);
    if(root*root == number) return true;

    int incremental = root+1;
    long long int remaining = pow(incremental,2) - number;

    root = sqrt(remaining);
    if(root*root == remaining) return true;

    return false;
}

int main()
{
    long long n;
    while(cin >> n)
    {
        cout << isValid(n) <<endl;
    }
}

