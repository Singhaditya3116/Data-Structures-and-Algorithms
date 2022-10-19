 	#include<map>
#include<algorithm>
	void PairSum(int *input, int n) {

	map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[input[i]]+=1;
    }
    map<int,int>:: iterator it;
    map<int,int>:: iterator it1;



    int count,loop;
    for(it=m.begin();it!=m.end();it++)
    {
        int temp=it->first;
        if(temp<0)
        {
            loop=it->second;
            while(loop!=0)
            {
            temp=-temp;
            it1=m.find(temp);
            if(it1!=m.end())
            {
                count=it1->second;
            }
            while(count!=0)
            {
                cout<<-temp<<" "<<temp<<endl;
                count--;
            }
                loop--;
            }
        }

    }


}

