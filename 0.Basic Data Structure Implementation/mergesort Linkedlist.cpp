// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends


/* Structure of the linked list node is as
struct Node
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

/* Function to mergesort the linked list
   It should return head of the modified list  */

Node *findMid(Node *head)
{
    if(head==NULL) return head;

    if(head->next==NULL) return head;

    Node *slow=head;
    Node *fast=head->next;
    cout <<"hdggy "<<slow->data<<" "<<fast->data<<endl;

    while(fast->next!=NULL && fast!=NULL)
    {
        slow=slow->next;
        cout <<"work "<<slow->data<<en
        fast=fast->next;
        cout <<"fast "<<fast->data<<" "<<fast->next<<endl;
        if(fast->next==NULL)
        {
            break;
        }
        fast=fast->next;
        cout <<"fast "<<fast->data<<endl;

    }
    cout <<"sloe "<<slow->data<<endl;
    return slow;
}


Node *merge(Node *h1,Node *h2)
{
    Node *finalHead=NULL;
    Node *finalTail=NULL;

    while(h1!=NULL&&h2!=NULL)
    {
        if(h1->data < h2->data)
        {
            if(finalHead==NULL)
            {
                finalHead=h1;
            }
            else
            {
                finalTail->next=h1;
            }
            finalTail=h1;
            h1=h1->next;

        }else{
            if(finalHead==NULL)
            {
                finalHead=h2;
            }
            else
            {
                finalTail->next=h2;
            }
            finalTail=h2;
            h2=h2->next;
        }
    }

    if(h1==NULL&&h2!=NULL)
    {
        finalTail->next=h2;
    }
    if(h2==NULL&&h1!=NULL)
    {
        finalTail->next=h1;
    }
    return finalHead;
}

Node* mergeSort(Node* head) {
    cout <<"hmm "<<head->data<<endl;
    // your code here
    if(head->next==NULL || head==NULL)
    {
        return head;
    }
    cout<<"mid"<<endl;
    Node *mid=findMid(head);
    cout<<"hello"<<endl;
    Node *secondHead=mid->next;
    mid->next=NULL;
    cout <<"end"<<endl;

    Node *firstPart=mergeSort(head);
    Node *secondPart=mergeSort(secondHead);

    Node *finalHead=merge(firstPart,secondPart);
    return finalHead;
}


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        printList(a);
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends
