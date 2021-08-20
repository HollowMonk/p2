/*

A[0] is the adjacency matrix.

by finding the transitive relations we can make A[1] .... A[n-1] for graph of size n.

Initially a[i][j] = 0;

But if and edge exists between i -> j then a[i][j] = 1.

and if for A[0]: a[i][k] = 1 and a[k][j] = 1. 
Then for A[1]: a[i][j] = 1. 

*/


#include <stdio.h>
#include <time.h>

void warshal(int p[10][10], int n)
{
    int i, j, k;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                p[i][j] = p[i][j] || (p[i][k] && p[k][j]);
}
int main()
{
    double clk;
    clock_t starttime, endtime;

    int p[10][10] = {0},n, e, u, v, i, j;
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &p[i][j]);
        }
    printf("Matrix of input data: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d\t", p[i][j]);
        printf("\n");
    }
    starttime = clock();

    warshal(p, n);
    endtime = clock();
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("Transitive closure of given input matrix is : \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d\t", p[i][j]);
        printf("\n");
    }
    printf("\nTime of execution = %f", clk);
    return 0;
}