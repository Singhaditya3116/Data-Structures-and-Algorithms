#include<bits/stdc++.h>
//Multiple Inheritance is a feature of C++ where a class can inherit from more than one classes.
//i.e one sub class is inherited from more than one base classes.
using namespace std;

class Vehicle{
  public:
    Vehicle(){
        cout <<"Vehicle constructor is called"<<endl;
    }
};


class FourWheeler{
    public:
        FourWheeler(){
            cout <<"FourWheeler constructor is called "<<endl;
        }
};

class Car : public Vehicle,public FourWheeler{  //Inherit from more than one class.
    public:
        Car(){
            cout <<"Car constructor is called"<<endl;
        }
};


int main()
{
    Car c1;
    return 0;
}
