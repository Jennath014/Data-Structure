#include<stdio.h>
#include<stdlib.h>
#define N 8

void readset(int s[])
{
 int m,x;
 printf("\nEnter number of elements:");
 scanf("%d",&m);
 printf("Enter elements (0-%d):",N-1);
 for(int i=0;i<m;i++)
 {
  scanf("%d",&x);
  if(x>=0 && x<N)
  {
   s[x]=1;
  }
 }
}

void print(int s[])
{
 printf("\n {");
 for(int i=0;i<N;i++)
 {
  if(s[i]==1)
  {
   printf("%d",i);
  }
 }
 printf("}");
 printf("\n bit string:");
 for(int i=0;i<N;i++)
 {
  printf("%d",s[i]);
 }
}

void Union(int a[],int b[],int result[])
{
 for(int i=0;i<N;i++)
 {
   result[i]=a[i] || b[i];
  }
}

void Intersection(int a[],int b[],int result[])
{
 for(int i=0;i<N;i++)
 {
   result[i]=a[i] && b[i];
  }
}

void Difference(int a[],int b[],int result[])
{
 for(int i=0;i<N;i++)
 {
   result[i]=a[i] &&  !b[i];
  }
}


int main()
{
 int a[N]={0},b[N]={0},result[N];
 int c;
 printf("\n set A:");
 readset(a);
 printf("\n set B:");
 readset(b); 
 printf("Set operations:\n 1. Display \n 2. Union \n 3. Intersection \n 4. Difference \n 5. Exit");
 while(1)
 {
  printf("Choice:");
  scanf("%d",&c);
  
  switch(c)
  {
    case 1: 	printf("Set A:");
    		print(a);
    		printf("Set b:");
    		print(b);
    		break;
    		
    case 2:	printf("AuB=");
    		Union(a,b,result);
    		print(result);
    		break;
    		
    case 3:	printf("AnB=");
    		Intersection(a,b,result);
    		print(result);
    		break;
    		
    case 4:	printf("A-B=");
    		Difference(a,b,result);
    		print(result);
    		break;
    		
    case 5:	printf("Exiting");
    		exit(0);
    	
    default:	printf("invalid choice");
  }
 }
 return 0;
}
