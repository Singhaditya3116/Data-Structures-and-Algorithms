#include<bits/stdc++.h>
using namespace std;

/*
1
12
123
1234
12345
*/

int main()
{
    int n;
    cout <<"Upto which value of n you want to print ";
    cin >> n;
    int i = 1;

    while(i<=n)
    {
        int j = 1;
        while(j<=i)
        {
            cout << j;
            j++;
        }
        cout <<endl;
        i++;
    }5

    return 0;
}
