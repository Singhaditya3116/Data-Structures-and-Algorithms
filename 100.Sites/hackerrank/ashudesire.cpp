#include<bits/stdc++.h>

using namespace std;
int main()
{
    int N,i;
    cin >> N;
    long long int A[N];
    for(i=0;i<N;i++)
    {
        cin >> A[i];
    }

    for(i=0;i<N;i++)
    {
        int sum=0;
        long long int num =A[i];
        while(num!=0)
        {
            int rem=num%2;
            sum+=rem;
            num = num/2;
        }

        if(sum%10==0)
        {
            cout << "Win" << endl;
        }
        else
        {
            cout << "Loose" <<endl;
        }
    }

    return 0;
}



