#include<bits/stdc++.h>

using namespace std;

void update(int index,int value,int* BIT,int n)
{
    for(index=index;index<=n;index+=index&(-index))
    {
        BIT[index]+=value;
    }
}

int query(int ele,int* BIT)
{
        int sum=0;
    for(ele=ele;ele>0;ele-=ele&(-ele))
    {
        sum+=BIT[ele];
    }
    return sum;
}



int main()
{
    int n;
    cin>>n;

    int* arr=new int [n+1]();
    int* BIT=new int[n+1]();

    for(int i=1;i<n+1;i++)
    {
        cin>>arr[i];
        update(i,arr[i],BIT,n);
    }

    cout<<"sum of first 5 element"<<query(5,BIT)<<endl;


}
