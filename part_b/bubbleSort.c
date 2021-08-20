#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b)
{
    int c;
    c = *b;
    *b = *a;
    *a = c;
}

void bubble_sort(int *ar,int size)
{
    int i,j;

    for(i=0;i<size-1;i++)
        {
            for(j=0;j<size-i-1;j++)/* (size)(size-1)/2 times the loop executes worst case O(size^2) and best case O(size) ie sorted already */
            {
                if(ar[j]>ar[j+1])
                    swap(&ar[j],&ar[j+1]);
            }
        }
}

int main()
{
    int n,i,j;

    printf("Enter the size of array: \n");
    scanf("%d",&n);

    int ar[n];

    for(i=0;i<n;i++)
        ar[i] = rand()%1000;

    printf("The array is :-\n\n");

    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
    
    clock_t t;
    t = clock(); //Clocking starts
    
    bubble_sort(ar,n);

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("\n\nThe sorted array is:-\n\n");

    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
  
    printf("\n\nProgram took %f seconds to execute \n", time_taken);
    long long loops = (n*(n-1))/2;
    printf("Loops executed: %lld\n",loops);



}