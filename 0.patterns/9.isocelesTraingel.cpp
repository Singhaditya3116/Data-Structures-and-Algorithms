#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout <<"Enter n ";
    cin >> n;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=(n-i);j++)
        {
            cout <<" ";
        }

        int k=1;
        while(k<=i)
        {
            cout <<k;
            k++;
        }
        k=i-1;
        while(k>0)
        {
            cout <<k;
            k--;
        }
        cout <<endl;
    }

    return 0;
}
