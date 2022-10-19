#include<iostream>
#include<vector>
using namespace std;

void allIndex(int *a,int size,int value,vector<int> output)
{
    if(size == 1)
    {
        if(a[0] == value)
        {

            output.push(0);
        }
        return;

    }
    if(a[0] == value)
    {
        output.push(0);
    }

    allIndex(a+1,size-1,value,output);

    for(int i=0;i<output.size();i++)
    {
        output[i]++;
    }

}

int main()
{
    int a[] = {10,5,6,7,5};

    vector<int> output;
    allIndex(a,sizeof(a)/sizeof(int),value,output);




    return 0;
}
