#include<bits/stdc++.h>

using namespace std;
#define m 200

int computeExponentiation(int a ,int b)
{
    int ans=1;
    int number = a;
    for(int i=0;i<32;i++)
    {
        int bit = (b >> i)&1;
        //cout <<bit<<" ";
        if(bit == 1)
        {
            ans = ans * number;
            ans = ans%m;
        }

        number*=number;
        number=number%m;
    }
    return ans;
}


int main()
{
    //Compute a to the power b ,a^b
    int a,b;
    cin >>a >> b;
    cout << computeExponentiation(a,b)<<endl;

    return 0;
}
