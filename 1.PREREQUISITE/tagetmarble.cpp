#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,target_number,i;
    cin >> N >> target_number;
    int A[N];

    for(i=0;i<N;i++)
    {
        cin >> A[i];
    }
    bool breakingouterloop =false;
    for(i=0;i<N;i++)
    {
        int sum=0;
        for(int j=0;j<N;j++)
        {
            sum+=A[j];
            if(sum==target_number)
            {
                breakingouterloop =true;
                cout << "true" << endl;
                int index=i;
                for(int k=index;k<=j;k++)
                {
                    cout << A[k] << " " << endl;
                }
                break;
            }
            if(sum>target_number)
            {
                break;
            }
        }
        if(breakingouterloop)
        {
            break;
        }
        if(i==4)
        {
            cout << false;
        }
    }

	return 0;
}
