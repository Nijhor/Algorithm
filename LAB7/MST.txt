#include<iostream>

using namespace std;
#define V 5

int minkey(int key[], bool mstset[])
{
    int min = 9999, min_index;

    for (int v = 0; v < V; v++) {
        if (mstset[v] == false && key[v] < min) {

            min = key[v];
			min_index = v;
        }
    }
    return min_index;
}


int printmst(int parent[], int graph[V][V])
{
    int mincost=0;
	cout<<"Edge \tWeight\n";
    for (int i = 1; i< V; i++) {
		cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
		mincost+=graph[i][parent[i]];
    }
	cout<<"Total cost is"<<mincost;
}


void mst(int graph[V][V])
{
    int parent[V], key[V];
    bool mstset[V];


    for (int i = 0; i< V; i++) {
        key[i] = 9999;
        mstset[i] = false;
        parent[i]=-1;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int x = 0; x < V - 1; x++)
    {

        int u = minkey(key, mstset);

        mstset[u] = true;


        for (int v = 0; v < V; v++)
        {

            if (graph[u][v]!=0 && mstset[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }


	printmst(parent, graph);
}


int main()
{
    int graph[V][V];
	cout<<"Enter the 5 verticed graph";
    for (int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
			cin>>graph[i][j];
        }
    }
	mst(graph);

    return 0;
}
