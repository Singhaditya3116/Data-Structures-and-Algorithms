
#include<bits/stdc++.h>

using namespace std;

class House{
public:
    string name;
    int age;
    House()//constructor
    {
        name="andugondu";
        age=0;
    }
    House(string x,int ag)//function having same name but different parameter
    {
        name=x;
        age=ag;
    }
    void Display()
    {
        cout<<name<<" "<<age<<endl;
    }
};

int main()
{
    House h1;//function is called when an object of the class is created;
    h1.Display();


    House h2("aditya",20);
    h2.Display();

    return 0;
}
