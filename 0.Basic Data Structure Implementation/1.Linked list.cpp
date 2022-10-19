#include<iostream>
using namespace std;


class Node{
  public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

class Pair{
    public:
        Node *head;
        Node *tail;
};


void print(Node *head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout <<temp->data<<" ";
        temp=temp->next;
    }
    cout <<endl;
}

Node *takeInput()   //O(N^2)
{
    int data;

    Node *head=NULL;
    while(true)
    {
        cin >> data;
        if(data == -1){   //I dont want to take further input.
            return head;
        }
        Node *newnode=new Node(data);
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            Node *temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
    return head;
}


Node *takeInput_optimal()   //O(N)
{
    int data;
    Node *head=NULL;
    Node *tail=NULL;
    while(true)
    {
        cin >> data;
        if(data == -1){   //I dont want to take further input.
            return head;
        }
        Node *newnode=new Node(data);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    return head;
}

Node *insertNode(Node *head,int i,int data)  //insert at ith position,Following 1 based index.
{
    Node *newnode=new Node(data);
    int count=1;
    Node *temp=head;

    if(i==1) //insert at begining
    {
        newnode->next=head;
        head=newnode;
        return head;
    }

    while(temp!=NULL && count != i-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp!=NULL)
    {
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return head;
}

Node *insertRecursive(Node *head,int count,int data)
{
    if(head==NULL) //if initially the linked list given is empty then dont do anything.
    {
        return head;
    }

    if(count == 1)
    {
        Node *newnode=new Node(data);
        newnode->next=head;
        head=newnode;
        return head;
    }

    head->next=insertRecursive(head->next,count-1,data);
    return head;
}

Node *deleteNode(Node* head,int i)
{
    if(i == 1)
    {
        Node* byProduct = head;
        head=head->next;
        delete byProduct;
        return head;
    }

    Node* temp = head;
    int count = 1;

    while(temp!= NULL && count != i-1)
    {
        temp = temp->next;
        count++;
    }
    while(temp != NULL && temp->next != NULL)
    {
        Node* byProduct = temp->next;
        temp->next = temp->next->next;
        delete byProduct;
        return head;
    }
    return head;

}


Node* deleteRecursive(Node* head,int count)
{
    if(head == NULL)
    {
        return head;
    }

    if(count == 1)
    {
        Node* temp = head;
        head=head->next;
        delete temp;
        return head;
    }
    head->next = deleteRecursive(head->next,count-1);
    return head;
}

Node* reverseList(struct Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    Node *smallpart=reverseList(head->next);

    Node *temp=smallpart;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head;
    head->next=NULL;
    head=smallpart;
    return head;
}

Pair reverseList_optimal(struct Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        Pair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }

    Pair smallpart=reverseList_optimal(head->next);

    smallpart.tail->next=head;
    head->next=NULL;
    smallpart.tail=smallpart.tail->next;
    return smallpart;
}

Node* reverseList_tricky(struct Node *head)// tricky approach
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    Node *smallpart=reverseList(head->next);

    Node *tail=head->next;
    tail->next=head;
    head->next=NULL;
    return smallpart;
}

Node *reverseListIterative(Node * head)
{
    if(head==NULL)
    {
        return NULL;
    }

    Node *curr=head;
    Node *prev=NULL;
    Node *ahead=head->next;

    while(curr!=NULL)
    {
        ahead=curr->next;
        curr->next=prev;
        prev=curr;
        curr=ahead;
    }
    head=prev;
    return head;
}

int main()
{
    //Statically
/*
    Node n1(1);   //int a;
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    Node *head=&n1;
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;

    print(head)
*/

    //Dynamically;
/*
    Node *n1=new Node(10);
    Node *n2=new Node(20);
    Node *n3=new Node(30);
    Node *n4=new Node(40);
    Node *n5=new Node(50);

    Node *head=n1;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;

    print(head);
*/

    //Node *head=takeInput();    //O(N^2) approach
    Node *head=takeInput_optimal();  //O(N) approach
    cout <<"Original :";
    print(head);
    /*
    //---------Insert Node at ith position---------
    int i,data;
    cin >> i >>data;
    head=insertNode(head,i,data);
    print(head);
    */
    /*
    //---------Delete Node at ith position---------
    int i;
    cin >> i;
    head = deleteNode(head,i);
    cout <<"Updated :";
    print(head);
    */
    /*
    //-----------Delete Recursive at ith position--------------
    int i;
    cin >>i;
    head=deleteRecursive(head,i);
    cout <<"Updated :";
    print(head);
    */
    int i,data;
    cin >>i >>data;
    head=insertRecursive(head,i,data);
    cout <<"Updated :";
    print(head);

    /*
    Pair p=reverseList_optimal(head);
    head=p.head;
    cout<<endl;
    print(head);
    cout <<endl;
    head=reverseList_tricky(head);
    print(head);
    cout <<endl;
    head=reverseListIterative(head);
    print(head);
    */

    //print(head);


    return 0;
}



