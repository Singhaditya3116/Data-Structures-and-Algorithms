#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout <<"Enter n ";
    cin >> n;

    /*
       *
      **
     ***
    ****
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=(n-i);j++)
        {
            cout <<' ';
        }

        for(int j=1;j<=i;j++)
        {
            cout <<"*";
        }
        cout <<endl;
    }
    ----------------------------------
    */
    /*
       1
      12
     123
    1234
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=(n-i);j++)
        {
            cout <<' ';
        }

        for(int j=1;j<=i;j++)
        {
            cout <<j;
        }
        cout <<endl;
    }
    ------------------------------------
    */
    /*
    ****
    ***
    **
    *

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=(n-i+1);j++)
        {
            cout <<"*";
        }
        cout <<endl;
    }
    -------------------------------------
    */

    /*
    1234
    123
    12
    1
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=(n-i+1);j++)
        {
            cout <<j;
        }
        cout <<endl;
    }
    -----------------------------------
    */

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=(n-i+1);j++)
        {
            cout <<i;
        }
        cout <<endl;
    }

    return 0;
}
