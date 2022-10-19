#include<bits/stdc++.h>
using namespace std;

/*
1
2 3
4 5 6
7 8 9 10
*/

int main()
{
    int  n;
    cout <<"Enter n "<<endl;
    cin >> n;

    int i=1,j=1;
    while(i<=n)
    {
        int count = 1;
        while(count <= i)
        {
            cout << j <<" ";
            count++;
            j++;
        }
        cout <<endl;
        i++;
    }


    return 0;
}
