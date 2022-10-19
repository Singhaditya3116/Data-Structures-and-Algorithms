#include <iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main() {

    int t;
    cin >>t;

    while(t--)
    {

    	priority_queue<int , vector<int> , greater<int> > pq;
    	int n,k;
    	cin >>n;
    	int input[n],temp[n];
    	for(int i=0;i<n;i++)
    	{
    	    cin >>input[i];
    	    temp[i]=input[i];
    	}
    	cin>>k;
    	sort(temp,temp+n);

    	for(int i=0;i<=k;i++)
    	{
    	    pq.push(input[i]);
    	}
    	int index=0;
    	for(int i=k+1;i<n;i++)
    	{
    	    input[index]=pq.top();
    	    pq.pop();
    	    pq.push(input[i]);
    	    index++;
    	}

    	while(pq.empty() == false)
    	{
    	    input[index]=pq.top();
    	    pq.pop();
    	    index++;
    	}
        bool isKsorted=true;
    	for(int i=0;i<n;i++)
    	{
    	    cout <<"hello "<<i<<" "<<temp[i]<<" "<<input[i]<<endl;
    	    /*if(input[i] == temp[i])
    	    {
    	        continue;
    	    }
    	    else
    	    {
    	        isKsorted=false;
    	        break;
    	    }
    	    */
    	}

    	if(isKsorted)
    	{
    	    cout <<"Yes"<<endl;
    	}
    	else
    	{
    	    cout <<"No"<<endl;
    	}

    }
	return 0;
}
