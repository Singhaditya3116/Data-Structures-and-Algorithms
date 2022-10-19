#include<stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int a,b;
    cin >> a >> b;
    int maximum,minimum;
    if(a>b)
    {
        maximum=a;
        minimum=b;
    }
    else
    {
        maximum=b;
        minimum=a;
    }

    int maxlength=0;
    while(true)
    {
        maxlength+=minimum;
        if(maxlength>=N)
        {
            break;
        }

    }




    return 0;
}
