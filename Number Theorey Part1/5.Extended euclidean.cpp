#include<bits/stdc++.h>

using namespace std;


class Triplet{
    public:
        int x;
        int y;
        int gcd;
};


Triplet extendedEuclid(int a,int b)
{
    //Base case
    if(b == 0)
    {
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }

    //small calculation;
    Triplet smallAns = extendedEuclid(b,a%b);
    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - ((a/b)*smallAns.y);
    return ans;
}

int main()
{
    int a,b;
    cin >>a >> b;
    Triplet ans = extendedEuclid(a,b);
    cout <<"The Value of X and Y for "<<a<<" and "<<b<<" is "<<ans.x <<" "<<ans.y <<" and the GCD is "<<ans.gcd<<endl;
    return 0;
}




