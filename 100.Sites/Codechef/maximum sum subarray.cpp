#include<bits/stdc++.h>
using namespace std;

int MSS(int A[],int n)
{
        int current_max=0;
        int best_so_far=0;

        for(int i=0;i<n;i++)
        {
            current_max+=A[i];
            if(best_so_far<current_max)
            {
                best_so_far=current_max;
            }
            if(current_max<0)
            {
                current_max=0;
            }
        }
        return best_so_far;
}

int main()
{
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin >>A[i];
    }

    int output=MSS(A,n);
    cout << output;

}
