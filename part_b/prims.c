// /*

// Delete the self loops and parrallel multiple edges between same nodes keeping the min.

// Choose any arbitrary node.
// Check all the outgoing edges and chose the one with min weight.

// Check all the unused outgoing edges from the nodes that have been visited and choose the min cost path.

// */


// #include <stdio.h>
// #include <time.h>

// int a, b, u, v, n, i, j, ne = 1;

// int visited[10] = {0}, min, mincost = 0, cost[10][10];

// void main()

// {

//     double clk;
//     clock_t starttime, endtime;
//     printf("\nEnter the number of nodes:");

//     scanf("%d", &n);

//     printf("\nEnter the adjacency matrix:\n");

//     for (i = 1; i <= n; i++)

//         for (j = 1; j <= n; j++)

//         {

//             scanf("%d", &cost[i][j]);

//             if (cost[i][j] == 0)

//                 cost[i][j] = 999;
//         }

//     visited[1] = 1;

//     printf("\n");
//     starttime = clock();
//     while (ne < n)

//     {

//         for (i = 1, min = 999; i <= n; i++)

//             for (j = 1; j <= n; j++)

//                 if (cost[i][j] < min)

//                     if (visited[i] != 0)

//                     {

//                         min = cost[i][j];

//                         a = u = i;

//                         b = v = j;
//                     }

//         if (visited[u] == 0 || visited[v] == 0)

//         {

//             printf("\n Edge %d:(%d %d) cost:%d", ne++, a, b, min);

//             mincost += min;

//             visited[b] = 1;
//         }

//         cost[a][b] = cost[b][a] = 999;
//     }
//     endtime = clock();
//     clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

//     printf("\n Minimun cost=%d \n", mincost);
//     printf("%f\n", clk);
// }



#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}

int printMST(int parent[], int graph[V][V])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];
 
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1; // First node is always root of MST
 
    for (int count = 0; count < V - 1; count++) {

        int u = minKey(key, mstSet);
 
        mstSet[u] = true;

        for (int v = 0; v < V; v++)

            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
 
    printMST(parent, graph);
}
 
int main()
{

    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
 
    primMST(graph);
 
    return 0;
}