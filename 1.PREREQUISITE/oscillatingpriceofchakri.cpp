#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int price[N];
    for(int i=0;i<N;i++)
    {
        cin >> price[i];
    }
    int maxprofit=0;
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            int temp=0;
            temp=price[j]-price[i];
            if(temp>maxprofit)
            {
                maxprofit=temp;
            }
        }
    }
    cout << maxprofit ;
    return 0;
}
