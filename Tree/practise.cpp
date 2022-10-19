#include<iostream>
#include<vector>
#include<sstream>
using namespace std;


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        int flag=0;
        cin >> s;
        vector<string> vstr;
        string temp="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '-')
            {
                vstr.push_back(temp);
                temp="";
                continue;
            }
            temp+=s[i];
        }
        vstr.push_back(temp);
        for(int i=0;i<vstr.size();i++)
        {
            string s1=vstr[i];
            stringstream ss(s1);
            long long int n;
            ss >> std::hex >> n;
            //cout <<"n "<< n <<" ";
            long long int factor=0;
            for(long long int i=1;i*i<=n;i++)
            {
                if(n % i == 0)
                {
                    factor+=2;
                }
            }
           // cout << "f " <<factor;
            long long int count=0;
            for(long long int i=1;i*i<=factor;i++)
            {
                if(factor%i == 0)
                {
                    count+=2;
                }
            }
            if(count >2)
            {
                flag=1;
                break;
            }
        }
        if(flag == 1)
        {
            cout << "NO" <<endl;
        }
        else
        {
            cout << "YES" <<endl;
        }
    }
}
