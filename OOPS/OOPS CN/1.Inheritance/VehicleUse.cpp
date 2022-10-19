#include<iostream>
#include<string>
using namespace std;

#include "Car.cpp"


int main()
{

    Vehicle v;
    v.color="Black";
    //v.maxSpeed=100;   Cannot be accessible as it is private
    //v.numtyres=4;     Cannot be accessible as it is protected

    Car c;
    c.color="Green";
    c.numGears=8;
   // c.print();
   // c.maxSpeed=100;   Cannot be accessible as it is private
   // c.numtyres=4;     Cannot be accessible as it is protected
}
