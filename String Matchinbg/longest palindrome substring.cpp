#include<bits/stdc++.h>

using namespace std;
int main()
{
    string s;
    cin >>s;
    int size=s.length();
    int left=0,right=0;
    int maxsublength=0;
    for(int i=0;i<size;i++)
    {
        int substringlength=0;
        if(s[i]==s[i+1])
        {
            left=i-1;
            right=i+2;
            substringlength+=2;
            while(left>=0 && right<size)
            {
                if(s[left]==s[right])
                {
                    substringlength+=2;
                    left--;
                    right++;
                }
                else
                {
                    break;
                }
            }
            maxsublength=max(maxsublength,substringlength);
        }
        else
        {
            left=i-1;
            right=i+1;
            substringlength+=1;
            while(left>=0 && right<size)
            {
                if(s[left]==s[right])
                {
                    substringlength+=2;
                    left--;
                    right++;
                }
                else
                {
                    break;
                }
            }
            maxsublength=max(maxsublength,substringlength);
        }
    }

    cout<<maxsublength<<endl;



    return 0;
}
