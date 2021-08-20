// /*

// Single Source shortest path:

// Find the min cost path from curent node to the next 
// and add that to the cost of current node to find 
// the next node cost.
// When all nodes have been traversed the min distance from starting node to all others is known.
//Select smallest vertex

// Initially the distance is initialised to infinity (999).

// For directed and undirected.

// Nodes: 5

// 999 4 2 999 8
// 999 999 999 4 5
// 999 999 999 1 999
// 999 999 999 999 3
// 999 999 999 999 999

// Shortest distance
// 1 to 1 = 0
// 1 to 2 = 4
// 1 to 3 = 2
// 1 to 4 = 3
// 1 to 5 = 6
// The time taken is 0.456643

// */
// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph

#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

#define V 9

int minDistance(int dist[], bool vis[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (vis[v] == false && dist[v] <= min)//If the node is smallest an not visited
			min = dist[v], min_index = v;

	return min_index;
}

void printSolution(int dist[])
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	bool vis[V]; 
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, vis[i] = false;

	dist[src] = 0;

	for (int count = 0; count < V - 1; count++) {//V-1 since source node is excluded

		int u = minDistance(dist, vis);//get index of closest node
		vis[u] = true;//visit it
		for (int v = 0; v < V; v++)
			if (!vis[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])//check distance of current node to all other unvisited nodes
				dist[v] = dist[u] + graph[u][v];
	}

	printSolution(dist);
}

int main()
{
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	dijkstra(graph, 0);

	return 0;
}
