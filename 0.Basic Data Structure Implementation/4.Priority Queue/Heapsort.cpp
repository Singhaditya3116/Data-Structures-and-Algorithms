#include<iostream>

using namespace std;

void inplaceHeapSort(int input[],int n)
{
    //Bulid Heap;
    int childIndex=0;
    int parentIndex=0;
    for(int i=1;i<n;i++)
    {
        childIndex=i;
        while(childIndex!=0)
        {
            parentIndex=(childIndex-1)/2;
            if(input[parentIndex] > input[childIndex])
            {
                swap(input[parentIndex],input[childIndex]);
                childIndex=parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    //remove elements
    int index=n-1;
    while(index!=0)
    {
        int temp=input[0];
        input[0]=input[index];
        input[index]=temp;

        index--; //my heap size will reduce.

        int parentIndex=0;
        int leftChildIndex=(2*parentIndex)+1;
        int rightChildIndex=(2*parentIndex)+2;

        while(leftChildIndex <= index)
        {
            int minIndex=parentIndex;
            if(input[parentIndex] > input[leftChildIndex])
            {
                minIndex=leftChildIndex;
            }

            if(rightChildIndex <= index && input[minIndex] > input[rightChildIndex])
            {
                minIndex=rightChildIndex;
            }

            if(minIndex == parentIndex) //element is at the correct position
            {
                break;
            }

            int temp=input[parentIndex];
            input[parentIndex]=input[minIndex];
            input[minIndex]=temp;

            parentIndex=minIndex;
            leftChildIndex=(2*parentIndex)+1;
            rightChildIndex=(2*parentIndex)+2;
        }

    }

}

int main()
{
    int arr[]={15,6,3,2,20};
    inplaceHeapSort(arr,5);

    for(int i=0;i<5;i++)
    {
        cout <<arr[i] <<" ";
    }
    return 0;
}
