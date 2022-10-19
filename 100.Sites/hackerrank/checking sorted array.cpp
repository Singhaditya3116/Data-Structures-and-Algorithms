#include<bits/stdc++.h>
using namespace std;

bool sorted(int A[],int size)
{
    if(size==0 || size==1)
    {
        return true;
    }

    bool smallsorted=sorted(A+1,size-1);
    if(smallsorted)
    {
        if(A[0]>A[1])
        {
            return false;
        }
        else{
            return true;
        }
    }
    else{
        return false;
    }

}

int main()
{
    int A[6]={2,3,4,5,6,7};
    bool output = sorted(A,6);

    if(output)
    {
        cout <<"array is sorted";
    }
    else{
        cout <<"array is not sorted";
    }
}
