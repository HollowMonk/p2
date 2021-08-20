#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    double clk;
    clock_t starttime, endtime;
    int s[20], x[20], n, sum, i, tot, soln = 0;
    long int a;

    printf("\nEnter the value of n ");
    scanf("%d", &n);
    printf("\nEnter the values ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }
    printf("\nEnter the total sum ");
    scanf("%d", &tot);
    printf("\nSolution to the problem is ");
    starttime = clock();
    for (a = 0; a < pow(2, n); a = a + 1)//2 since a value may or may not be involved
    {
        sum = 0;
        for (i = 0; i < n; i++)
        {
            if ((a & (int)pow(2, i)) != 0)
            {
                x[i] = 1;//Number used array
                sum = sum + s[i];
            }
            else
            {
                x[i] = 0;//Number at ith position not used
            }
        }
        //Loop end
        if (sum == tot)//sum equal to required sum
        {
            soln = soln + 1;//increment the no of solutions
            printf("\n");
            for (i = 0; i < n; i++)
            {
                if (x[i] == 1)//If number at ith index is used 
                {
                    printf("%d ", s[i]);
                }
            }
        }
        //backTrack
    }
    endtime = clock();
    if (soln == 0)
    {
        printf("is not possible!!");
    }
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("The time taken is %f\n", clk);
}