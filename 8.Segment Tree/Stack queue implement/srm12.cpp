#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {

        int N;
        int M;
        cin >> N >> M;
        map<int,int> m;
        m[N]+=1;
        map<int,int> :: iterator it;
        while(M!=0)
        {
            it=m.begin();

            while(it!=m.end())
            {
                int temp=(it->first);
                m.erase(temp);
                if(temp%2 == 0)
                {
                    int n1=temp*2;
                    m[n1]+=1;
                    n1=n1+1;
                    m[n1]+=1;
                }
                else
                {
                    int n2 = temp*2;
                    m[n2]+=1;
                }
                it++;
            }
            M--;
        }
      long long int count=0;
        for(it=m.begin();it!=m.end();it++)
        {
            //cout << "djhfhj" <<it->first<<endl;
            int temp = (it->first);
            if((temp%2)!=0)
            {
                count +=1;
            }
            count=count%1000000007;
        }
        cout << count <<endl;
    }


}
