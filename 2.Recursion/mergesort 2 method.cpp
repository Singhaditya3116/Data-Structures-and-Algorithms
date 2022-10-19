
#include <iostream>

using namespace std;

void merge1(int input[],int L[],int R[],int leftsize,int rightsize)
{

    int i=0,j=0,k=0;
    while(i<leftsize && j<rightsize)
    {

        if(L[i]<R[j])
        {
            input[k]=L[i];
            i++;
            k++;
        }
        else
        {
            input[k]=R[j];
            k++;
            j++;
        }
    }
    while(i<leftsize)
    {
        input[k]=L[i];
        i++;
        k++;
    }
    while(j<rightsize)
    {
        input[k]=R[j];
        k++;
        j++;
    }
}

void mergeSort(int input[], int size){
    if(size<=1)
    {
        return;
    }
    int mid=size/2;
    int leftsize=mid;
    int rightsize=size-mid;
    int L[leftsize];
    int R[rightsize];
    for(int i=0;i<leftsize;i++)
    {
        L[i]=input[i];
    }
    for(int i=0;i<rightsize;i++)
    {
        R[i]=input[mid+i];
    }
    mergeSort(L,leftsize);
    mergeSort(R,rightsize);

    merge1(input,L,R,leftsize,rightsize);
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
