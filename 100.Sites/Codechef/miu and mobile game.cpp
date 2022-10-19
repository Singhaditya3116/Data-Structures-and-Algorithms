#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector<int> score;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            score.push_back(temp);
        }
        int bestmin=INT_MAX;
        while(q--)
        {
            int miuscore;
            cin>>miuscore;

            score.push_back(miuscore);

            sort(score.begin(),score.end(),greater<int>());
            int count=0;

            vector<int>::iterator low1;
            low1=lower_bound(score.begin(),score.end(),miuscore);
            count=low1-score.begin();
            count++;
            cout<<"count"<<count<<endl;
            /*int count=0;
            for(int i=0;i<=n;i++)
            {
                count++;
                if(miuscore==score[i])
                {

                    break;
                }
            }*/
            if(count<bestmin)
            {
                bestmin=count;
            }
            cout<<bestmin<<endl;
            score.erase(remove(score.begin(),score.end(),miuscore));
        }
    }

    return 0;
}


