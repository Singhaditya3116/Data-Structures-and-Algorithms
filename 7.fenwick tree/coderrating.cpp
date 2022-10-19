#include <bits/stdc++.h>
using namespace std;


class rating
{
public:
  int x,y,index;
};

bool compare(rating r1,rating r2)
{
    if(r1.x==r2.x)
    {
        return r1.y<r2.y;
    }
    return r1.x<r2.x;
}

void update(int y,int* BIT)
{
    for(;y<=100000;y+=(y&(-y)))
    {
        BIT[y]++;
    }
}

int query(int y,int* BIT)
{
    int count=0;
    for(;y>0;y-=(y&(-y)))
    {
        count+=BIT[y];
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    rating* arr=new rating[n];

    for(int i=0;i<n;i++)
    {
         cin>>arr[i].x>>arr[i].y;
         arr[i].index=i;
    }

    sort(arr,arr+n,compare);


    int* BIT = new int[100001];
    int* ans=new int[n];

    for(int i=0;i<n;)
    {

        int endindex=i;
        while(endindex<n && arr[i].x==arr[endindex].x && arr[i].y==arr[endindex].y)
        {
            endindex++;
        }
        for(int j=i;j<endindex;j++)
        {
        ans[arr[j].index]=query(arr[j].y,BIT);
        }
        for(int j=i;j<endindex;j++)
        {
        update(arr[j].y,BIT);
        }
        i=endindex;
    }



    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<endl;
    }


    return 0;
}

