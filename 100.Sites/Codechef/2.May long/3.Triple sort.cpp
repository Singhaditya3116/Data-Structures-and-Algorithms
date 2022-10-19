#include<bits/stdc++.h>
using namespace std;


int findIndex(int *arr,int currindex,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==currindex)
        {
            return i;
        }
    }
}
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;

        int arr[n+1];
        for(int i=1;i<=n;i++)
        {
            cin >>arr[i];
        }
        arr[0]=0;
        set< vector<int> > s;
        int count=0;

        bool possible=true;
        for(int i=n;i>=1;i--)
        {
            vector<int> v;
            if(arr[i]==i)
            {
                continue;
            }
            int currindex=i;
            int elementIndex=findIndex(arr,currindex,n);
            int minIndex=-1;
            int minvalue=arr[elementIndex];
            v.push_back(currindex);
            v.push_back(elementIndex);
            for(int j=elementIndex-1;j>=1;j--)
            {
                if(arr[j] < minvalue && arr[j]!=j)
                {
                    minvalue=arr[j];
                    minIndex=j;
                }
            }
           // cout << currindex << " " << elementIndex << " " << minIndex <<endl;
            if(minIndex == -1)
            {
                possible = false;
                break;
            }
            swap(arr[currindex],arr[elementIndex]);
            swap(arr[elementIndex],arr[minIndex]);
            v.push_back(minIndex);

            s.insert(v);
            count++;
        }
        if(!possible || count > k)
        {
            cout << "-1" <<endl;
            continue;
        }
        cout << count <<endl;
        set< vector <int> > :: iterator sit;
        vector<int> :: iterator vit;
        for(sit=s.begin();sit!=s.end();sit++)
        {
            vector<int> v = *sit;
            for(vit = v.begin();vit!=v.end();vit++)
            {
                cout << *vit << " ";
            }
            cout <<endl;
        }
    }

    return 0;
}
