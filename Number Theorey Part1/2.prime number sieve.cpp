#include<bits/stdc++.h>
using namespace std;

vector<int>  computePrimeFactors(int n,vector<int> &primes)
{
    vector<int> primeFactor;

    int p = primes[0];
    int index=0;
    while(p*p <= n)
    {
        if(n%p == 0)
        {
            primeFactor.push_back(p);
            while(n%p == 0)
            {
                n=n/p;
            }
        }
        index++;
        p=primes[index];
    }

    if(n!=1)
    {
        primeFactor.push_back(n);
    }
    return primeFactor;
}

int main()
{
    int n;
    cin >>n;
    //How many prime Numbers are present between 1 to N.

    bool sieve[n+1];
    for(int i=0;i<=n;i++)
    {
        sieve[i]=true;
    }
    sieve[0]=false;
    sieve[1]=false;

    for(int i=2;i*i<=n;i++)
    {
        if(sieve[i]==true)
        {
            for(int j=(i*i);j<=n;j+=i)
            {
                sieve[j]=false;
            }
        }
    }

    int count=0;
    vector<int> primes;
    for(int i=2;i<=n;i++)
    {
        if(sieve[i])
        {
            primes.push_back(i);
            count++;
        }
    }
    cout<<count<<endl;
    /////////////////------------Computing Prime factors---------------
    cout <<"Prime Numbers are ";
    for(int i=0;i<primes.size();i++)
    {
        cout <<primes[i]<<" ";
    }
    cout <<endl<<"The Prime Factor of a Number is ";
    vector<int> primeFactor;
    primeFactor = computePrimeFactors(n,primes);
    for(int i=0;i<primeFactor.size();i++)
    {
        cout <<primeFactor[i]<<" ";
    }
    cout <<endl;

    return 0;
}
