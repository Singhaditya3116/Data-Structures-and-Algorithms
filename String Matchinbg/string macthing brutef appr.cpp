#include<iostream>

using namespace std;

bool bruteforceapproach(string s,string pattern)
{
    for(int i=0;i<s.length()-pattern.length()+1;i++)
    {
        bool isfound=true;
        for(int j=0;j<pattern.size();i++)
        {
            if(pattern[j]!=s[i+j])//if at that particlular index not matches break and serach for another index of string
            {
                isfound=false;
                break;
            }
            if(isfound==true)//if all matches then return trye;
            {
                return true;
            }
        }
    }

    return false;//if  the whole length of the string is  traversed and string not matched with pattern then return false "NOT FOUND"
}

void suffix_w_is_prefix(string s,int *stringarr,int arrsize)
{
    int j=0;
    stringarr[j]=0;
    int i=j+1;

    while(i<arrsize)
    {
        if(s[j]==s[i])
        {
            stringarr[i]=j+1;
            i++;
            j++;
        }
        else
        {
            if(j==0)
            {
                stringarr[i]=0;
                i++;
            }
            else
            {
            j=stringarr[j-1];
            }
        }
    }
}




int main()
{
    string s;
    string pattern;
    cin >>s >> pattern;

    //cout<<bruteforceapproach(s,pattern)<<endl;

    int arrsize=pattern.length();
    int stringarr[arrsize];

    suffix_w_is_prefix(pattern,stringarr,arrsize);


    int j=0,i=0;
    while(i<s.length())//KMP APPROACH
    {
        while(j<arrsize)
        {
            if(s[i]==pattern[j])
            {
                i++;
                j++;
            }
            else
            {
                if(i>=s.length())
                {
                    return false;
                }
                if(j==0)
                {
                    i++;
                }
                else
                {
                j=stringarr[j-1];
                }
            }
        }
        if(j>=arrsize)
        {
            return true;
        }

    }
    return false;

    for(int i=0;i<arrsize;i++)
    {
        cout<<stringarr[i]<<" ";
    }



}
