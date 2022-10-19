#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l1,b1,h1,l2,b2,h2;
        cin>>l1>>b1>>h1>>l2>>b2>>h2;
        int pick=1;
        if(h2>h1)
        {
            pick=2;
        }
        int maxvol=0;
        int vol1=l1*b1*h1;
        int vol2=l2*b2*h2;
        if(vol1>=vol2)
        {
            maxvol=1;
        }
        else{
            maxvol=2;
        }
         if(pick==maxvol)
         {
             cout<<"1"<<endl;
         }
         else{
            cout<<"0"<<endl;
         }
    }

    return 0;
}
