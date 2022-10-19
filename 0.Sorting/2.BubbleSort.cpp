#include<iostream>
using namespace std;

void bubbleSort(int A[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(A[j] <= A[j+1])
            {
                continue;
            }
            else
            {
                int temp = A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}

int main()
{
    int input[]={7,8,1,2,5,9,6};
    bubbleSort(input,7);

    for(int i=0;i<7;i++)
    {
        cout <<input[i] << " ";
    }
    cout <<endl;


}
