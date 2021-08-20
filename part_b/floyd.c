/*

Dynamic Programming Approach.

Works for negative weights as well unlike dijkstra.
Will need to apply dijkstra for all n nodes.

To find the shortest distance between all pair of vertices.

Initialised to infinity for no edge.
Zero between same node.

Enter no of vertices : 4
Enter the cost matrix
0 999 3 999
2 0 999 999
999 7 0 1
6 999 999 0
All pairs shortest path matrix is:
0 10 3 4
2 0 5 6
7 7 0 1
6 16 9 0
The time taken is 0.989011

*/

#include<stdio.h>
#include <time.h>
int min(int a, int b){
    if(a<b) return a;
    else return b;
}
void copy_floyd(int n, int W[10][10], int D[10][10]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            D[i][j] = W[i][j];//Initialise distance matrix
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                D[i][j] = min(D[i][j],D[i][k]+D[k][j]);//If the node is not visited D[i][j] will be 999
            }
        }
    }
}
int main() {
    while (1) {
        printf("Enter the no of Cities: " );
        int n;
        scanf("%d", &n);
        int D[10][10], W[10][10];
        printf("Enter the distance Matrix:\n" );
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d", &W[i][j]);
            }
        }
        double clk;
        clock_t start,end;
        start = clock();
        copy_floyd(n,W,D);
        end = clock();
        printf(" shortest path from the fire station to all the residential layout in florida is :\n" );
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%d\t", D[i][j]);
            }
            printf("\n" );
        }
        clk = (double)(end-start)/CLOCKS_PER_SEC;
        printf("The runtime is %lf \n", clk);
    }
}