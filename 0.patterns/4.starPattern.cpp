#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout <<"Enter n ";
    cin >>n;

    int i = 1;
    int j = 1;
    while(i <= n)
    {
        int spaceCount = 1;
        while(spaceCount <= (n-i))
        {
            cout << " ";
            spaceCount++;
        }

        int starCount = 1;

        while(starCount <= j)
        {
            cout <<"*";
            starCount++;
        }
        j+=2;
        cout <<endl;

        i++;

    }

    return 0;
}
