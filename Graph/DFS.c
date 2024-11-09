#include<stdio.h>

int adj[10][10], visited[10], n = 0, V = 0;

int main(void)
{
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges:");
    scanf("%d", &n);
    for(int i = 0; i < V; i++)
    {
        visited[i] = 0;
        for(int j = 0; j < V; j++)
        {
            adj[i][j] = 0;
        }
    }

    printf("Enter %d edges: \n", n);
    printf("Enter the edges in the format (u v): \n");
    for(int i = 0; i < n; i++){
        int u,v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
}