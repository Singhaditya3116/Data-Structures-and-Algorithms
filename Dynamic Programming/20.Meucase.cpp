#include<bits/stdc++.h>
using namespace std;

bool order = true;

void computePrice(int pricePerUnit, int &totalPrice)
{
    int quantity;
    cin >> quantity;

    totalPrice +=(quantity*pricePerUnit);

    char furtherMore;
    cin >>furtherMore;
    if(furtherMore == 'y')
    {
        order =true;
    }
    else
    {
        order = false;
    }
}

int main()
{
    int total = 0;
    do
    {
        int option;
        cin >> option;
        switch(option)
        {
            case 1: //Veg Sandwich
                    computePrice(80,total);
                    break;
            case 2 :
                    computePrice(130,total);
                    break;
            case 3:
                    computePrice(100,total);
                    break;
            case 4 :
                    computePrice(80,total);
                    break;
            case 5 :
                    computePrice(90,total);
                    break;
            case 6 :
                    computePrice(110,total);
                    break;
            case 7 :
                    computePrice(120,total);
                    break;
            case 8 :
                    computePrice(140,total);
                    break;
            case 9 :
                    computePrice(70,total);
                    break;
            case 10 :
                    computePrice(80,total);
                    break;
            case 11 :
                    computePrice(130,total);
                    break;
            case 12 :
                    computePrice(160,total);
                    break;
            case 13 :
                    computePrice(70,total);
                    break;
            case 14 :
                    computePrice(60,total);
                    break;
            case 15 :
                    computePrice(40,total);
                    break;
            case 16 :
                    computePrice(50,total);
                    break;
            case 17 :
                    computePrice(30,total);
                    break;
            case 18 :
                    computePrice(40,total);
                    break;
            case 19 :
                    computePrice(160,total);
                    break;
            case 20 :
                    computePrice(150,total);
                    break;
            default : cout << "INVALID INPUT" <<endl;
        }

    }while(order == true);

    cout <<total;
    return 0;
}
