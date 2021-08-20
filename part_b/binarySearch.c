#include <stdio.h>
#include<stdlib.h>
#include<time.h>
 
int binarySearch(long arr[], int l, int r, long x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;
 
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }
 
    return -1;
}

void swap(long *xp, long *yp)
{
    long temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 

void bubbleSort(long arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)     
 
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
 
int main(void)
{
    int n,i;
    long x;
    double clk;
    clock_t starttime,endtime;

    printf("Enter the number of elements\n");
    scanf("%d",&n);
    long arr[n];

    for(i=0;i<n;i++)
        arr[i] = rand()%100000;

    bubbleSort(arr,n);

    printf("The sorted array is: \n");

    for(i=0;i<n;i++)
        printf("%ld ",arr[i]);

    printf("\nEnter the element to search\n");
    scanf("%ld",&x);

    starttime=clock();

    int result = binarySearch(arr, 0, n - 1, x);

    endtime=clock();

    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d",
                            result);

    clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
	
    printf("\n\nThe run time is %f seconds\n",clk);
    return 0;
}