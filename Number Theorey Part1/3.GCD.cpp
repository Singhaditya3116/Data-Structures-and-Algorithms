#include<bits/stdc++.h>

using namespace std;

int gcd(int firstno,int secondno)//BRUTE FORCE METHOD
{
    int gcd=1;//MINIMUM GCD CAN BE 1
    int number=min(firstno,secondno);//THE LOOP SHOULD RUN FOR MIN OF THE TWO NUMBER
    if(firstno == 0 || secondno == 0)//IF NO IS ZERO THEN GCD IS ANOTHER NUMBER
    {
        gcd = max(firstno,secondno);
    }

    for(int i=1;i<=number;i++)
    {
        if(firstno%i==0 && secondno%i==0)//IF BOTH NUMBER ARE DIVISIBLE BY I THEN UPDATE GCD
        {
            gcd=i;
        }
    }
    return gcd;
}


int main()
{
    int firstno,secondno;
    cin >> firstno >> secondno;

    cout<<gcd(firstno,secondno)<<endl;

    return 0;
}
