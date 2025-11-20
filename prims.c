#include<stdio.h>
int main()
{
 int cost[10][10];
 int visited[10]={0};
 int n,i,j,edges=0;
 int min,u=0,v=0,totalcost=0;
 printf("\nEnter no. of vertices:");
 scanf("%d",&n);
 printf("\nEnter cost adjacency matrix:");
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   scanf("%d",&cost[i][j]);
   if(cost[i][j] ==0 )
   {
    cost[i][j]== 99999;
   }
  }
 }
 visited[0]=1;
 printf("\nEdges in minimum cost spanning tree:");
 while(edges<n-1)
 {
  min=9999;
  for(i=0;i<n;i++) 
  {
   if(visited[i]==1)
   {
    for(j=0;j<n;j++)
    {
     if(visited[j]==0 && cost[i][j] < min)
     {
      min=cost[i][j];
      u=i;
      v=j;
     }
    }
   }
  }
  visited[v]=1;
  totalcost+=min;
  printf("\n Edge %d : (%d -> %d ) cost= %d\n",edges+1,u+1,v+1,min);
  edges++;
 }
 printf("\n Minimum cost=%d ",totalcost);
 return 0;
}
 
 
