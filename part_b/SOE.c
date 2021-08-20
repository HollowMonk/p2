
// Generate prime no using Sieve of E....

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
int main()
{
	int n = rand()%1000;    //// 4 bytes

	int prime[n+1];     ////   4*(n+1) bytes

	for(int i = 1; i <= n; i++)
	{
		prime[i] = i;
	}

    clock_t t;
    t = clock(); //Clocking starts

	for(int i = 2; i*i <= n; i++)
	{
		if(prime[i] != -1)
		{
			
			for(int j = 2*i; j <=n ; j += i)
				prime[j] = -1;
		}
	}

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("Program took %f seconds to execute \n", time_taken);

	printf("Prime numbers till %d are: \n",n);
	for(int i=2; i <= n; i++)
	{
		if(prime[i] != -1)
		{
			printf("%d ", i);
		}
	}
}
