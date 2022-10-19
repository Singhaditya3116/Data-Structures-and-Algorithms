#include<bits/stdc++.h>
using namespace std;
#define Max 20
int queu[Max];
int front=-1,rear=-1;

void insertQ()
{
    if(rear == Max-1)
    {
        cout << "queue overflow" <<endl;
    }
    else
    {

        cout << "Enter the value to be added" <<endl;
        int value;
        cin >> value;
        if(front == -1)
        {
            front =0;
        }
        rear++;
        queu[rear]=value;
    }
}

void deleteQ()
{
    if(rear == -1 || front > rear)
    {
        cout << "queue underflow" <<endl;
    }
    else
    {
        int val=queu[front];
        cout << "the value deleted is" << val <<endl;
        front++;
    }
}

void display()
{
    if(rear == -1 || front >rear)
    {
        cout << "Queue Empty" <<endl;
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            cout <<queu[i] << " ";
        }
        cout <<endl;
    }
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
            insertQ();
            break;
        case 2:
            deleteQ();
            break;
        case 3:
            display();
            break;
        }
    }while(option <=10);
}
