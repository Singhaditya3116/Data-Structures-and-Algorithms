#include<iostream>
using namespace std;

int findgreater(int *arr,int end,int value)
{
    int index=-1;
    int maxvalue=value;
    for(int i=end;i>=0;i--)
    {
        if(arr[i] > maxvalue)
        {
            maxvalue=arr[i];
            index=i;
        }
    }
    return index;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >>arr[i];
    }

    for(int i=n-1;i>=0;i--)
    {
        int index=findgreater(arr,i-1,arr[i]);
        //cout <<arr[i] <<" " <<index <<" "<<arr[index] <<endl;
        if(index!=-1)
        {
            swap(arr[i],arr[index]);
        }
    }

    for(int i=0;i<n;i++)
    {
        cout <<arr[i] <<" ";
    }
    return 0;
}
