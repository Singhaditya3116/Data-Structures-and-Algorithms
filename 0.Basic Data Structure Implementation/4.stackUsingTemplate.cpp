#include<bits/stdc++.h>

using namespace std;

template <typename T>
class stackUsingArray{
private:
    T *data;
    int top=-1;
    int capacity;

public:
    stackUsingArray(int totalsize)
    {
        data=new T[totalsize];
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

    void push(T value)
    {
        if((top+1)>=capacity)
        {
            //cout <<"Stack Overlow"<<endl;
            T *newData = new T[capacity*2];
            for(int i=0;i<capacity;i++)
            {
                newData[i]=data[i];
            }
            capacity*=2;
            data=newData;
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
    stackUsingArray<char> s(4);

    s.push('A');
    s.push('B');
    s.push('C');
    s.push('D');
    s.push('E');

    cout <<s.peek()<<endl;
    cout <<s.pop()<<endl;
    cout <<s.pop()<<endl;

    cout <<s.size()<<endl;

    cout <<s.isEmpty()<<endl;
}
