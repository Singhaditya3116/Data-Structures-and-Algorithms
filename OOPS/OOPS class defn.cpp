#include<bits/stdc++.h>

using namespace std;


class Student{
public:
    string name;
    void Intro()
    {
        cout<<"hello"<<name;
    }
};

int main()
{

    Student s1;
    s1.name="aditya";
    s1.Intro();
    return 0;
}
