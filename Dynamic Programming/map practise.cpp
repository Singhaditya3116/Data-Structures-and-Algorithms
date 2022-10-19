
#include<bits/stdc++.h>
#include<map>
using namespace std;

int main()
{

    string str="Bcr$gw)TcE5S@DHTFw76";
    map <char,int> m;
    map <char,int> :: iterator it;

    for(int i=0;i<str.size();i++)
    {
        m[str[i]]=m[str[i]]+1;
    }

    string output="";
    for(int i=0;i<str.size();i++)
    {
        if(m.find(str[i])!=m.end())
        {
            output+=str[i];

            m.erase(str[i]);
        }
    }
    cout<<"output"<<output<<endl;
    int i=0;
    for( i=0;i<output.size();i++)
    {
        str[i]=output[i];
    }
    for(i;i<str.size();i++)
    {
    str[i]='\0';
    }

    cout <<"str"<<str<<endl;
}
