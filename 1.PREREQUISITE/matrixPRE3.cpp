#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int A[n][n];
    int row,col;
    for(row=0;row<n;row++)
    {
        for(col=0;col<n;col++)
        {
            cin >> A[row][col];
        }
    }
    int sum=0,diagonalsum=0;
    for(row=0;row<n;row++)
    {
        for(col=0;col<n;col++)
        {

            if(row==0 && col==(n-1))
            {
                diagonalsum = row +col;
                cout <<row<<col << " "<<diagonalsum;
            }
            if(row==0 || col==0 || row==(n-1) || col==(n-1) || (row==col) || diagonalsum==(row+col))
            {

                sum+=A[row][col];
                cout << row << col << " " <<sum <<endl;
            }
        }
    }
    cout << sum ;

	return 0;
}
