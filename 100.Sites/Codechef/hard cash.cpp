#include<iostream>
#include<climits>

using namespace std;

int mincoin(int *A,long long int *sumarr,int size,int k)
{
    int minvalue=INT_MAX;
    int coinremoved=0;
    long long int coinadd=0;
    for(int i=0;i<size;i++)
    {
        coinremoved=sumarr[i]%k;
        coinadd=sumarr[size-1]-sumarr[i];
        int rem = coinadd%k;
        if(rem == 0)
        {
            if(coinremoved < minvalue)
            {
                minvalue=coinremoved;
            }
        }
        else
        {
            int minadd= k - rem;
            if(coinremoved < minadd)
            {
                continue;
            }
            else
            {
                long long int sum = coinadd + coinremoved;
                rem = sum % k;
                if(rem < minvalue)
                {
                    minvalue=rem;
                }
            }
        }

    }
    return minvalue;
}



int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n,k;
        cin >> n >>k;
        int A[n];
        long long int sumarr[n];
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
            cin >> A[i];
            sum+=A[i];
            sumarr[i]=sum;
        }

        cout << mincoin(A,sumarr,n,k) <<endl;
    }
}
