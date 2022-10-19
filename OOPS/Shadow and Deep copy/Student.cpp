#include<string.h>

class Student{

    int age;
    char* name;

public:
    Student(int age,char* name)
    {
        //cout <<"Name "<<&name<<endl;
        this->age=age;
        // -----------  this->name=name;   //Shallow Copy;

        this->name = new char[strlen(name)+1];
        strcpy(this->name,name);
    }

    void display()
    {
        cout <<name<<" "<<age<<endl;
    }
};
