#include <iostream>
using namespace std;

int main() {
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        int n;
        cin >>n;

        int A[n];
        for(int i=0;i<n-1;i++)
        {
            cin >>A[i];
        }

        int commondiff=0;
        commondiff=A[1]-A[0];
        int diff=0;
        for(int i=0;i<n-1;i++)
        {
            int j=i+1;
            diff=A[j]-A[i];
            if(diff!=commondiff)
            {
                cout << A[i]+diff <<endl;
                break;
            }
        }
    }

	return 0;
}
