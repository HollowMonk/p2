// #include <stdio.h>
// #include <time.h>
// #include <stdlib.h>
// #define TRUE 1
// #define FALSE 0

// void heapbottomup(int h[], int n)
// {
//     int i, heap, v, j, k;
//     for (i = n / 2; i > 0; i--)
//     {
//         k = i;
//         v = h[k];
//         heap = FALSE;
//         while (!heap && (2 * k) <= n)
//         {
//             j = 2 * k;
//             if (j < n)
//                 if (h[j] < h[j + 1])
//                     j = j + 1;
//             if (v >= h[j])
//                 heap = TRUE;
//             else
//             {
//                 h[k] = h[j];
//                 k = j;
//             }
//         }
//         h[k] = v;
//     }
// }

// void heapsort(int h[], int n)
// {
//     int i, temp, last = n;
//     if (n <= 1)
//         return;
//     else
//     {
//         heapbottomup(h, n);
//         temp = h[last];
//         h[last] = h[1];
//         h[1] = temp;
//         last--;
//         heapsort(h, n - 1);
//     }
// }

// int main()
// {
//     srand(time(0));
//     int n, i;
//     double clk;
//     clock_t starttime, endtime;
//     printf("\n Enter the number of resumes\n");
//     scanf("%d", &n);
//     int h[n];
//     for (i = 1; i <= n; i++)
//     {
//         h[i] = rand() % 1000;
//     }
//     for (i = 1; i <= n; i++)
//     {
//         printf("%d\t", h[i]);
//     }
//     starttime = clock();
//     heapsort(h, n);
//     endtime = clock();
//     clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
//     printf("\n The ranks in sorted order: \n");
//     for (i = 1; i <= n; i++)
//         printf("%d\t", h[i]);
//     printf("\nThe run time is %f\n", clk);
//     return 0;
// }


#include <stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void heapify(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
 
        heapify(arr, n, largest);
    }
}
 
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
 
        heapify(arr, i, 0);
    }
}
 
/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
       printf("%d ",arr[i]);
    printf("\n");
}
 
// Driver code
int main()
{
    int arr[] = {22,1,33,2,4,1,90};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    heapSort(arr, n);
 
    printf("The sorted array is\n");
    printArray(arr, n);
}