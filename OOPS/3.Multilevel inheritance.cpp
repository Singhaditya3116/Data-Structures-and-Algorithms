#include<bits/stdc++.h>
///In this type of inheritance, a derived class is created from another derived class.
using namespace std;

class Vehicle{
  public:
    Vehicle(){
        cout <<"Vehicle constructor is called"<<endl;
    }
};


class FourWheeler : public Vehicle{
    public:
        FourWheeler(){
            cout <<"FourWheeler constructor is called "<<endl;
        }
};

class Car : public FourWheeler{  //Inherit from more than one class.
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

