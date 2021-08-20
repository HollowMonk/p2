/*BFS*/

#include<stdio.h>
#include<time.h>
void bfs(int a[20][20],int n,int source,int t[20][20],int visited[])
{
    int f,r,q[20];
    int u,v,i;
    int k=0;
    for(i=0;i<n;i++)
    visited[i]=0;
    f=r=k=0;
    q[r]=source;
    visited[source]=1;
    while(f<=r)
    {
        u=q[f++];
        for(v=1;v<n;v++)
        {
            if(a[u][v]==1 && visited[v]==0)
            {
                visited[v]=1;
                q[++r]=v;
                t[k][0]=u;
                t[k][1]=v;
                k++;
            }
        }
    }
}
int main()
{
    int a[20][20];
    int source,t[20][20],visited[20],i,j,n,flag;
    double clk;
    clock_t starttime,endtime;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
    printf("Enter the source\n");
    scanf("%d",&source);
    starttime=clock();
    bfs(a,n,source,t,visited);
    endtime=clock();
    clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;

    printf("\nThe run time is %f\n",clk);
    flag=0;
    for(i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            printf("Vertex %d is not reachable\n",i);
            flag=1;
        }
        else
        printf("%d is reachable\n",i);
    }
    if(flag==1)
    printf("Some nodes are reachable\n");
    printf("\nThe BFS traversal is \n");
    for(i=0;i<n;i++)
    printf("%d-->%d\n",t[i][0],t[i][1]);
}

