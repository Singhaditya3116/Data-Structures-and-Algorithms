#include<iostream>

using namespace std;

template <typename T>
class Node{

public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data=data;
        next=NULL;
    }
};


template <typename T>
class queueUsingLinkedlist{

    Node<T> *head; //front
    Node<T> *tail;//rear
    int size;

public:
    queueUsingLinkedlist()
    {
        head=NULL;
        tail=NULL;
        size=0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        if(head==NULL)
        {
            return true;
        }
        return false;
    }

    T front()
    {
        if(head == NULL)
        {
            cout <<"Queue is Empty" <<endl;
            return 0;
        }
        return head->data;
    }

    void enqueue(T element)
    {
        Node<T> *newnode = new Node<T>(element);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
        size++;
    }

    T dequeue()
    {
        if(head==NULL)
        {
            cout <<"Queue is empty"<<endl;
            return 0;
        }

        T ans=head->data;
        Node<T> *temp=head;
        head=head->next;
        delete temp;
        size--;
        return ans;
    }


};
