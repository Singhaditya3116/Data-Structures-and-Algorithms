#include<bits/stdc++.h>
using namespace std;


int subs(string input,string *output)
{
    if(input[0]=='\0')
    {
        output[0]="";
        return 1;
    }

    int smalloutput = subs(input.substr(1),output);
    for(int i=0;i<smalloutput;i++)
    {
        output[i+smalloutput]=input[0]+output[i];
    }
    return smalloutput*2;
}



int main()
{
    string input;
    cin >> input;

    int size=pow(2,input.size());

    string *output = new string[size];

    int subsize = subs(input,output);

    for(int i=0;i<subsize;i++)
    {
        cout << output[i] <<endl;
    }
    return 0;
}
