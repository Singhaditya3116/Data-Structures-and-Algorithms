#include<iostream>
using namespace std;


class Fraction{

private :
    int numerator;
    int denominator;

public:
    Fraction(int numerator,int denominator)
    {
        this->numerator=numerator;
        this->denominator=denominator;
        //cout <<"Constructor called"<<endl;
    }

    void print()
    {
        cout <<this->numerator<<"/"<<this->denominator<<endl;
        return;
    }

    void simplify()
    {
        int gcd=1;
        for(int i=1;i<=min(numerator,denominator);i++)
        {
            if(numerator%i==0 && denominator%i==0)
            {
                gcd = i;
            }
        }
        numerator=numerator/gcd;
        denominator=denominator/gcd;
    }

    void add(const Fraction &f2)    // Fraction f2  = main.f2
    {
        int lcm = denominator*f2.denominator;
        numerator = (numerator*f2.denominator)+(denominator*f2.numerator);
        denominator=lcm;
        simplify();
    }
};



int main()
{

    Fraction f1(10,2);
    Fraction f2(15,4);
    f1.print();
    f1.add(f2);
    f1.print();

}
