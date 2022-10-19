#include<bits/stdc++.h>

using namespace std;
//class created because we want to sort input on the basis of edges
class edges
{
    public:
    int srcv;
    int destn;
    int weight;
};

//custom compare function
bool compare(edges e1,edges e2)
{
    return e1.weight<e2.weight;
}

//to get the topmost parent
int getparent(int ver,int* parent)
{
    if(ver == parent[ver])
    {
        return ver;
    }

    getparent(parent[ver],parent);
}

void kruskal(edges* input,int e,int v,edges* output)
{
    sort(input,input+e,compare);
    //MAKING A parent array to for every vertices
    int parent[v];
    for(int i=0;i<v;i++)
    {
        parent[i]=i;
    }

    int count=0;
    int i=0;
    while(count<(v-1))
    {
        edges currentedge=input[i];

        int srcparent= getparent(currentedge.srcv,parent);//getting source parent;
        int destnparent = getparent(currentedge.destn,parent);//getting destination parent
        //if the parent are different then they are different connected components
        if(srcparent!=destnparent)
        {
            output[count]=currentedge;
            count++;
            parent[srcparent]=destnparent;//making topmost parent same
        }
        i++;
    }

}


int main()
{
    int v,e;
    cin >>v >>e;
    edges input[e];//creating array of objects
    //taking input;
    for(int i=0;i<e;i++)
    {
        int s,d,w;
        cin >>s>>d>>w;
        input[i].srcv=s;
        input[i].destn=d;
        input[i].weight=w;
    }

    edges output[v-1];//output array of size vertcies-1;
    kruskal(input,e,v,output);

    for(int i=0;i<v-1;i++)
    {
        //printing output;
        if(output[i].srcv<output[i].destn)
        {
            cout<<output[i].srcv<<" "<<output[i].destn<<" "<<output[i].weight<<endl;
        }
        else{
            cout <<output[i].destn<<" "<<output[i].srcv<<" "<<output[i].weight<<endl;
        }

    }

    return 0;
}
