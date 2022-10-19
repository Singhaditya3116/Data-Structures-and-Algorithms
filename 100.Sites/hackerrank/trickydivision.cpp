#include<bits/stdc++.h>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int A,B,C,D;
    int  add,sub;
    int  div;

    while(T--)
    {
        cin >> A >> B >> C >> D;
        add = (A+B);
        sub=(C-D);
        div=-1;
        if(sub!=0)
        {
        div=add/sub;
        }
        if(sub==0 || div <0)
        {
            cout << "-1" << endl;
        }
        if(div>=0)
        {
            cout << div << endl;
        }

    }

    return 0;

}
