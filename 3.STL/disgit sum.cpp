#include<bits/stdc++.h>
#include<map>
using namespace std;
int main() {
    int n=5;
    int input[n]={2,1,-2,2,3};
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[input[i]]+=1;
    }
    map<int,int>::iterator it;

    for(int i=0;i<n;i++)
    {
        int search=-input[i];
        auto it=m.find(search);
        cout<<it->second;

    }

	/*int t;
    cin>>t;
    long long int remainder,sum=0;
    while(t--)
    {
        long long int val;
        cin>>val;
        while(val!=0)
        {
            remainder=val%10;
            sum+=remainder;
            val=val/10;
        }
        cout<<sum<<endl;


    }*/
}
