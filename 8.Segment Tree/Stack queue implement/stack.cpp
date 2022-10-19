#include<iostream>
using namespace std;
#define max 10

void push(int st[],int& top,int value)
{
    if(top == max-1)
    {
        cout << "stack overflow\n";
    }
    else
    {
        top++;
        st[top]=value;
    }
}

void pop(int st[],int& top)
{
    if(top == -1)
    {
        cout<<"stack underflow"<<endl;
    }
    else
    {
        cout << "topmost value is deleted which is"<<st[top]<<endl;
        top--;
    }
}

void display(int* st,int top)
{
        while(top>=0)
        {
            cout << st[top] << " ";
            top--;
        }
        cout << endl;
}
int main()
{
    int st[max];
    int top=-1;
    int option,value;
    do
    {
        cout <<"1.Push\t";
        cout <<"2.Pop\t";
        cout <<"3.display\t";
        cout <<"4.exit\n";
        cin >> option;
        switch(option)
        {
        case 1 :
                cout <<"enter the value to be pushed ";
                cin >> value;
                push(st,top,value);
                break;
        case 2:
                pop(st,top);
                break;
        case 3:
                display(st ,top);
        }
    }while(option!=4);
}
