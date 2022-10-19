
#include<iostream>
#include<algorithm>
using namespace std;

class Edges{
public:
	int v1;
	int v2;
    int weight;
};

bool compare(Edges e1,Edges e2)
{
    return e1.weight < e2.weight;
}

int getParent(int *parent,int vertex)
{
    if(parent[vertex]==vertex)
    {
        return vertex;
    }
    return getParent(parent,parent[vertex]);
}


void kruskal(Edges *arr,int vertices,int edge,Edges *output,int *parent)
{
    int count=0;
    sort(arr,arr+edge,compare);
    int i=0;
    while(count < (vertices-1))
    {
        int srcVertex = arr[i].v1;
        int destnVertex = arr[i].v2;
        int cost = arr[i].weight;

        int srcParent=getParent(parent,srcVertex);
        int destnParent =getParent(parent,destnVertex);

        if(srcParent != destnParent)
        {
            output[count]=arr[i];
            parent[srcParent]=destnParent;
            count++;
        }
        i++;
    }
}

int main()
{
    int v,e;
    cin >> v >>e;
    Edges arr[e];
    for(int i=0;i<e;i++)
    {
        int vertex1,vertex2,cost;
        cin >> vertex1 >> vertex2 >> cost;
        arr[i].v1=vertex1;
        arr[i].v2=vertex2;
        arr[i].weight=cost;
    }
    Edges *output=new Edges[v-1];
    int *parent =new int[v];
    for(int i=0;i<v;i++)
    {
        parent[i]=i;
    }
    kruskal(arr,v,e,output,parent);
    for(int i=0;i<v-1;i++)
    {
        if(output[i].v1 < output[i].v2)
        {
        	cout << output[i].v1 << " " <<output[i].v2<<" "<<output[i].weight <<endl;
        }
        else
        {
            cout << output[i].v2 << " " <<output[i].v1<<" "<<output[i].weight <<endl;
        }
    }

}
