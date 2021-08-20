//Matrix addition
//April 15

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i,j,k; ////Space 3*4 bytes

    printf("Enter matrix size\n");
    scanf("%d",&k);

    int a[k][k],b[k][k]; ////Space taken 8*k^2 bytes 


    for(i=0;i<k;i++)
        for(j=0;j<k;j++)
        {
            a[i][j] = rand()%100;
            b[i][j] = rand()%100;
        }

    printf("\n\nMatrix a is: \n\n");

    for(i=0;i<k;i++)
        {
            for(j=0;j<k;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
        }

        printf("\n\nMatrix b is: \n\n");

    for(i=0;i<k;i++)
        {
            for(j=0;j<k;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
        }

        printf("\n\nSum of Matrix a and b is: \n\n");

    clock_t t;
    t = clock(); //Clocking starts


    for(i=0;i<k;i++)    //k^k
        {
            for(j=0;j<k;j++)
        {
            printf("%d ",a[i][j]+b[i][j]);
        }
        printf("\n");
        }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("Program took %f seconds to execute \n", time_taken);
    int size = 8*k*k+12;
    printf("%d bytes ",size);

    return 0;
}



