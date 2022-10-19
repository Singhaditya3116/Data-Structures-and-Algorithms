#include<bits/stdc++.h>
//Overloading -- same name but diff parameter
using namespace std;

class TimePass{
    public:
        void fun(int x)
        {
            cout <<"value of x is "<<x<<endl;
        }

        void fun(double x)
        {
            cout <<"value of x is "<<x<<endl;
        }

        void fun(int x,int y)
        {
            cout <<"value of x is "<<x <<" y is "<<y<<endl;
        }
};

int main()
{
    TimePass t1;
    t1.fun(5);
    t1.fun(12.5);
    t1.fun(2,3);
    return 0;
}
