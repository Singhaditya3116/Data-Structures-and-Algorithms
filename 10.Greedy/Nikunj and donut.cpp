#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int donut[n];
    for(int i=0;i<n;i++)
    {
        cin >> donut[i];
    }
    sort(donut,donut+n,greater<int>());
    unsigned long long walk=donut[0];
    for(int i=1;i<n;i++)
    {
        walk+=(pow(2,i)*donut[i]);
    }
    cout <<walk<<endl;


    return 0;
}
