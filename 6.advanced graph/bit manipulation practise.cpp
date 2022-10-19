#include <iostream>
using namespace std;

int turnOffFirstSetBit(int n){
        int  count=0;
    int temp=n;
    while(n>0)
    {

         temp=n&1;
        if(temp)
        {
            break;
        }
        count++;
        n=n>>1;
    }

    int turnoff=~(1<<count);
    cout<<turnoff;
    n=n&turnoff;
    return n;
}
int main() {
	int n;

	cin >> n;

	cout<<turnOffFirstSetBit(n) <<endl;

	return 0;
}




