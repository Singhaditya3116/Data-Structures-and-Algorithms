#include<iostream>

using namespace std;

#include "Pair.cpp"

int main()
{
/*
    -----------------Same Datatype for both the variable
    Pair<int> p1;
    p1.setX(5);
    p1.setY(10);

    Pair <double> p2;

    p2.setX(5.55);
    p2.setY(10.10);

    cout <<p1.getX()<<" "<<p1.getY()<<endl;
    cout <<p2.getX()<<" "<<p2.getY()<<endl;
*/

/*

    -----------------Different Datatype for both the variable

    Pair<int,double> p1;
    p1.setX(12);
    p1.setY(22.56);

    cout <<p1.getX() <<" "<<p1.getY()<<endl;

*/

    Pair<Pair<int,int>,int> p1;

    p1.setY(10);

    Pair<int,int> p4;
    p4.setX(15);
    p4.setY(20);

    p1.setX(p4);

    cout <<"p1 ka X "<<p1.getX().getX() <<" "<<p1.getX().getY()<<endl;
    cout <<"p1 ka Y "<<p1.getY()<<endl;


    return 0;
}
