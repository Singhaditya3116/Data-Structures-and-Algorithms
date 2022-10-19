#include<bits/stdc++.h>
#include<set>
using namespace std;

bool isCoprime(int n1,int n2)
{
    for(int i=2;i<=min(n1,n2);i++)
    {
        if(n1%i==0 && n2%i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector< vector<int> > finalans;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            arr[i]=i+1;
        }

        int count=0;
        while(arr.size()!=0)
        {
            bool visited[arr.size()];
            for(int i=0;i<arr.size();i++)
            {
                visited[i]=false;
            }
            vector<int> ans;
            vector<int>temp;
            ans.push_back(arr[0]);
            visited[0]=true;
            for(int i=1;i<arr.size();i++)
            {
                int flag=0;
                for(int j=i-1;j>=0;j--)
                {
                    if(!visited[j])
                    {
                        continue;
                    }

                    if(isCoprime(arr[i],arr[j]) == false)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    visited[i]=true;
                    ans.push_back(arr[i]);
                }
                else
                {
                    temp.push_back(arr[i]);
                }
            }
            finalans.push_back(ans);
            arr.clear();
            for(int i=0;i<temp.size();i++)
            {
                arr.push_back(temp[i]);
            }
        }
        cout << finalans.size() <<endl;
        for(int i=0;i<finalans.size();i++)
        {
            cout << finalans[i].size() << " ";
            for(int j=0;j<finalans[i].size();j++)
            {
                cout << finalans[i][j] << " ";
            }
            cout <<endl;
        }

    }

    return 0;
}
