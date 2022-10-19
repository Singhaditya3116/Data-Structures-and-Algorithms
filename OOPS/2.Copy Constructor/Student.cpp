#include<iostream>
#include<string.h>
using namespace std;

class Student{
public:
    int age;
    char* name;


    Student(int age,char* name)
    {
        this->age=age;
        this->name = new char[strlen(name)+1];
        strcpy(this->name,name);
    }

    //Copy Constructor
    Student(Student const &s)
    {
        this->age=s.age;

        //this->name = s.name    //Shallow Copy
        this->name = new char[strlen(s.name)+1];
        strcpy(this->name,s.name);
    }

    void display()
    {
        cout <<name<<" "<<age<<endl;
    }
};

int main()
{
    char name[]="abcd";

    Student s1(20,name);
    s1.display();

    Student s2(s1);
    s2.name[0]='H';

    s1.display();
    s2.display();
}
