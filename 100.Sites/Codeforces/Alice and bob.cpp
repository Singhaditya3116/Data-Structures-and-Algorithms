#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        string s;
        cin >> s;

        string move="alice";

        for(int i=0;i<s.length();i+=2)
        {
            if(i+1 == s.length())
            {
                break;
            }
            if(move == "alice") move="bob";
            else move = "alice";
        }

        if(move == "alice") cout <<"NET" <<endl;
        else cout <<"DA" <<endl;
    }
}
