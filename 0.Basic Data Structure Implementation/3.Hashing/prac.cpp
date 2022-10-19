#include<iostream>

using namespace std;

int main()
{
    int i=6,a=23;
    int j=0;
    j=i+a&&i/a&&i+i;

    if(j)
    {
        cout <<"stais "<<j<<endl;
    }
    else
    {
        cout <<j*j<<endl;
    }
    return 0;
}
