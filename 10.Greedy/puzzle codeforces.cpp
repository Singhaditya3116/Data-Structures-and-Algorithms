#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
    int n,m;
    cin >> n>>m;
    int puzzle[m];
    for(int i=0;i<m;i++)
    {
    cin >>puzzle[i];
    }

    sort(puzzle,puzzle+m);
    int overallSmall=INT_MAX;
    for(int i=0;i<=m-n;i++)
    {
        int small = puzzle[i];
        int large = puzzle[i+(n-1)];
        int diff=large-small;
        overallSmall=min(overallSmall,diff);
    }


    cout <<overallSmall <<endl;

    return 0;
}
