#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int A[n];
        int flag=0;
        for(int i=0;i<n;i++)
        {
            cin >> A[i];
        }

        int count=6;
        for(int i=0;i<n;i++)
        {
            if(A[i] == 0)
            {
                count++;
            }
            else
            {
                if(count < 6)
                {
                    cout << "No" <<endl;
                    flag=1;
                    break;
                }
                count=1;
            }
        }
        if(flag == 0)
        {
            cout << "Yes" <<endl;

        }
    }
    return 0;
}
