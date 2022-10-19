#include<bits/stdc++.h>

using namespace std;

int coin_change(int *d,int size,int value)
{

    if(value == 0)
    {
        return 1;
    }
    if(value < 0)
    {
        return 0;
    }
    if(size == 0)
    {
        return 0;
    }


    int first = coin_change(d,size,value-d[0]);
    int second = coin_change(d+1,size-1,value);
    return first + second;
}



int main()
{
    int n;
    cin >> n;
    int d[n];
    for(int i=0;i<n;i++)
    {
        cin >> d[i];
    }
    int value;
    cin >> value;

    int ans = coin_change(d,n,value);
    cout << ans<<endl;
}
