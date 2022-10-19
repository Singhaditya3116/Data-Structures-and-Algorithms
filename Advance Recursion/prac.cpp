#include <iostream>
#include <string>
using namespace std;

int main() {
    string n;
    cin >>n;
    int length=n.length();
    int A[length];
    for(int i=0;i<length;i++)
    {
        int temp=int(n[i]);
        A[i]=temp-48;
    }
    for(int i=0;i<length;i++)
    {
        cout <<A[i] <<" ";
    }
}

