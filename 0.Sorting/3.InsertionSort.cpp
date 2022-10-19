#include<iostream>
using namespace std;

void insertionSort(int input[],int n)
{
    for(int i=1;i<n;i++)
    {
        int value = input[i];
        int j;
        for(j=i-1;j>=0;j--)
        {
            if(input[j] > value)
            {
                input[j+1] = input[j];
            }
            else
            {
                break;
            }
        }
        input[j+1]=value;
    }
}



int main()
{
    int input[]={7,8,1,2,5,9,6};
    insertionSort(input,7);

    for(int i=0;i<7;i++)
    {
        cout <<input[i] << " ";
    }
    cout <<endl;
}
