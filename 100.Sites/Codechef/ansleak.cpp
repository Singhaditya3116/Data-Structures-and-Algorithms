#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        int arr[n][k];
        bool visited[m+1];
        for(int i=0;i<=m;i++)
        {
            visited[i]=false;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                cin >> arr[i][j];
            }
        }
       int ans[n][k];
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<n;j++)
            {
                int value=arr[j][i];
                visited[value]=false;
                for(int a=1;a<=m;a++)
                {
                    if(!visited[a])
                    {
                        ans[j][i]=a;
                        break;
                    }
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            map<int,int> m1;
            for(int j=0;j<k;j++)
            {
                m1[ans[i][j]]+=1;
            }
            map<int,int> :: iterator it;
            int key=1;
            int value=0;
            for(it = m1.begin();it!=m1.end();it++)
            {
                if(value < it->second)
                {
                    value=it->second;
                    key=it->first;
                }
            }
            cout << key << " ";
        }
        cout <<endl;
    }

    return 0;
}
