#include<iostream>
using namespace std;

void Transpose(int** arr,int start,int end,int &count)
{
    for(int i=start;i<=end;i++)
    {
        int temp = arr[0][i];
        arr[0][i]=arr[i][0];
        arr[i][0]=temp;
    }
    count++;
    return;
}

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n;
        cin >> n;
        int** arr = new int*[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=new int[n];
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> arr[i][j];
            }
        }

        int number=n;
        int count=0;
        for(int i=n-1;i>0;i--)
        {
            if(arr[0][i] != number)
            {
                Transpose(arr,0,i,count);
            }
            number--;
        }

        cout <<count<<endl;

        for(int i=0;i<n;i++)
        {
            delete [] arr[i];
        }
        delete [] arr;
    }

    return 0;
}
