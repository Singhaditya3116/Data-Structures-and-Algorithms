#include<bits/stdc++.h>

using namespace std;

template <typename T>
class stackUsingArray{
private:
    T *data;
    int top=-1;
    int capacity;

public:
    stackUsingArray()
    {
        data=new T[2];
        capacity=2;
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

    void push(T value)
    {
        if((top+1)>=capacity)
        {
            //cout <<"Stack OverFlow"<<endl;
            T *newArray = new T[capacity*2];
            for(int i=0;i<capacity;i++)
            {
                newArray[i]=data[i];
            }
            capacity*=2;
            delete [] data;
            data=newArray;
        }
        top++;
        data[top]=value;
    }

    T pop()
    {
        if(top==-1)
        {
            cout <<"Stack Underflow"<<endl;
            return 0;
        }
        T value=data[top];
        top--;
        return value;
    }

    T peek()
    {
        if(top==-1)
        {
            cout <<"Stack Underflow"<<endl;
            return 0;
        }
        return data[top];
    }
};




int main()
{
    stackUsingArray<char> s;

    s.push('A');
    s.push('B');
    //cout <<"Capacity "<<s.capacity<<endl;
    s.push('C');
    //cout <<"Capacity "<<s.capacity<<endl;
    s.push('D');
   // cout <<"Capacity "<<s.capacity<<endl;
    s.push('E');
    //cout <<"Capacity "<<s.capacity<<endl;

    cout <<s.peek()<<endl;
    cout <<s.pop()<<endl;
    cout <<s.pop()<<endl;

    cout <<s.size()<<endl;

    cout <<s.isEmpty()<<endl;
}
