#include<bits/stdc++.h>
using namespace std;

int sum(int *a,int size)
{
    int sum=0;

    for(int i=0;i<size;i++)
    {
        sum = sum + a[i];
    }

    return sum;
}

int main()
{

    int a[10];

    cout <<sizeof(a)<<endl;
    cout << sum(a,10) <<endl;


    return 0;
}
