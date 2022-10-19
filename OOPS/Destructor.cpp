#include<bits/stdc++.h>

using namespace std;

class House{
public:
    int a;
    House()//constructor
    {
        cout<<"hello xhfgdgf"<<endl;
    }

    ~House()//DESTRUCTOR
    {
        cout<<"destructor is called"<<endl;
    }
};

int main()
{
    House* h1=new House();//function is called when an object of the class is created;
    delete h1;//When memory get deleted destructor get called
    return 0;
}

