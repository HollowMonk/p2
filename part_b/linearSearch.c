#include <stdio.h>
#include<stdlib.h>
#include<time.h>
 
int main()
{  int num;
    
 
    int i,  keynum, found = 0;
 
    printf("Enter the number of elements ");
    scanf("%d", &num);
    int array[num];

    for (i = 0; i < num; i++)
    {
        array[i] = rand()%1000;
    }

    for (i = 0; i < num; i++)
    {
        printf("%d ",array[i]);
    }
 
    printf("\nEnter the element to be searched\n ");
    scanf("%d", &keynum);
  
    clock_t t;
    t = clock();

    for (i = 0; i < num ; i++)
    {
        if (keynum == array[i] )
        {
            found = 1;
            break;
        }
    }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; 
  
    printf(" %f seconds to execute \n", time_taken);

    if (found == 1)
        printf("\nElement is present in the array at position %d\n",i+1);
    else
        printf("\nElement is not present in the array\n");
    
   
      return 0;
}