#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
void bfs(int n,int s,int vis[],int arr[][SIZE]);
int main(){
int arr[SIZE][SIZE],n,vis[SIZE],s,i,j;
printf("Enter the no of diagraph\n");
scanf("%d",&n);
printf("enter the values of adjacent matrix\n");
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        scanf("%d",&arr[i][j]);
    }
}
printf("enter the source vertex");
scanf("%d",&s);
bfs(n,s,vis,arr);
for(i=0;i<n;i++)
{
    if(vis[i]==1)
    {
        printf("%d reacheble from %d",s,i);
    }
    else
    {
      printf("%d not reacheble from %d",s,i);  
    }
}

return 0;
}
void bfs(int n,int s,int vis[],int arr[][SIZE])
{
    int queue[SIZE];
    int u,v,f=0,r=0;
    queue[r]=s;
    vis[s]=1;
    while(f<=r)
    {
        u=queue[f++];
        for(v=0;v<n;v++)
        {
            if( arr[u][v]==1&&vis[v]==0)
            {
                queue[++r]=v;
                vis[v]=1;
            }

        }
    }
}