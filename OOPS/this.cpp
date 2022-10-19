#include<bits/stdc++.h>

using namespace std;

class Point{
    public:
        int x,y;

        Point(int x1,int y1)
        {
            x=x1;
            y=y1;
        }

       /* Point(int x,int y)
        {
            this->x=x;
            this->y=y;
        }*/
};

int main()
{
    Point p1(3,4);

    cout <<p1.x <<" "<<p1.y<<endl;

    return 0;
}
