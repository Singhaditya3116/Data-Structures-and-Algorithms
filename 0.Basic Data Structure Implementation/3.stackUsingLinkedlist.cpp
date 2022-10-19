#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Node{

public:
    T data;
    Node<T> *next;

    Node(T data){
        this->data=data;
        this->next=NULL;
    }
};


template <typename T>
class Stack{

private:
    Node<T> *head;
    int Size; // TO get the size in O(1)

public:
    Stack(){
        head=NULL;
        Size=0;
    }

    void push(T value)
    {
        Node<T> *newnode=new Node<T>(value);
        if(head==NULL)
        {
            head=newnode;
            Size=1;
        }
        else
        {
            newnode->next=head;
            head=newnode;
            Size++;
        }
    }

    T pop()
    {
        if(head == NULL)
        {
            cout <<"Stack Underflow"<<endl;
            Size=0;
            return 0;
        }
        Node<T> *temp=head;
        T value=temp->data;
        head=head->next;
        delete temp;
        Size--;
        return value;
    }

    T peek()
    {
        if(head == NULL)
        {
            cout <<"Stack Underflow"<<endl;
            return 0;
        }
        return head->data;
    }

    T getSize()
    {
        return Size;
    }

    bool isEmpty()
    {
        if(head==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout <<s.peek()<<endl;
    cout <<s.pop()<<endl;
    cout <<s.pop()<<endl;

    cout <<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;

    return 0;
}
