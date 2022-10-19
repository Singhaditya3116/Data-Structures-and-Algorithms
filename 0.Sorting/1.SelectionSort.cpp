#include<iostream>
using namespace std;

void selectionSort(int input[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        //Find minimum in the array
        int min = input[i],minIndex = i;
        for(int j=i+1;j<n;j++)
        {
            if(input[j] < min)
            {
                min=input[j];
                minIndex=j;
            }
        }
        //Swap the minimum with the first index of the unsorted array
        int temp = input[i];
        input[i]=min;
        input[minIndex] = temp;
    }
}

int main()
{
    int input[]={7,8,1,2,5,9,6};
    selectionSort(input,7);

    for(int i=0;i<7;i++)
    {
        cout <<input[i] << " ";
    }
    cout <<endl;
}
