#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i=0;i<N;i++)
    {
        cin >> A[i];
    }

    int temp=0,j,i=0;
    while(i<N)
    {
        if(i%2==1)
        {
            j=1;
            while(j<N)
            {

                if(A[j]>A[j+1])
                {
                    temp=A[j];
                    A[j]=A[j+1];
                    A[j+1]=temp;
                }
                j=j+2;
            }
        }
        else
        {
            j=0;
            while(j<N)
            {
                if(A[j]>A[j+1])
                {
                    temp=A[j];
                    A[j]=A[j+1];
                    A[j+1]=temp;
                }
                j=j+2;
            }
        }
        i=i+1;
    }
    for(i=0;i<N;i++)
    {
        cout << A[i] << " " ;
    }



	return 0;
}
