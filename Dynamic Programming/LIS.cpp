#include<bits/stdc++.h>
using namespace std;

int LIS(int *A,int size)
{
    int output[size];//An array which will contain all LIS upto ith index
    output[0]=1;//First element is always 1 because it is starting sequence

    for(int i=1;i<size;i++)
    {
        output[i]=1; // kharab se kharab 1 toh LIS hoga he
        int possans=0;
        for(int j=i-1;j>=0;j--)
        {
            if(A[j] < A[i]) // if previous numbers are smaller then only the LIS count will change
            {
                possans = output[j]+1;
                if(possans > output[i])  //Multiple LIS will be there to compute best one this is done
                {
                    output[i]=possans;
                }
            }
        }
    }

    int best=0;
    for(int i=0;i<size;i++)//find the maximum count of LIS form the output array
    {
        if(best < output[i])
        {
            best = output[i];
        }
    }
    return best;
}

int main()
{
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin >> A[i];
    }
    int ans = LIS(A,n);
    cout << ans<<endl;
    return 0;
}
