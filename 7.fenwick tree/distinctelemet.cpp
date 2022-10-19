#include <bits/stdc++.h>
using namespace std;

class queryno{
    public:
    int si;
    int end;
    int index;
};

bool compare(queryno q1,queryno q2)
{
    return q1.end<q2.end;
}

void update(int index,int value,int n,int* bit)
{
    for(;index<=n;index+=(index&(-index)))
    {
        bit[index]+=value;
    }
}
int query(int index,int n,int* bit)
{
    int count=0;
    for(;index>0;index-=(index&(-index)))
    {
        count+=bit[index];
    }
    return count;
}

int main()
{

    int n;
    cin>>n;
    int inputarr[n+1];
    for(int i=1;i<=n;i++)
    {
        cin >> inputarr[i];
    }
    int d;//no. of queries
    cin>>d;
    queryno* queryarr=new queryno[d];
    for(int i=0;i<d;i++)
    {
        cin>>queryarr[i].si>>queryarr[i].end;
        queryarr[i].index=i;
    }
    sort(queryarr,queryarr+d,compare);

    int* bit = new int[n+1];
    int* ans=new int[d];
    int total=0;
    int k=0;

    int* last = new int[1000001];
    for(int i=0;i<=100000;i++)
    {
        last[i] = -1;
    }


    for(int i=1;i<=n;i++)
    {
        if(last[inputarr[i]] != -1)
        {
             update(last[inputarr[i]],-1,n,bit);
        }else{
            total++;
        }
        update(i,1,n,bit);
        last[inputarr[i]]=i;
        while(k<d && queryarr[k].end==i)
        {
            ans[queryarr[k].index] = total-query(queryarr[k].si-1,n,bit);
			k++;
        }

    }

    for(int i=0;i<d;i++){
		cout << ans[i] <<endl;
	}


    return 0;
}
