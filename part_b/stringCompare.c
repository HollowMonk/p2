////String compare

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int len(char a[])
{
    int i=0;
    while(a[i] != '\0')
        i++;
    
    return i;
}

  
int compare(char a[],char b[])  
{  
    int flag=0,i=0; 

    int len1 = len(a),len2 = len(b);
    if(len1 != len2)
    {
        return -1;
    }
    while(a[i]!='\0' &&b[i]!='\0') 
    {  
       if(a[i]!=b[i])  
       {  
           flag=1;  
           break;  
       }  
       i++;  
    }  
    if(flag==0)  
        return 0;  
    else  
        return 1;  
} 

int main()  
{ 
    double clk;
    clock_t starttime,endtime;
   char str1[1000];   
   char str2[1000];   
   printf("Enter the first string : ");  
   scanf("%s",str1);  
   printf("Enter the second string : ");  
   scanf("%s",str2);

   starttime=clock();  
   int c= compare(str1,str2);  
   endtime=clock();

   if(c==0)  
   printf("\nstrings are same\n");  
   else  
   printf("\nstrings are not same\n"); 

    clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
	
    printf("\n\nThe run time is %f seconds\n",clk); 
  
    return 0;  
}  
  
 
