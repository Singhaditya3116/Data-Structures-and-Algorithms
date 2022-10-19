#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >>T;
    while(T--)
    {
        int N;
        int M,i;
        cin >>N>>M;
        int arr[M];
        for(i=0;i<M;i++)
        {
            cin>>arr[i];
        }
        int sum;
        sum=(N+1)*(N);
        sum=sum/2;
        int tempsum=0;
        int count=1;
        int flag=1;
        for(i=0;i<M;i++)
        {
            tempsum+=arr[i];
            if(count%N==0)
            {
                if(tempsum%sum==0)
                {
                    flag=1;
                }
                else{
                    flag=0;
                    break;
                }
            }
            count++;
        }

        if(flag==1)
        {
            cout <<"YES"<<endl;
        }
        else{
            cout <<"NO"<<endl;
        }
    }

    return 0;
}
