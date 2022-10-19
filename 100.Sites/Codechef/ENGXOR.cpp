#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        int A[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&A[i]);
        }
        int loopcount=0;
        int finalpset=0;
        int evencount=0;
        while(q--)
        {
            int p;
            scanf("%d",&p);
            int xorr[n];
            int temps=p;
            int pset=0;
            while(temps>0)
            {
                temps=temps&(temps-1);
                pset++;
            }

            if(loopcount==0)
            {
                int extra=3;
                int tempextra=extra;
                int extraset=0;
                while(tempextra >0)
                {
                    tempextra=tempextra&(tempextra-1);
                    extraset++;
                }
                loopcount++;
                for(int i=0;i<n;i++)
                {
                    xorr[i]=extra^A[i];
                    int value=xorr[i];
                    int count=0;
                    while(value > 0)
                    {
                        count ++;
                        value=value&(value-1);
                    }
                    if(count %2 == 0)
                    {
                        evencount++;
                    }
                    finalpset=extraset;
                }
            }

            if(pset%finalpset==0)
            {
                printf("%d %d",evencount,n-evencount);
                printf("\n");
            }
            else
            {
                printf("%d %d",n-evencount,evencount);
                printf("\n");
            }


        }
    }
    return 0;
}
