#include<bits/stdc++.h>

using namespace std;

class stackUsingArray{
private:
    int *data;
    int top=-1;
    int capacity; //How much element my stack can hold.

public:
    stackUsingArray(int totalsize)
    {
        data=new int[totalsize];
        capacity=totalsize;
    }

    //returns the number of element present in the stack
    int size()
    {
        return top+1;
    }

    //checks if stack is empty or not
    bool isEmpty()
    {
        if(top==-1)
            return true;
        else
            return false;
        //return top==-1;
    }

    //insert element in the stack

    void push(int value)
    {
        if((top+1)>=capacity)
        {
            cout <<"Stack OverFlow"<<endl;
            return;
        }
        top++;
        data[top]=value;
    }

    int pop()
    {
        if(top==-1)
        {
            cout <<"Stack Underflow"<<endl;
            return INT_MIN;
        }
        int value=data[top];
        top--;
        return value;
    }

    int peek()
    {
        if(top==-1)
        {
            cout <<"Stack Underflow"<<endl;
            return INT_MIN;
        }
        return data[top];
    }
};

int main()
{
    stackUsingArray s(4);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout <<s.peek()<<endl;
    cout <<s.pop()<<endl;
    cout <<s.pop()<<endl;

    cout <<s.size()<<endl;

    cout <<s.isEmpty()<<endl;
}
