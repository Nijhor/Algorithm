#include<bits/stdc++.h>
using namespace std;
int n,e;
vector <int> adj[100005];
int dis[100005];
int mx,val;

queue<int> q;
void bfs(int s)
{
    for(int i=0;i<=n;i++)
    {
        dis[i]=-1;
    }
    dis[s]=0;
    q.push(s);
    int x,y;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(int i=0; i<adj[x].size();i++)
        {
            y=adj[x][i];
            if(dis[y]==-1)
            {
                q.push(y);
               dis[y]=dis[x]+1;

            }
        }
    }

}

int main()
{
    int x,y,s=1,mx=0;
    scanf("%d %d",&n,&e);
    for(int i=0;i<e;i++)
    {
       scanf("%d %d",&x,&y);
       adj[x].push_back(y);
       adj[y].push_back(x);
    }

    bfs(s);
    for(int i=0;i<=n;i++)
    {
        val=max(dis[i],dis[i+1]);
        if(mx<val)mx=val;
    }
    printf("%d\n",mx);
    return 0;
}
