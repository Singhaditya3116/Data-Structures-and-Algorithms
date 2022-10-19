#include<bits/stdc++.h>
#include<string>

using namepsace std;

void removeX(string s)
{
    if(s[0]=='\0')
    {
        return;
    }

    if(s[0]!='x')
    {
        removeX(s+1);
    }
    else
    {
        int j=1;
        for(;s[j]!='\0';j++)
        {
            s[j-1]=s[j];
        }
        s[j-1]=s[j];
        removeX(s);
        return;
    }
}

int main()
{
    string s;
    cin >>s;
    removeX(s);
    cout <<s<<endl;




    return 0;
}
