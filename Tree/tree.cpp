#include<bits/stdc++.h>
#include<queue>
#include<stack>
using namespace std;

class Node
{
    public:
        int data;
        Node *lchild=NULL;
        Node *rchild=NULL;
};
Node *root=NULL;

void create()
{
    int x;
    cout << "Enter the root value" <<endl;
    cin >> x;
    root=new Node;
    root->data=x;
    queue <Node *> q;
    q.push(root);
    Node *ptr=NULL;
    while(!q.empty())
    {
        ptr=q.front();
        q.pop();
        int value;
        cout << "Enter the left child of " << ptr->data << " ";
        cin >> value;
        if(value != -1)
        {
            Node *temp=new Node;
            temp->data =value;
            q.push(temp);
            ptr->lchild = temp;
        }
        cout << "Enter the right child of" << ptr->data << " ";
        cin >> value;
        if(value !=-1)
        {
            Node *temp1=new Node;
            temp1->data=value;
            q.push(temp1);
            ptr->rchild = temp1;
        }

    }
}

void Preorder(Node *p)
{
    if(p)
    {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Iter_preorder(Node *p)
{
    stack <Node *> st;
    while(!st.empty() || p!=NULL)
    {
        if(p != NULL)
        {
            cout << p->data << " ";
            st.push(p);
            p = p->lchild;
        }
        else
        {
            p=st.top();
            st.pop();
            p=p->rchild;
        }
    }
}


void Postorder(Node *p)
{
    if(p == NULL)
    {
        return;
    }
    Postorder(p->lchild);
    Postorder(p->rchild);
    cout << p->data << " ";
}

void Iter_postorder(Node *p)
{
    stack <Node *> st;
    stack <Node *> temp;
    while(p!=NULL || !st.empty())
    {
        if(p!= NULL)
        {
            st.push(p);
            p=p->lchild;
        }
        else
        {
            p=st.top();
            st.pop();
            temp.push(p);
            p=p->rchild;
            if(!temp.empty())
            {
                p=temp.top();
                temp.pop();
                cout << p->data << " ";
                p=NULL;
            }
            /*st.pop();
            if(temp > 0)
            {
                st.push(-temp);
                p = ((Node *)temp)->rchild;
            }
            else
            {
                cout << ((Node *)temp)->data <<" ";
                p=NULL;
            }*/
        }
    }
}

void Postorder_it(Node* p)
{
    stack <Node *> st;
    stack<int> s;

    while(!st.empty() || p!=NULL)
    {
        if(p!=NULL)
        {
            s.push(p->data);
            st.push(p);
            p=p->rchild;
        }
        else
        {
            p=st.top();
            st.pop();
            p=p->lchild;
        }
    }

    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

void Inorder(Node *p)
{
    if(p == NULL)
    {
        return;
    }
    Inorder(p->lchild);
    cout << p->data << " ";
    Inorder(p->rchild);
}

void Iter_Inorder(Node *p)
{
    stack <Node *> st;
    while(!st.empty() || p!=NULL)
    {

        if(p!=NULL)
        {
            st.push(p);
            p=p->lchild;
        }
        else
        {
            p=st.top();
            st.pop();
            cout << p->data << " ";
            p=p->rchild;
        }
    }


}

void level(Node *p)
{
    queue <Node *> q;
    q.push(p);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        cout << p->data << " ";
        q.push(p->lchild);
        q.push(p->rchild);
    }
}


int height(Node *p)
{
    if(p == NULL)
    {
        return 0;
    }
    int option1 = height(p->lchild);
    int option2 = height(p->rchild);
    return (max(option1,option2)+1);
}

int countnode(Node *p)
{
    if(p == NULL)
    {
        return 0;
    }
    int option1 = countnode(p->lchild);
    int option2 = countnode(p->rchild);
    return option1 + option2 +1;
}

int leafnodecount(Node *p)
{
    if(p == NULL)
    {
        return 0;
    }
    int option1 = leafnodecount(p->lchild);
    int option2 = leafnodecount(p->rchild);
    if(p->lchild == NULL && p->rchild == NULL)
    {
        return option1 + option2 +1;
    }
    return option1 + option2;
}

int nonleafnodecount(Node *p)
{
    if(p == NULL)
    {
        return 0;
    }
    int option1 = nonleafnodecount(p->lchild);
    int option2 = nonleafnodecount(p->rchild);
    if(p->lchild !=NULL || p->rchild != NULL)
    {
        return option1 + option2 +1;
    }
    return option1 + option2;
}

void mirrortree(Node *p)
{
    if(p == NULL)
    {
        return;
    }
    mirrortree(p->lchild);
    mirrortree(p->rchild);
    Node * temp = p->lchild;
    p->lchild = p->rchild;
    p->rchild = temp;
}

int main()
{
    create();
    cout << "Preorder traversal is ";
    Preorder(root);
    cout << endl << " Iter Pre order traversal is ";
    Iter_preorder(root);
    cout << endl << "Post order traversal is ";
    Postorder(root);
    cout <<endl <<"Mirror Tree is ";
    mirrortree(root);
    cout << endl << " Iter post order traversal is ";
    Postorder_it(root);
    cout <<endl;
    Inorder(root);
    cout <<endl;
    Iter_Inorder(root);
    cout << endl;
    cout << "height is " << height(root)-1<<endl;
    cout << "leaf node count is " << leafnodecount(root) <<endl;
    cout << "Non leaf node is " << nonleafnodecount(root) <<endl;
    cout << "count of nodes is " << countnode(root) <<endl;
    cout << "Level order is ";
    level(root);
    cout <<endl;

    return 0;
}
