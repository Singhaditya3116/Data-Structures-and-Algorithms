#include<bits/stdc++.h>
using namespace std;
//Higher the no ,higher the priority

int index=0;

void insertElement(int *arr,int &index,int value)
{
    arr[index]=value;
    index++;
}
void deleteElement(int*arr,int &index)
{
    if(index == 0)
    {
        cout << "Empty Quueue" <<endl;
        return;
    }
    int maxEle=INT_MIN;
    int maxIndex=0;
    for(int i=0;i<=index;i++)
    {
        if(arr[i]>maxEle)
        {
            maxEle = arr[i];
            maxIndex=i;
        }
    }

    for(int i=maxIndex+1;i<=index;i++)
    {
        arr[i-1]=arr[i];
    }
    index--;
}
void display(int *arr ,int &index)
{
    if(index==0)
    {
        return;
    }
    for(int i=0;i<=index;i++)
    {
        cout <<arr[i] << " ";
    }
    cout  <<endl;
}

int main()
{
    int arr[10];
    for(int i=0;i<10;i++)
    {
        arr[i]=0;
    }
    int option;
    do{

        cout << "1.insert element"<<endl;
        cout << "2.delete element" <<endl;
        cout << "3.display" <<endl;
        cout << "Enter the opt"<<endl;
        cin >> option;

        switch(option)
        {
            case 1: cout << "Enter teh value";
                    int value;
                    cin >> value;
                    insertElement(arr,index,value);
                    break;
            case 2: deleteElement(arr,index);
                    break;
            case 3: display(arr,index);
        }
    }while(option!=5);

    return 0;
}
