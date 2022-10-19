#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

class jobs{
    public:
        int start=0;
        int end=0;
        int profit=0;
};

bool compare(jobs a,jobs b)
{
    return a.end < b.end;
}

int findprevious(jobs *arr,int *dp,int n,int low,int high,int STARTtime)
{
    int maxProfit=INT_MIN;
    int index=-1;
    for(int i=0;i<=high;i++)
    {
        if(arr[i].end <= STARTtime)
        {
            if(dp[i] > maxProfit)
            {
                maxProfit=dp[i];
                index=i;
            }
        }
    }
    return index;
}

int solve(jobs *arr,int n,int  *dp)
{
    for(int i=1;i<n;i++)
    {
        int STARTtime=arr[i].start;

        int j=findprevious(arr,dp,n,0,i-1,STARTtime);
        if(j!=-1)
        {
            dp[i]=dp[j]+arr[i].profit;
        }
    }

}

int main()
{
    int n;
    cin >> n;
    int dp[n];
    jobs arr[n];

    for(int i=0;i<n;i++)
    {
        cin >> arr[i].start >> arr[i].end >> arr[i].profit;
    }

    sort(arr,arr+n,compare);
    for(int i=0;i<n;i++) dp[i]=arr[i].profit;

    solve(arr,n,dp);

    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(dp[i]>max)
        {
            max=dp[i];
        }
    }
    cout <<max <<endl;
    return 0;
}
