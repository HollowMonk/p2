// GCD and LCM by consecutive integer method

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int lcm(int n1,int n2)
{

    int max = (n1 > n2) ? n1 : n2;

    while (1) {
        if (max % n1 == 0 && max % n2 == 0) {
            break;
        }
        ++max;
    }

    return max;
}

int gcd(int n1,int n2)
{

    int min = (n1 < n2) ? n1 : n2;
    int i;

    for(i=min;i>=1;i--)
    {
        if((n1 % i == 0) && (n2 % i == 0))
        {
            break;
        }
    }

    return i;

}

void main()
{

    int a = rand()%1000; ////4 bytes
    int b = rand()%1000; ////4 bytes

    clock_t t;
    t = clock(); //Clocking starts

    printf("\n\nThe LCM is: %d\nThe GCD is: %d\n\n",lcm(a,b),gcd(a,b));

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("Program took %f seconds to execute \n", time_taken);

}
