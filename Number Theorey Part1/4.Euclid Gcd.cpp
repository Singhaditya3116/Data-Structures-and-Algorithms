#include<bits/stdc++.h>

using namespace std;

int euclidGcd(int firstno,int secondno)//BRUTE FORCE METHOD
{
    if(first no == 0 || secondno==0)
    {
        return max(firstno,secondno);
    }
    int output= euclidGcd(secondno,firstno%secondno);
    return output;
}

int lcm(int firstno,int secondno) //lcm of a number
{
    return (firstno*secondno)/euclidGcd(firstno,secondno); //GCD * LCM = a*b;
}


int main()
{
    int firstno,secondno;
    cin >> firstno >> secondno;

    cout<<euclidGcd(firstno,secondno)<<endl;
    cout <<lcm(firstno,secondno)<<endl;

    return 0;
}
