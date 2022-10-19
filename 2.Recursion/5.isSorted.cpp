#include<iostream>
using namespace std;

bool is_Sorted(int *a,int size)
{
    if(size == 0 || size == 1) //Base Case
    {
        return true;
    }

    if(a[0] > a[1]) //Not a Base Case
    {
        return false;
    }

    bool isSmallerSorted= is_Sorted(a+1,size-1);
    return isSmallerSorted;
}


int main()
{

    int arr[] = {1,3,2,4,5};
    cout <<is_Sorted(arr,sizeof(arr)/sizeof(int));
    return 0;
}
