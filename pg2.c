// Breadth First Search

#include <stdio.h>
int i, j, n, f = 0, r = 0, a[10][10], q[10], visited[10];
void bfs(int u)
{
    int v;
    visited[u] = 1;
    q[r] = u;
    while (f <= r)
    {
        u = q[f++];
        for (v = 1; v <= n; v++)
        {
            if (a[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                q[++r] = v;
            }
        }
    }
}
void main()
{
    int source;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix of the directed graph\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    printf("Enter the source vertex\n");
    scanf("%d", &source);
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    bfs(source);
    printf("From vertex %d the vertices\n", source);
    for (i = 1; i <= n; i++)
    {
        if (visited[i] == 1)
            printf("%d is visited \n", i);
    }
}

// Depth First Search

#include <stdio.h>
int n, a[10][10], visited[10];
void dfs(int u)
{
    int v;
    visited[u] = 1;
    for (v = 1; v <= n; v++)
        if (a[u][v] == 1 && visited[v] == 0)
            dfs(v);
}
void main()
{
    int I, j, source;
    printf("Enter the number of vertices of the graph :");
    scanf("% d", &n);
    printf("Enter the adjacency matrix.....\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("% d", &a[i][j]);
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    for (i = 1; i <= n; i++)
    {
        dfs(i);
        for (j = 1; j < n; j++)
        {
            if (visited[j] != 1)
            {
                printf("% d is not reachable from % d\n", j, i);
                printf("So graph is not connected");
                exit(0);
            }
        }
    }
    for (j = 1; j <= n; j++)
        visited[j] = 0;
    printf("\n\n\n");
    printf("Graph is connected\n"); 