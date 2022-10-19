#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    while(N--)
    {
        long long int K,L,R;
        cin >> K >> L >> R;
        int desire_number=0;
        for(long long int i=L;i<=R;i++)
        {
            long long int num=i;
            int one_count=0;
            while(num!=0)
            {
                int rem=num%2;
                if(rem==1)
                {
                    one_count++;
                }
                num = num/2;
            }
            if(one_count==K)
            {
                desire_number++;
            }
        }
        cout << desire_number <<endl;
    }

    return 0;
}
