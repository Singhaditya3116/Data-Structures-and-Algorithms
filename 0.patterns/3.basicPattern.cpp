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
    cout <<"Enter n ";
    int n;
    cin >>n;

    int i = 1;
    int val = 1;
    while(i <= n)
    {
        int count = n - i;
        int j = 1;
        while( j <= count)
        {
            cout << " ";
            j++;
        }

        int count1 = 1;

        while(count1 <= i)
        {
            cout <<val;
            val++;
            count1++;
        }

        cout <<endl;
        i++;
    }

    return 0;
}
