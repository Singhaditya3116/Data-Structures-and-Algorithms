#include<bits/stdc++.h>
#include<vector>
#include<math.h>
using namespace std;

bool isValid(long long int number)
{
    long long int root = sqrt(number);
    if(root*root == number) return true;

    int incremental = root+1;
    long long int remaining = pow(incremental,2) - number;

    root = sqrt(remaining);
    if(root*root == remaining) return true;

    return false;
}


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
            int n;
            cin >> n;
            int A[n];
            for(int i=0;i<n;i++)
            {
                cin >> A[i];
            }
            vector< vector<int> > v;
            for(int i=0;i<n;i++)
            {
                vector<int> temp;
                for(int j=i;j<n;j++)
                {
                    temp.push_back(A[j]);
                    v.push_back(temp);
                }
                temp.clear();
            }
            int count =0;
            for(int i=0;i<v.size();i++)
            {
                long long int product=1;
                for(int j=0;j<v[i].size();j++)
                {

                    product *=v[i][j];
                }
                //cout << "hello" <<product <<endl;
                bool ans = isValid(product);
                if(ans) count++;
            }
            v.clear();
            cout <<count <<endl;
    }


    return 0;
}
