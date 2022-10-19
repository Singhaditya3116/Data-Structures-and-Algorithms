#include <iostream>
using namespace std;

class Input
{
    public:
    int v1;
    int v2;
    int weight;
};


int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

 Input arr[E];
for(int i=0;i<E;i++)
{
    cin >> arr[i].v1;
    cin >> arr[i].v2;
    cin >> arr[i].weight;

}

for(int i=0;i<E;i++)
{
    cout << arr[i].v1;
    cout <<arr[i].v2;
    cout <<arr[i].weight <<endl;

}


  return 0;
}
