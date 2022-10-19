
#include<bits/stdc++.h>
#include<set>
using namespace std;

bool isCoprime(int n1,int n2)
{
    for(int i=2;i<=min(n1,n2);i++)
    {
        if(n1%i==0 && n2%i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << isCoprime(2,4);


    return 0;
}
