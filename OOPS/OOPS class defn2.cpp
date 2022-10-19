#include<bits/stdc++.h>

using namespace std;

class Student{
    public:
    string name;

    void Intro();
};

void Student:: Intro()
{
    cout<<"hello "<<name<<endl;
}

int main()
{
    Student s1;
    s1.name="aditya";
    s1.Intro();

    //DYNAMIC OBJECT
    Student* s2=new Student;
    (*s2).name="singh"; //s2->name="singh";
    (*s2).Intro();//s2->intro();
    return 0;
}
