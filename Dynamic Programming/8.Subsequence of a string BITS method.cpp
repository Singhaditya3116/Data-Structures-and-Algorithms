#include<bits/stdc++.h>
using namespace std;

//BIT method
int findSubseq(string s, vector<string> &output)
{
    int size = pow(2,s.length());

    for(int i=0;i<size;i++)
    {
        int currNum = i;
        string ans="";
        for(int k=s.length()-1;k>=0;k--)
        {
            int bit = (currNum >> k)&1;
            if(bit == 1)
            {
                ans=ans+s[s.length() - k-1];
            }
        }
        output.push_back(ans);
    }

    return size;
}

// iterative --finding for smaller one then keep on computing.
int findSubseq2(string s,vector<string> &output)
{
    output.push_back("");
    for(int i=0;i<s.length();i++)
    {
        int currSize = output.size();
        for(int j=0;j<currSize;j++)
        {
            output.push_back(output[j]+s[i]);
        }
    }
    return output.size();
}


int main()
{
    string s;
    cout <<"Enter the first string :";
    cin >> s;
    vector<string> output;
    int size = findSubseq(s,output);

    vector<string> output1;
    string s1;
    cout <<"Enter the second string :";
    cin >> s1;

    int size1 = findSubseq2(s1,output1);
    cout <<"The subseq are :"<<endl;

    for(int i=0;i<size;i++)
    {
        cout <<output[i]<<endl;
    }

    for(int i=0;i<size1;i++)
    {
        cout <<output1[i]<<endl;
    }

    int lcs = 0;
    for(int i=0;i<size;i++)
    {
        string first = output[i];
        for(int j=0;j<size1;j++)
        {
            if(first == output1[j])
            {
                int len = first.length();
                lcs = max(lcs,len);
            }
        }
    }
    cout <<lcs<<endl;

}
