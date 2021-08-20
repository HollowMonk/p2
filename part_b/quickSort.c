#include <stdio.h>
#include<stdlib.h>
#include<time.h>


void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}


int partition(int array[], int low, int high) {
  

  int pivot = array[high];
  

  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        

      i++;
    
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    int pi = partition(array, low, high);
    
    quickSort(array, low, pi - 1);
    
    quickSort(array, pi + 1, high);
  }
}


int main() {
  int n,i;

  printf("Enter the no of elements\n");
  scanf("%d",&n);

  int data[n];

  for(i=0;i<n;i++)
    data[i] = rand()%100;
  
  printf("The data is :\n\n");
  for(i=0;i<n;i++)
    printf("%d ",data[i]);

clock_t t;
    t = clock(); //Clocking starts
  
  quickSort(data, 0, n - 1);

t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

   printf("Sorted array in ascending order: \n\n");
  for(i=0;i<n;i++)
    printf("%d ",data[i]);

 printf("\n\nProgram took %f seconds to execute \n", time_taken);
  
  return 0;
}