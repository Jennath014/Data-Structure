#include<stdio.h>

#define MAX 10

int visit[MAX];
int adj[MAX][MAX];
int q[MAX];
int f=0,r=0;
int n;

void enqueue(int v)
{
  q[r++]= v;
}

int dequeue()
{
   return q[f++];
}


//bfs function
void bfs(int v)
{
  visit[v]= 1;
  enqueue(v);
  
  while(f != r) // queue not empty
  {
   int vertex = dequeue();
   printf("%d",vertex);
   	
   for(int i=0;i<n;i++)
   {
    if(adj[vertex][i]==1 && !visit[i])
    {
     visit[i]=1;
     enqueue(i);
   	 }
   	}
   }
}

   	


// main function
int main()
{
 int e,u,v,start;
 printf("Enter no. of vertices:");
 scanf("%d",&n);
 
 for(int i=0;i<n;i++)
 {	
 	visit[i]=0;
 	for(int j=0;j<n;j++)
 	{
 		adj[i][j]=0;
 	}
 }
 
 printf("Enter no . of edges:");
 scanf("%d",&e);
 
 printf("Enter edges:");
 for(int i=0;i<e;i++)
 {
 	scanf("%d %d",&u, &v);
 	adj[u][v]=1;
 	adj[v][u]=1;
 }
 	
 printf("Enter starting vertex:");
 scanf("%d", & start);
 
 printf("BFS starting from vertex %d:", start);
 bfs(start);
 
 return 0;
}
