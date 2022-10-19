#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll kadane(int arr[],int n)
{
    ll current_sum=0;
    ll best_so_far=INT_MIN;
    for(int i=0;i<n;i++)
    {
        current_sum+=arr[i];
        if(current_sum>best_so_far)
        {
            best_so_far = current_sum;
        }
        if(current_sum<0)
        {
            current_sum=0;
        }
    }
    return best_so_far;
}

ll maximumsubarray(int arr[],int n,int K)
{
    ll kadane_sum =kadane(arr,n);
    if(K==1)
    {
        return kadane_sum;
    }

    ll current_prefix_sum=0,curent_suffix_sum=0;
    ll best_prefix_sofar=INT_MIN,best_suffix_sofar=INT_MIN;

    for(int i=0;i<n;i++)
    {
        current_prefix_sum=current_prefix_sum+arr[i];
        if(best_prefix_sofar<current_prefix_sum)
        {
            best_prefix_sofar=current_prefix_sum;
        }
    }
    ll totalsum=current_prefix_sum;

    for(int i=n-1;i>=0;i--)
    {
        curent_suffix_sum+=arr[i];
        if(best_suffix_sofar<curent_suffix_sum)
        {
            best_suffix_sofar=curent_suffix_sum;
        }
    }
    ll ans;
    if(totalsum>0)
    {
        ans=max((best_suffix_sofar+(totalsum*(K-2))+best_prefix_sofar),kadane_sum);
        return ans;
    }
    else{
        ans=max(best_prefix_sofar+best_suffix_sofar,kadane_sum);
        return ans;
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n,K;
        cin >> n >> K;
        int arr[n],sum=0;
        for(int i=0;i<n;i++)
        {
            cin >>arr[i];
        }
        cout << maximumsubarray(arr,n,K) << endl;
    }
    return 0;

}
