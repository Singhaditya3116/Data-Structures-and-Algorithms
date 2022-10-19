#include<bits/stdc++.h>

using namespace std;

class bag{
public:
    int weight=0;
    int value=0;
    double ratio=0; //value/weight ratio
};

bool compare(bag a,bag b)
{
    return a.ratio > b.ratio;
}


int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n,maxweight;
        cin >> n >>maxweight;

        bag arr[n];
        for(int i=0;i<n;i++)
        {
            int val,weig;
            cin >> val >>weig;
            arr[i].value=val;
            arr[i].weight=weig;
            arr[i].ratio=(arr[i].value/arr[i].weight);
        }

        sort(arr,arr+n,compare);
        int currweight=0;
        double currValue=0;
        for(int i=0;i<n;i++)
        {
            if((currweight + arr[i].weight)<=maxweight)
            {
                currweight+=arr[i].weight;
                currValue+=arr[i].value;
            }
            else
            {
                int diff = maxweight-currweight;
                double val = (double)diff/(double)arr[i].weight;
                val= val * (double)arr[i].value;
                currValue+=val;
                break;
            }
        }

        cout << currValue <<endl;
    }

}
