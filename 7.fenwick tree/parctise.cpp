#include <bits/stdc++.h>
using namespace std;


class rating
{
public:
  int x,y;
};

bool compare(rating r1,rating r2)
{
    if(r1.x==r2.x)
    {
        r1.y<r2.y;
    }
    return r1.x<r2.x;
}

void update(int y,int* BIT)
{
    for(;y<=100001;y+=(y&(-y)))
    {
        BIT[y]++;
    }
}

int query(int y,int* BIT)
{
    cout<<"world";
    int counts=0;
    for(;y>=0;y-=(y&(-y)))
    {
        counts+=BIT[y];
    }
    cout<<counts;
    return counts;
}
int main()
{
    int n;
    cin>>n;
    rating* arr=new rating[n+1];

    for(int i=1;i<=n;i++)
    {
         cin>>arr[i].x>>arr[i].y;
    }

    sort(arr+1,arr+n+1,compare);

    int* BIT = new int[100001]();
    int* ans=new int[n];

    for(int i=1;i<=n;i++)
    {

        ans[i]=query(arr[i].y,BIT);
        cout<<ans[i];


        update(arr[i].y,BIT);
    }

    for(int i=0;i<=n;i++)
    {
        cout<<ans[i]<<endl;
    }


    return 0;
}


