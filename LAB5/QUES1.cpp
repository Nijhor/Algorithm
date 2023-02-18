#include<bits/stdc++.h>
#define WHITE 1
#define GREY 2
#define BlACK 3
using namespace std;


vector <int> adj[100009];
int col[100009];
bool iscycle;
bool isdirect;
void dfs(int nd)
{
    col[nd]=GREY;
    for(int i =0; i<adj[nd].size(); i++)
    {
        int v= adj[nd][i];
		if(col[v]==WHITE)dfs(v);
        if(col[v]==GREY)iscycle= true;

    }
    col[nd]= BlACK;

}

int main()
{
int n,e;
    scanf("%d %d", &n, &e);

    for(int i=0; i<e; i++)
    {
        int u, v;
        cin >> u >> v;
		adj[u].push_back(v);
    }

for (int i =1;i<=n;i++)
    {
	    col[i]= WHITE;
    }

	for (int i =1;i<=n;i++)
        {
	        if(col[i]==WHITE)dfs(i);
        }

 if(iscycle) cout<<"no"<<endl;
else
	cout<<"yes"<<endl;


}
