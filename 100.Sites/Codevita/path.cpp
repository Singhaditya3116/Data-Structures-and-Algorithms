#include<iostream>
#include<vector>
#define ll long long

using namespace std;

void fillThis(vector<ll> &v,ll n1)
{
    /*v.push_back(n1);
    while(n1!=1)
    {
        if(n1%2==0)
        {
            n1=n1/2;
            v.push_back(n1);
        }
        else if(n1%3 ==0)
        {
            n1=n1/3;
            v.push_back(n1);
        }
        else if(n1%5 == 0)
        {
            n1=n1/5;
            v.push_back(n1);
        }else{
            n1=n1/n1;
            v.push_back(n1);

        }
    }*/

    v.push_back(n1);

    ll i=2;
    while(i*i<=n1)
    {
        if(n1%i==0)
        {
            v.push_back(n1/i);
            n1=n1/i;
            i=1;
        }
        i++;
    }
    v.push_back(1);
}

int binarySearch(vector<ll> &v,ll value)
{
    ll low=0;
    ll high=v.size()-1;
    ll index=-1;

    while(low<=high)
    {
        int mid=(low+high)/2;
        if(value>=v[mid])
        {
            if(v[mid]==value)
            {
                return mid;
            }
            else
            {
                high=mid-1;
            }
        }
        else
        {
            low=mid+1;
        }
    }
    return index;
}

int main()
{
    ll n1,n2;
    cin >>n1 >>n2;
    vector<ll> v1;
    vector<ll> v2;

    fillThis(v1,n1);
    fillThis(v2,n2);

    ll index2=0;
    ll index1=0;
    for(std::size_t i=0;i<v1.size();i++)
    {
        index2=binarySearch(v2,v1[i]);
        index1=i;
        if(index2 == -1)
        {
            continue;
        }else
        {
            break;
        }
    }

    int edge=0;
    for(ll i=index1;i>=0;i--)
    {
        if(v1[i]==n1){
            break;
        }else{
            edge++;
        }
    }

    for(ll i=index2;i>=0;i--)
    {
        if(v2[i]==n2)
        {
            break;
        }
        else{
            edge++;
        }
    }

    cout <<edge;


    return 0;
}
