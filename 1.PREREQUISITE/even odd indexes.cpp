#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin >> n;
    int A[n];
    for(i=0;i<n;i++)
    {
        cin >>  A[i];
    }

    int evensum=0,oddsum=0;
    for(i=0;i<n;i++)
    {
        if((A[i]%2==0)&&(i%2==0))
        {
            evensum+=A[i];

        }
        if((A[i]%2==1)&&(i%2==1))
        {
            oddsum+=A[i];
        }
    }
    cout << evensum << " " << oddsum;
    return 0;
}
