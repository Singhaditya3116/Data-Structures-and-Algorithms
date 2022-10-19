#include<bits/stdc++.h>
using namespace std;

struct studentmarks{
    int seq;
    string name;
    int total;
};

bool sortinrev(const studentmarks a,  const studentmarks b)
{
       if (a.total!=b.total) {
           return a.total>b.total;
       }
    return a.seq<b.seq;

}

int main()
{
    int n,m1,m2,m3;
    string name1;
    cin >>n;



    studentmarks s1[n];

    for(int i=0;i<n;i++)
    {
        s1[i].seq=i;
        cin >>name1;
        s1[i].name=name1;
        cin>>m1>>m2>>m3;
        s1[i].total=m1+m2+m3;

    }

    sort(s1, s1+n, sortinrev);
    for(int i=0;i<n;i++)
    {
        cout<<s1[i].seq+1<<" "<<s1[i].name<<endl;

    }



	return 0;
}
