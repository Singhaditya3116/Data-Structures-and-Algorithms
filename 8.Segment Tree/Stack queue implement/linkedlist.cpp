#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next=NULL;
};
struct Node *head = NULL; //Poore struct ko point karega

void insert_beg()
{
    Node *newnode=new Node; // int *temp=new int;
    //cout <<sizeof(head) << " " << sizeof(Node) <<endl;
    int temp;
    cout << "Enter the value" <<endl;
    cin >> temp;
    (*newnode).data=temp;
    newnode->next=head;
    head = newnode;
}

void insert_end()
{
    int temp;
    Node *newnode=new Node;
    cout << "enter the value" <<endl;
    cin >> temp;
    newnode->data=temp;
    struct Node *ptr=head;
    while(ptr->next !=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next = newnode;
    newnode->next = NULL;
}

void insert_after()
{
    Node *newnode = new Node;
    int temp;
    cout << "Enter the value to be inserted" <<endl;
    cin >> temp;
    newnode->data=temp;
    int val;
    cout << "after which value it should be inserted" <<endl;
    cin >>val;
    struct Node *postptr=head;
    struct Node *ptr=head;

    while(ptr->data != val)
    {
        ptr=postptr;
        postptr=postptr->next;
    }
    newnode->next=postptr;
    ptr->next=newnode;
}

void insert_bef()
{
    int temp;
    Node *newnode = new Node;
    cout << "enter the value to be inserted" <<endl;
    cin >> temp;
    newnode->data = temp;
    int value;
    cout << "before which value it should be inserted" <<endl;
    cin >> value;
    struct Node *ptr=head;
    struct Node *preptr=head;
    while(ptr->data != value)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    newnode->next=ptr;
    preptr->next=newnode;
}
void Display()
{
    struct Node *ptr=head;
    while(ptr!=NULL)
    {
        cout << ptr->data <<" ";
        ptr=ptr->next;
    }
    cout <<endl;
}

void delete_beg()
{
    struct Node* ptr=head;
    head=head->next;
    delete ptr;
}

void delete_end()
{
    struct Node *ptr;
    struct Node *preptr;
    ptr=head;
    while(ptr->next !=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    delete ptr;
    preptr->next=NULL;
}

void delete_af()
{
    int value;
    cout << "after which value it should be deleted" <<endl;
    cin >> value;
    struct Node *ptr=head;
    struct Node *postptr=head;
    while(ptr->data != value)
    {
        ptr=postptr;
        postptr=postptr->next;
    }
    ptr->next=postptr->next;
}

void delete_bef()
{
    int value;
    cout << "before which value it should be deleted" <<endl;
    cin  >> value;
    struct Node *ptr=head;
    struct Node *preptr=head;
    struct Node*postptr=head;
    while(postptr->data != value)
    {
        preptr=ptr;
        ptr=ptr->next;
        postptr=ptr->next;
    }
    preptr->next=ptr->next;

}
int main()
{
    int option;
    do
    {
        cout <<"1.Insert at beginning" <<endl;
        cout << "2.Display" << endl;
        cout << "3.Insert at end" <<endl;
        cout << "4.Insert after a given node" <<endl;
        cout << "5.Insert before a given Node" <<endl;
        cout << "6.Delete beginning node" <<endl;
        cout << "7.Delete from end" <<endl;
        cout << "8.Delete after a given node" <<endl;
        cout << "9.Delete before a given node" << endl;
        cin >> option;
        switch(option)
        {
        case 1:
            insert_beg();
            break;
        case 2:
            Display();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            insert_after();
            break;
        case 5:
            insert_bef();
            break;
        case 6:
            delete_beg();
            break;
        case 7:
            delete_end();
            break;
        case 8:
            delete_af();
            break;
        case 9:
            delete_bef();
            break;
        }

    }while(option<=10);

    return 0;
}
