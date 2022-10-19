#include<bits/stdc++.h>
#include<map>
using namespace std;


int main()
{

    long long int A[5]={250000,500000,750000,1000000,1250000,1500000};
    float amount[5]={0.05,0.1,0.15,0.20,0.25};
    int t;
    cin >> t;
    long long int diff;
    long long int value;
    while(t--)
    {

        long long int income,temp;
        cin >> income;
        temp=income;
        for(int i=0;i<5;i++)
        {
            if(income > A[i])
            {
                if(income > A[i+1])
                {
                    diff = A[i+1]-A[i];
                    value= diff*amount[i];
                    income-=value;
                }
                else
                {
                    diff=temp-A[i];
                    value = diff * amount[i];
                    income-=value;
                }
            }
            else
            {
                break;
            }

        }

        if(temp > 1500001)
        {
             diff = temp - 1500000;
             value= diff*0.3;
            income-=value;
        }

        cout <<income<<endl;
    }
}
