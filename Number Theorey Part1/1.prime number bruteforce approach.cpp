#include<bits/stdc++.h>

using namespace std;

bool checkprime(int n)
{
    int count=0;
    for(int j=1;j*j<=n;j++)
    {
        if(n%j == 0)
        {
            if(j*j == n)
            {
                count+=1;
            }
            else
            {
                count+=2;
            }
        }
    }

    if(count== 2)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int checkPrimeBasicApproach(int n)
{
    int countDivisor=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i == 0)
        {
            countDivisor++;
        }
    }

    if(countDivisor == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    int n;
    cin >>n;

    int primecount=0;
    //How many primes are present between 1 to N.
    for(int i=1;i<=n;i++)
    {
        if(checkprime(i))
        {
            primecount+=1;
        }

    }
    cout<<"The total Number of prime number between 1 to "<<n<<" is "<<primecount<<endl;

}
