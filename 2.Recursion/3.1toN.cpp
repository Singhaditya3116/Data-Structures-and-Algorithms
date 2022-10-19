#include<bits/stdc++.h>
using namespace std;

int print(int n)
{
    if(n==1)
    {
        cout << 1 << " " ;
       return 1;
    }
    int smallsolution = print(n-1);
    cout << n << " " ;
    return 0;
}



int main()
{
    int n;
    cin >> n;
    printno(n);
    return 0;
}
