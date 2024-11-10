#include<stdio.h>

int adj[10][10], visited[10], n = 0, V = 0, S[10];

int top = -1;
int pop(int S[]){
    if(top == -1){
        return -1;
    }
    else{
        return S[top--];
    }
}

int push(int S[], int element){
    if(top == V-1){
        reuturn -1;
    }
    else{
        S[top++] = element;
        retunr 0;
    }
}

void DFS(int source){
    visited[source] = 1;
    if(push(S, source) == -1){
        printf("Stack overflow");
    }
    int j = 0;
    for(j = 0; j < V; j++){
        if(adj[source][j] == 1 && visited[j] == 0){
            count++;
            if(push(S, j) == -1){
                printf("Stack overflow");
                return;
            }
            DFS(j);
        }
    }
    pop(S);
}

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

    DFS(source);
}