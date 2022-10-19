#include<bits/stdc++.h>
#include<algorithm>
# define M 1000000007
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
        for(int i=0;i<n;i++)
        {
            cin >> A[i];
        }
        sort(A,A+n,greater<int>());

        long long int profit=0;
        long long int years=0;
        for(int i=0;i<n;i++)
        {
            int value= A[i]-years;
            if(value > 0)
            {
                profit+=value;
                profit%=M;
            }
            years++;
        }
        cout << profit << endl;
    }
    return 0;
}
