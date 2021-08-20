// Unique arry elements brute force

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{

    int n,i,j;   ////Space 3*4 bytes
    printf("Enter the elements in the array\n");
    scanf("%d",&n);

    int a[n];    ////Space n*4 bytes



    for (i = 0; i < n; i++)
    {
        a[i] = rand()%1000;
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }

        clock_t t;
  t = clock(); //Clocking starts

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i] == a[j])
            {
                printf("\n\nDuplicates found for %d at %d\n .....Exiting....\n\n",i+1,j+1);
                goto exit;
            }
        }
    }

    printf("\n\nNo Duplicates\n\n");

    exit:
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("Program took %f seconds to execute \n", time_taken);


}
