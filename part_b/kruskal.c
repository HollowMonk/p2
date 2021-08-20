/*

Delete the self loops and parrallel multiple edges between same nodes keeping the min.

List all costs in ascending order and start making tree ensuring no cycles are formed.

*/

#include<stdio.h>
#include<stdlib.h>

int i,j,k,a,b,u,v,n,ne=1;

int min,mincost=0,cost[9][9],parent[9];

int find(int i)
{
	while(parent[i])//parent not 0
		i=parent[i];//keep moving to parent

	return i;//return parent
}

int uni(int i,int j)//send parents
{
	if(i!=j)//if the parent is not same
	{
		parent[j]=i;//set parent of j as i	
			return 1;
	}
	return 0;
}

int main()
{
	printf("\n\tImplementation of Kruskal's algorithm\n");
	printf("\nEnter the no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter the cost adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	printf("The edges of Minimum Cost Spanning Tree are\n");
	while(ne < n)//no of edges < no of vertices
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))//if the parents are same then a cycle is formed and -0 is returned
		{
			printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
			mincost +=min;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n\tMinimum cost = %d\n",mincost);
	return 0;
}
