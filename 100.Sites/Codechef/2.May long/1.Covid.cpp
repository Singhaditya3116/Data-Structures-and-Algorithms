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
        for(int i=0;i<n;i++)
        {
            cin >> A[i];
        }
        int minValue=INT_MAX;
        int maxValue=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int currValue = A[i];
            int affected = 0;
            for(int j=i;j<n;j++)
            {
                int diff = abs(currValue - A[j]);
                if(diff <=2)
                {
                    currValue = A[j];
                    affected++;
                }
                else
                {
                    break;
                }
            }
            currValue=A[i];
            for(int j=i-1;j>=0;j--)
            {
                int diff = abs(currValue - A[j]);
                if(diff <=2)
                {
                    currValue = A[j];
                    affected++;
                }
                else
                {
                    break;
                }
            }
            if(affected > maxValue)
            {
                maxValue =affected;
            }
            if(affected < minValue)
            {
                minValue = affected;
            }
        }
        cout  << minValue <<" " << maxValue  <<endl;
    }


    return 0;
}
