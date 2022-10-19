#include<bits/stdc++.h>

using namespace std;

int decoding(int *a,int size)
{
    if(size==1)
    {
        return 1;
    }
    if(size==0)
    {
        return 1;
    }
    int output = decoding(a,size-1);

    if(a[size-2]*10+a[size-1]<=26)
    {
    output+=decoding(a,size-2);
    }

    return output;
}
/*int decoding2(int *a,int size,int *output_array)
{

    if(size==1)
    {
        return 1;
    }
    if(size==0)
    {
        return 1;
    }
    if(output_array[size]>0)
    {
        return output_array[size];
    }
    int output = decoding(a,size-1,output_array);

    if(a[size-2]*10+a[size-1]<=26)
    {
        output+=decoding(a,size-2,output_array);
    }
    output_array[size]=output;
    return output;
}*/
int decoding2(int *a,int size,int *output_array)
{
     if(size==1)
    {
        if(size==1 && a[size]==0)
        {
            return 0;
        }

        return 1;
    }
    if(size==0)
    {
        return 1;
    }

    if(output_array[size]>0)
    {
        return output_array[size];
    }
    int output = decoding2(a,size-1,output_array);
    if(a[size-2]*10+a[size-1]<=26)
    {
        if(a[size-1]==0&&a[size-2]==0)
        {
            output_array[size]=0;
            return 0;
        }
        if(a[size-2]==0)
        {
            output+=0;
            output_array[size]=output;
            return output;
        }
        if(a[size-1]==0)
        {
            output_array[size]=1;
            return 1;
        }
        output+=decoding2(a,size-2,output_array);
    }


    output_array[size]=output;
    return output;
}


int main()
{
    string s;

    while(cin >> s)
    {

    int size_arr =s.size();
    int input[size_arr];
    int output_array[size_arr+1]={0};

    for(int i=0;i<size_arr;i++)
     {
       input[i]=s[i] - 48;
     }

        int ans =decoding2(input,size_arr,output_array);
        ans=ans%1000000007;
         cout <<ans<<endl;



    }
    return 0;


}
