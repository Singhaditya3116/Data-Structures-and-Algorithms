#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int divcount,primecount;
        cin >> divcount >> primecount;

        long long number=1;
        int  i=2;
        while(primecount!=0)
        {
            int notprime=0;
            for(int j=2;j<i;j++)
            {
                if(i%j == 0)
                {
                    notprime=1;
                    break;
                }
            }
            if(notprime == 0)
            {
                cout << "not" <<i <<endl;
                number*=i;
                primecount--;
            }
            i++;
        }

        int divisors=0;
        for(long long int i=1;i<=number;i++)
        {
            if(number%i == 0)
            {
                divisors++;
            }
        }

        if(divisors == divcount)
        {
            cout << "1" <<endl;
        }
        else
        {
            cout << "0" <<endl;
        }

    }

    return 0;
}
