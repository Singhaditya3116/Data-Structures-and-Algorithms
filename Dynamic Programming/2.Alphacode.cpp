#include<bits/stdc++.h>

using namespace std;

int No_Code(int *A,int size)
{
    if(size == 1 || size == 0)
    {
        return 1;
    }

    int smalloutput=No_Code(A,size-1);

    if(A[size-2]*10 + A[size-1] <=26)
    {
        smalloutput+=No_Code(A,size-2);
    }
    return smalloutput;
}
int No_Code2(int *A,int size,int *output)
{
    if(size == 1 || size == 0)
    {
        return 1;
    }
    if(output[size]>0)
    {
        return output[size];
    }

    int smalloutput=No_Code(A,size-1);

    if(A[size-2]*10 + A[size-1] <=26)
    {
        smalloutput+=No_Code(A,size-2);
    }
    output[size]=smalloutput;
    return smalloutput;
}





int main()
{
    string input;
    cin >>input;

    int A[5000];
    int size=input.length();
    for(int i=0;i<size;i++)
    {
        A[i]=input[i]-48;
    }
    //-------------array for storing repeated work----------
    int output[size+1]={};
    int ans= No_Code2(A,size,output);
    cout <<ans <<endl;

    return 0;
}
