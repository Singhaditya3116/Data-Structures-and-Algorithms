#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> v1(n);
    for(int i=0;i<n;i++)
    {
        cin >>v1[i];
    }

    vector<int> v2(m);
    for(int i=0;i<m;i++)
    {
        cin >>v2[i];
    }
    int i=0,j=0,count=0;
    while(i!=v2.back())
    {
        count+=1;
        sort(v1.begin(),v1.end(),greater<int> ());
        int temp=v1[0];
        if(count==v2[j])
        {
            cout <<temp <<endl;
            j++;
        }
        v1.erase(v1.begin());
        temp=ceil(temp/2);
        if(temp>0)
        {
            v1.push_back(temp);
        }
        i++;

    }

    return 0;
}

