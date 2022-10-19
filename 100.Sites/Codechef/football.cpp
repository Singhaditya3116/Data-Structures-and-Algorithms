#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >>T;
    while(T--)
    {
        int N;
        cin>>N;
        int determine=1;
        while(N--)
        {
            int reply_type;
            long long int A,B;
            cin >> reply_type >>A >>B;
            if(reply_type==1)
            {
                cout << "YES"<<endl;
                determine=0;
            }
            else{
                if(A==B || determine==0)
                {
                    cout << "YES"<<endl;
                }
                else{
                cout << "NO"<<endl;
                }
                determine=1;
            }

        }
    }
    return 0;
}

