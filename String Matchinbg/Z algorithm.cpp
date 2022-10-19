#include<bits/stdc++.h>
using namespace std;

void FillZarray(string s,int size,int* Zarr)
{
    int i=0,j=1;
    Zarr[0]=0;
    while()
    {
        if(s[i]==s[j])
        {
            i++;
            j++;
        }
        else{
            Zarr[j]=0;
            j++;
        }

    }

}

int main()
{
  string text,pattern;
  cin >>text>>pattern;

  string s=text+"$"+pattern;
  int size=s.length();
  int* Zarr=new int[size]();

  FillZarray(s,size,Zarr);

  for(int i=0;i<size;i++)
  {
      if(Zarr[i]==pattern.length())
      {
          cout<<i-pattern.length()-1<<endl;
      }
  }

}
