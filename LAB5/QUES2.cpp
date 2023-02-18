#include<bits/stdc++.h>
#include <iostream>
#include <list>
#include <stack>
using namespace std;
  int cnt=0;
class Graph
{
    int V;
    list<int> *adj;


    void fillorder(int v, bool visited[], stack<int> &Stack);


    void dfsutil(int v, bool visited[]);
public:
    Graph(int V);
    void addedge(int v, int w);


    void printscc();


    Graph getTranspose();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}


void Graph::dfsutil(int v, bool visited[])
{

    visited[v] = true;



    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            dfsutil(*i, visited);
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {

        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::addedge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::fillorder(int v, bool visited[], stack<int> &Stack)
{

    visited[v] = true;

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            fillorder(*i, visited, Stack);

    Stack.push(v);
}


void Graph::printscc()
{
    stack<int> Stack;


    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;


    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            fillorder(i, visited, Stack);


    Graph gr = getTranspose();


    for(int i = 0; i < V; i++)
        visited[i] = false;


    while (Stack.empty() == false)
    {

        int v = Stack.top();
        Stack.pop();


        if (visited[v] == false)
        {
            gr.dfsutil(v, visited);
              cnt++;

        }
    }
}


int main()
{

 int n,e;

 cin >> n >> e;

    Graph g(n+1);


       for(int i=0; i<e; i++)
    {
        int u, v;
        cin >> u >> v;
             g.addedge(u, v);

    }

    g.printscc();
    cout<<cnt-1;

    return 0;
}
