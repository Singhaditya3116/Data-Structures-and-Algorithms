#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next=NULL;
};

struct Node *front=NULL;
struct Node*rear = NULL;

void push()
{
    Node *newnode=new Node;
    int value;
    cout << "Enter the value" <<endl;
    cin >> value;
    newnode ->data =value;
    if(rear == NULL)
    {
        front =newnode;
        rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}

void pop()
{
    if(front ==NULL)
    {
        cout << "Queue is empty" <<endl;
        return;
    }
    struct Node *ptr=front;
    cout << "The value deleted is" << ptr->data <<endl;
    front=front->next;
    delete ptr;
}

void display()
{
    struct Node *ptr=front;
    while(ptr!=NULL)
    {
        cout << ptr->data <<" ";
        ptr=ptr->next;
    }
    cout <<endl;
}

int main()
{
    int option;
    do{
        cout << "1.insert into queue" <<endl;
        cout << "2.delete from queue" <<endl;
        cout << "3.display" <<endl;
        cin >> option;
        switch(option)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        }
    }while(option <=10);




    return 0;
}
