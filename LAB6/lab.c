#include<stdio.h>
#define infinity 999
#define MAX 100
void dijkstra (int n, int start);
int G[MAX][MAX];
int main()
{
    int G[MAX][MAX],i,j,u,n;
    scanf("%d",&n);
    for (i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&G[i][j]);
    scanf("%d",&u);
    dijkstra(n,u);
    return 0;
}
void dijkstra(int n, int start)
{
        int distance[MAX], pre[MAX];
        int visited [MAX]={0},count, mindistance, next,i,j;
        for (i=0;i<n;i++)
        {
            pre[i]=start;
            distance[i]=G[start][i];
        }
        distance[start]=0;
        visited[start]=1;
        count=1;
        while (count<n-1)
        {
            mindistance=infinity;
            for (i=0;i<n;i++)
            {
                if (distance[i]<mindistance&&visited[i]==0 )
                {
                    mindistance=distance[i];
                    next=i;
                }
            }
            visited[next]=1;
            for(i=0; i<n;i++)
                if(!visited[i]==0)
            {
                if(mindistance+G[next][i]<distance[i])
                {
                    distance[i]=mindistance+G[next][i];
                    pre[i]=next;
                }
            }
            count++;
        }
        for(i=0;i<n;i++)
        {
            if(i!=start)
            {
                printf("\ndistance of node %c = %c",i+65,distance[i]+65);
                printf("\npath=%c",i+65);
                j=i;
                do{
                        j=pre[j];
                        printf("<-%c",j+65);
                    }
                    while(j!=start);
            }
        }
}
