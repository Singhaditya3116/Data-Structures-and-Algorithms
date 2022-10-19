#include<bits/stdc++.h>
//The main aim of OOP is to bind together the data and the functions that operate on
//them so that no other part of the code can access this data except that function.
using namespace std;

class House{
public:
    int a;
    House()//constructor
    {
        cout<<"hello xhfgdgf"<<endl;
    }
    ~House()
    {
        cout <<"Destructor called"<<endl;
    }
};

int main()
{
    House h1;//function is called when an object of the class is created;
    return 0;
}
