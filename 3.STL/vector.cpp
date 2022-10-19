#include<iostream>
#include<utility>
#include<set>
using namespace std;

int main()
{
    /*
    -------------------VECTOR----------------------
    vector <int> v(5);
    for(int i=0;i<v.size();i++)
    {
       v[i]=2*i;
    }
    vector <int>:: iterator it;
    for(it=v.begin();it<v.end();it++)
    {
        cout << *it <<" ";
    }*/

    /*---------------------PAIR-----------------------
    pair<int,char> p(1,'g');
    pair <int,char> p2;
    p2=make_pair(2,'l');
    cout <<p.first << " " << p.second<<endl;
    cout <<p2.first << " " <<p2.second<<endl;
    */
    //----------------------------SET--------------
    set <int> s;
    int ar[]={1,2,3,4,5,6,6,6};
    for(int i=0;i<8;i++)
    {
        s.insert(ar[i]);
    }
    set <int>::iterator it;
    for(it=s.begin();it!=s.end();it++)
    {
        cout << *it << " ";
    }
    if(s.find(2)==s.end())
    {
        cout << "element not found";
    }
    else{
        cout<< "element found";
    }
    return 0;
}
