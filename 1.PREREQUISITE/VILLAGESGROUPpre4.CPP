#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int population[n];

    for(int i=0;i<n;i++)
    {
        cin >>population[i];
    }

    for(int i=0;i<(n/2);i++)
    {
        int combined=0;
        combined=population[i]+population[n-1-i];
        int groupsformed=0;
        groupsformed=combined/10;
        int withoutgroup=0;
        withoutgroup=combined-(groupsformed*10);
        cout <<groupsformed << " " << withoutgroup <<endl;
    }

	return 0;
}
