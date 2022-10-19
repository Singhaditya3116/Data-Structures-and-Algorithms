#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main()
{
    int N1,N2,N3;
    cin >> N1 >> N2 >> N3;
    int size=N1+N2+N3;
    vector<int> v;
    int finalarr[size];


    for(int i=0;i<size;i++)
    {
        cin >>finalarr[i];
    }
    sort(finalarr,finalarr+size);
    int i;
    for(i=0;i<size;i++)
    {
        int temp=finalarr[i];
        int count=1;
        int j=i+1;
        for(j;temp==finalarr[j];j++)
        {
            count++;
        }
        if(count>=2)
        {
            v.push_back(temp);
        }
        i=j-1;

    }

    cout <<v.size()<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout <<v[i] <<endl;
    }





    return 0;
}
