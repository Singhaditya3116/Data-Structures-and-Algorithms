#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout <<"Enter n";
    cin >> n ;
    /*
    ABCD
    ABCD
    ABCD
    ABCD
    ABCD

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
        char ch = 'A'+j-1;
            cout <<ch <<" ";
        }
        cout <<endl;
    }
    ---------------------------------
    */
    /*
    ABCD
    BCDE
    CDEF
    DEFG
    for(int i=1;i<=n;i++)
    {
        char ch = 'A' + i - 1;
        //cout <<"Address "<< &ch <<endl;
        for(int j=1;j<=n;j++)
        {
            cout << ch <<" ";
            ch++;
        }
        cout <<endl;
    }
    -------------------------------------
    */
    for(int i=1;i<=n;i++)
    {
        char ch = 'A' + i - 1;
        for(int j=1;j<=i;j++)
        {
            cout <<ch<<" ";
        }
        cout <<endl;
    }
    return 0;
}
