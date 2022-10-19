#include<iostream>
#include<algorithm>

using namespace std;

long long int maxsum(int *A,int *B,int size)
{
    long long int cum=0;
    sort(A,A+size);
    sort(B,B+size);

    for(int i=0;i<size;i++)
    {
        cum +=min(A[i],B[i]);
    }
    return cum;
}


int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n;
        cin >> n;
        int A[n];
        int B[n];

        for(int i=0;i<n;i++)
        {
            cin >>A[i];
        }
        for(int i=0;i<n;i++)
        {
            cin >>B[i];
        }

        cout << maxsum(A,B,n) << endl;
    }
}
