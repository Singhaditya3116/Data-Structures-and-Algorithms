#include<set>
#include<bits/stdc++.h>
using namespace std;


void printDuplicates(int arr[], int n)
{
    map <int,int> m;
    vector <int> v;
    set<int> s;
    int flag=0;

   for(int i=0;i<n;i++)
   {
       m[arr[i]]+=1;
       if(m[arr[i]]>=2)
       {
           if(s.insert(arr[i]))
           {
               flag=1;
               v.push_back(arr[i]);
           }
       }
   }

    vector<int> :: iterator it=v.begin();
    while(it!=v.end())
    {
        cout << *it << " ";
    }

   if(flag == 0)
   {
       cout <<"-1";
   }
}
int main()
{

    int a[]={2,3,4,5,6};
    printDuplicates(a,5);

}
