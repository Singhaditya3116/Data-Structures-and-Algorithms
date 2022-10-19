#include<iostream>

using namespace std;
bool SubsetSum(int set[], int n, int sum)
{
   if (sum == 0)
     return true;
   if (n == 0 && sum != 0)
     return false;

   if (set[n-1] > sum)
     return SubsetSum(set, n-1, sum);


   return SubsetSum(set, n-1, sum) ||
                        SubsetSum(set, n-1, sum-set[n-1]);
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int N,X,L;
        cin >> N >> X >> L;
        int A[N];
        for(int i=1;i<N;i++ )
        {
            if(i == X)
            {
                continue;
            }
            A[i]=i;
        }
        if (SubsetSum(A, N, L) == true)
        {
            cout << "yes"<<endl;
        }
        else
        {
            cout <<"no"<<endl;
        }
    }

}
