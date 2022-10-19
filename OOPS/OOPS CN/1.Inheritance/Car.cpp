#include "Vehicle.cpp"

class Car : public Vehicle{

public:
    int numGears;

    void print()
    {
        cout << "Numtyres : "<<numtyres <<endl;
        cout << "Color : "<<color<<endl;
        cout << "numGears : "<<numGears<<endl;
    }

    Car()
    {
        cout<<"Car default constructor"<<endl;
    }

    ~Car()
    {
        cout<<"Car default destructor"<<endl;
    }

};
