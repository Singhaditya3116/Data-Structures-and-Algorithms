#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int solved=0;
    while(n--)
    {
        int p1,p2,p3;
        cin >> p1 >>p2 >>p3;
        int sum=0;
        sum=p1+p2+p3;
        if(sum >=2)
        {
            solved++;
        }
    }
    cout << solved <<endl;
    return 0;
}
