#include<iostream>
#include <unistd.h>
#include<sstream>
#define ll long long

using namespace std;

bool isPalindrome(ll n)
{
    stringstream ss2;
    ss2<<n;
    string number;
    ss2>>number;

    int i=0;
    int j=number.length()-1;

    while(i<=j)
    {
        if(number[i]==number[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int number1,number2;
    cin >>number1>>number2;

    stringstream ss;
    ss<<number1;
    string first="";
    ss>>first;
    first+="000000";
    if(number1==0)
    {
        first="0000000";
    }

    stringstream ss1;
    ss1<<number2;
    string second="";
    ss1>>second;
    second+="235959";
    if(number2==0)
    {
        second="0235959";
    }

    ll n1=stoi(first);
    ll n2=stoi(second);

    ll count=0;
    for(ll i=n1;i<=n2;i++)
    {
        cout <<"hello "<<i<<" "<<count<<endl;
        //usleep(10000);
        ll temp=i;
        temp=temp/10;
        ll rem=temp%10;
        if(rem>=6)
        {
            continue;
        }

        temp=temp/100;
        rem=temp%10;

        if(rem>=6)
        {
            continue;
        }

        temp=temp/10;
        rem=temp%100;
        if(rem>=24)
        {
            continue;
        }


        if(isPalindrome(i)){

            count++;
        }

    }
    cout <<count<<endl;

    return 0;
}
