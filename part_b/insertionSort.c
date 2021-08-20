//Insertion Sort

#include <math.h>
#include<time.h>
#include<stdlib.h>
#include <stdio.h>
 
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 

int main()
{
    int n,i;
    double clk;
    clock_t starttime,endtime;

    printf("Enter the number of elements in array\n");
    scanf("%d",&n);

    int arr[n];

    for(i=0;i<n;i++)
        arr[i] = rand()%1000;

    printf("\nThe new array is: \n");

    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
 
    starttime=clock();

    insertionSort(arr, n);

    endtime=clock();

    printf("\n\nSorted array is: \n\n");

    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
        
    clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
	
    printf("\n\nThe run time is %f seconds\n",clk);
  
 
    return 0;
}

