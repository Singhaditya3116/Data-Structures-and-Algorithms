#include<bits/stdc++.h>
#include<vector>

using namespace std;
int main()
{
    char input[100];
    cin >>input;
    cout<<strlen(input);
    /*string str="abade";
    int size=str.size();
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(str[i]==str[j])
            {
                str[j]=0;
            }
        }
    }
    for(int i=0;i<size;i++)
    {
        if(str[i]!=0)
        {
            cout<<str[i];
        }
    }*/


    /*string words;
    vector<string> str;
    int a=4;
    while(a--)
    {
        cin >>words;
        str.push_back(words);
    }
    sort(str.begin(),str.end());

    string temp;
    temp=str[0];
    int count=1;
    int flag=0;
    int size=str.size();

    for(int i=1;i<size;i++)
    {
        if(temp==str[i])
        {
            count++;
            if((size-1)==i)
            {
                if(count>1)
                {
                cout <<temp<<" "<<count<<endl;
                flag=1;
                }
            }
        }
        else
        {
            if(count>1)
            {
             cout <<temp<<" "<<count<<endl;
                flag=1;
            }
            temp=str[i];
            count=1;
        }

    }
    if(flag==0)
    {
        cout<<"-1"<<endl;
    }*/
	return 0;
}
