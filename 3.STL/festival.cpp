#include<bits/stdc++.h>
using namespace std;
int main() {

	int N;
    cin >>N;
    int  arrivaltime[N];
    int departure_time[N];
    for(int i=0;i<N;i++)
    {
        cin>>arrivaltime[i];
    }
    for(int i=0;i<N;i++)
    {
        cin>>departure_time[i];
    }
    sort(arrivaltime,arrivaltime+N);
    sort(departure_time,departure_time+N);
    int minchair=0;
    int j=0;
    for(int i=0;i<N;i++)
    {
        if(departure_time[j]>arrivaltime[i])
        {
            minchair+=1;
        }
        else
        {
            j++;
        }
    }
    cout<<minchair<<endl;
}
