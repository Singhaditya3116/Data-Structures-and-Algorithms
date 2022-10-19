#include<bits/stdc++.h>
#include "ourmap.h"
using namespace std;

int main()
{
    ourmap<int> m;


    for(int  i=0;i<10;i++)
    {
        string s="abc";
        s+=to_string(i);
        m.insert(s,i+1);
        cout <<m.getLoadFactor()<<endl;
    }


    cout <<m.getSize()<<endl;
    m.Delete("abc2");
    m.Delete("abc9");
    cout <<m.getSize()<<endl;

    for(int i=0;i<10;i++)
    {
        string s="abc";
        s+=to_string(i);

        cout <<s<<" : "<<m.getValue(s)<<endl;
    }

    cout <<m.getSize()<<endl;


    return 0;
}
