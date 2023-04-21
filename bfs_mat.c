//Chapter:04:Balanced Trees BFS

#include<stdio.h>
#define max 10

void ReadGraph(int a[max][max],int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
}
void bfs(int a[max][max],int n,int visited[max],int src)
{
	int q[n],i;
	int f=0,r=-1;
	q[++r]=src;
	visited[src]=1;
	int v;
	while(f<=r)
	{
		v=q[f++];
		printf("%d ",v);
		for(i=0;i<n;i++)
		{
			if(a[v][i] && visited[i]==0)
			{
				q[++r]=i;
				visited[i]=1;
			}			
		}
	}	
}
int main()
{
	int a[max][max],n,visited[max],src,count=0,i;
	printf("enter the no. of nodes:");
	scanf("%d",&n);
	printf("enter the values to read matrix:\n");
	ReadGraph(a,n);
	printf("enter the source");
	scanf("%d",&src);
	for(i=0;i<n;i++)
		visited[i]=0;
	printf("bfs traversal:\n");
	bfs(a,n,visited,src);
	printf("\nreachable nodes are:");
	for(i=0;i<n;i++)
	{
		if(visited[i])
		printf("%d",i);
		count=count+1;
	}
	if(count==n)
	printf("\nconnected\n");
	else
	printf("\ndisconnected\n");
	return 0;
}