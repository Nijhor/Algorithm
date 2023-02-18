#include<bits/stdc++.h>
using namespace std;
int n,e;

vector <int> adj[100005];
int color[200005];
int  c=0, d=0;
queue<int> q;

int isBicolorable=1;

void bfs(int src){
for (int i=1;i<=n;i++){
    color[i]=2;
}
color[src]=0;
c+=200;
d+=500;

q.push(src);
int u,v;
while(!q.empty()){
    u=q.front();
    q.pop();
    for(int i=0;i<adj[u].size();i++){
        v=adj[u][i];
        if(color[v]==2){
            if(color[u]==1)
                {
                    color[v]=0;
                c+=200;
                d+=500;

                }
            else
                {
                    color[v]=1;
                c+=500;
                d+=200;

                }
            q.push(v);

        }
        else {

            if(color[u]==color[v]){
                isBicolorable=0;
             }
         }
        }
    }

    if(d>c){
        cout<< c <<endl;
    }
    else cout<< d <<endl;
}

int main(){
    scanf("%d %d", &n, &e);
    int u, v;

    for(int i=0; i<e; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src=1;
    bfs(src);

    return 0;
}
