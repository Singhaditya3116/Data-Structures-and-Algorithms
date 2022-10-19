#include<bits/stdc++.h>

using namespace std;

class triplet{
    public:
        int b;
        int k;
        int gcd;
};

triplet extendedEuclid(int a,int m)
{
    if(m == 0)
    {
        triplet ans;
        ans.gcd = a;
        ans.b=1;
        ans.k=0;
        return ans;
    }
    triplet smallans = extendedEuclid(m,a%m);
    triplet ans;
    ans.gcd= smallans.gcd;
    ans.b = smallans.k;
    ans.k = smallans.b - ((a/m)*smallans.k);

    return ans;
}



int main()
{
    int A,m;
    cin >>A>>m;

    triplet ans = extendedEuclid(A,m);
    cout <<"x= "<<ans.b<<endl;

    return 0;
}
