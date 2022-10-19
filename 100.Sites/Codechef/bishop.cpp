#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> arr;
vector <int> brr;

void bishopmoves(int **chess,int &moves,int i,int j)
{
    while(i<8 && j<8)
    {
        moves+=1;
        //cout <<"test" <<" " <<i+1 <<" " <<j+1<<endl;
        arr.push_back(i);
        brr.push_back(j);
        if((i-1)>= 0 && (j+1)<=7)//checking left present
        {
            int tempi=i;//copy value
            int tempj=j;
            int curri=tempi-1;
            int currj= tempj+1;
            while((tempi-1)>=0 && (tempj+1)<=7)
            {
                tempi--;
                tempj++;
                curri=tempi;
                currj=tempj;
            }
            //cout <<"test" <<" " <<curri+1 <<" " <<currj+1<<endl;
            arr.push_back(curri);
            brr.push_back(currj);
            moves+=1;
        }

        if((i+1)<=7 && (j-1)>=0)//checking another diagonal present
        {
            int tempi=i;
            int tempj=j;
            int curri=i+1;
            int currj=j-1;
            while((tempi+1)<=7 && (tempj-1)>=0)
            {
                tempi++;
                tempj--;
                curri=tempi;
                currj=tempj;
            }
            //cout <<"test" <<" " <<curri+1 <<" " <<currj+1<<endl;
            arr.push_back(curri);
            brr.push_back(currj);
            moves+=2;
            //cout <<"test" <<" " <<i+1<< " " <<j+1<<endl;
            arr.push_back(i);
            brr.push_back(j);
        }
        i++;
        j++;
    }
    //printing output
    cout <<moves-1<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cout << arr[i]+1 <<" "<<brr[i]+1 << endl;
    }
}

void bishopmoves2(int **chess,int &moves,int i,int j)
{
   // cout <<"m"<<moves<<endl;
    moves+=26;
    int tempa[26]={0,1,0,2,1,2,0,4,2,3,0,6,3,4,1,7,4,5,3,7,5,6,5,7,6,7};
    int tempb[26]={7,6,5,7,6,5,3,7,5,4,1,7,4,3,0,6,3,2,0,4,2,1,0,2,1,0};

    for(int i=0;i<26;i++)
    {
        arr.push_back(tempa[i]);
        brr.push_back(tempb[i]);
    }
    cout << moves-1 <<endl;

    for(int i=0;i<arr.size();i++)
    {
        cout << arr[i]+1 << " " << brr[i]+1 <<endl;
    }
}

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int **chess = new int*[8];
        for(int i=0;i<8;i++)
        {
            chess[i]=new int[8];
            for(int j=0;j<8;j++)
            {
                chess[i][j]=0;
            }
        }

        int row,col,k;
        cin >> row >> col;
        if((row+col)%2==0)
        {
            k=0;
        }
        else
        {
            k=1;
        }
        for(int i=0;i<8;i+=2)
        {
            int j=k;
            for(;j<8;j+=2)
            {
                chess[i][j]=1;
            }
        }
        int j;
        for(int i=1;i<8;i+=2)
        {
            if(k==0){j=1;}else{j=0;}
            for(;j<8;j+=2)
            {
                chess[i][j]=1;
            }
        }

      /*  for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                cout << chess[i][j]<< " ";
            }
            cout <<endl;
        }*/
        int moves=0;
        if(chess[0][0]==1)
        {
            int i=row-1;
            int j=col-1;
            if(i>=j)
            {
                if(i!=j)
                {
                    while(i!=j)
                    {
                        i--;
                        j++;
                    }
                    arr.push_back(i);
                    brr.push_back(j);
                    moves+=1;
                }
                if(i!=0 && j!=0)
                {
                    moves+=1;
                }
            }
            else
            {
                while(i!=j)
                {
                    i++;
                    j--;
                }
                arr.push_back(i);
                brr.push_back(j);
                moves+=1;
                if(i!=0 && j!=0)
                {
                    moves+=1;
                }
            }

            bishopmoves(chess,moves,0,0);
        }
        else
        {
            if((row+col)<=9)
            {
                if(row+col!=9)
                {
                    while((row+col)!=9)
                    {
                        row++;
                        col++;
                    }
                    arr.push_back(row-1);
                    brr.push_back(col-1);
                    moves+=1;
                }
                if(row!=1 && col!=8)
                {
                    moves+=1;
                }
            }
            else
            {
                while((row+col)!=9)
                {
                    row--;
                    col--;
                }
                arr.push_back(row-1);
                brr.push_back(col-1);
                moves+=1;
                if(row!=1 && col!=8)
                {
                    moves+=1;
                }
            }
            bishopmoves2(chess,moves,0,7);
        }
    }

    return 0;
}
