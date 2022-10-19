#include<bits/stdc++.h>

using namespace std;

class Player{
    public:
        static int count;
        Player(){
            count++;
        }
        ~Player(){
            count--;
        }
};

int Player::count=0; //static member definition
int main()
{
    Player p1;
    cout <<"player p1 "<<p1.count<<endl;
    {
        Player p2;
        cout <<"player p1 "<<Player::count<<endl;
    }//p2 get destroyed
    cout <<"COUNT "<<Player::count<<endl;
    return 0;
}
