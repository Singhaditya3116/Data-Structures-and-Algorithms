#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n==1)
        {
            cout <<"1"<<"\n";
            cout << "1 1" <<"\n";
            continue;
        }
        cout << n/2 <<"\n";
        if(n == 2)
        {
            cout << "2 1 2" <<"\n";
            continue;
        }
        if(n>=3)cout << "3 1 2 3" <<"\n";

        for(int i=4;i<=n;i+=2)
        {
            if(i == n)
            {
                cout << "1 " << n <<"\n";
                break;
            }
            cout << "2 " << i <<" " <<i+1 <<"\n";
        }

    }
    return 0;
}
