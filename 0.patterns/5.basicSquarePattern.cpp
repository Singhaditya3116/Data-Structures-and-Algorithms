#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout <<"enter N ";
    cin >> n;
    /*
    ****
    ****
    ****
    ****

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout <<"*";
        }
        cout<<endl;
    }
    -----------------------------------------------------------
    */

    /*
    1111
    2222
    3333
    4444

    for(int i=1;i<=n;i++)
    {
        for(int j =1;j<=n;j++)
        {
            cout <<i;
        }
        cout <<endl;
    }
    -----------------------------------------------------------
    */
    /*
    1234
    1234
    1234
    1234

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;4
        j++)
        {
            cout <<j;
        }
        cout <<endl;
    }
    ----------------------------------------------------------
    */

    /*
    4321
    4321
    4321
    4321
    */
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout <<n-j+1;
        }
        cout <<endl;
    }


    return 0;
}
