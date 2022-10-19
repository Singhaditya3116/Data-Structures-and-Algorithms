#include<bits/stdc++.h>

using namespace std;

class Vehicle{
  public:
    Vehicle(){
        cout <<"Vehicle constructor is called"<<endl;
    }
};


class Car : public Vehicle{
    public:
        Car(){
            cout <<"Car constructor is called"<<endl;
        };

};


int main()
{
    Car c1;
    return 0;
}
