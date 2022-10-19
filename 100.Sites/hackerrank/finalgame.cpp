#include <iostream>
#include<set>
using namespace std;

int removeDuplicates(int arr[], int n)
{
    int i;
    set<int> s;
    for (i = 0; i < n; i++) {
        s.insert(arr[i]);
    }

    set<int>::iterator it;
    int count=0;
    for (it = s.begin(); it != s.end(); ++it)
    {
        count ++;
    }
    return count;
}

int main(){

    int N,Q;
    cin >> N >>Q;
    int A[N];
    for(int i=0;i<N;i++)
    {
        cin >> A[i];
    }
    while(Q--)
    {
        int type,left,right;
        cin >> type;
        if(type==1)
        {
            cin >> left >> right;
            int n=right-left;
            int count = removeDuplicates(A,n);
            cout << count <<endl;
        }
        else
        {
            char rotat;
            cin >>left >> right >> rotat;
            if(rotat == 'L')
            {
                for(int i=(left-1);i<(right-1);i++)
                {
                    int temp=A[i];
                    A[i]=A[i+1];
                    A[i+1]=temp;
                }

            }
            else{
                for(int i=(right-1);i>(left-1);i--)
                {
                    int temp=A[i];
                    A[i]=A[i-1];
                    A[i-1]=temp;
                }

            }

        }

    }

	return 0;
}
