
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout <<"Enter n ";

    cin >> n;

    /*
    1
    12
    123
    1234

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout <<j;
        }
        cout <<endl;
    }
    ----------------------------------------
    */

    /*
    1
    2 3
    4 5 6
    7 8 9 10

    int k=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout <<k<<" ";
            k++;
        }
        cout <<endl;
    }
    ------------------------------------------
    */

    /*
    1
    2 3
    3 4 5
    4 5 6 7
    */
    for(int i=1;i<=n;i++)
    {
        int k=i;
        for(int j=1;j<=i;j++)
        {
            cout << k <<" ";
            k++;
        }
        cout <<endl;
    }

    return 0;
}
