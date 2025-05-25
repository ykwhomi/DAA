#include <stdio.h>
#include <stdlib.h>

int i, j, n, f = 0, r = -1;
int a[10][10], q[10], visited[10];

void bfs(int u) {
    int v;
    visited[u] = 1;
    q[++r] = u;

    while (f <= r) {
        u = q[f++];
        for (v = 1; v <= n; v++) {
            if (a[u][v] == 1 && visited[v] == 0) {
                visited[v] = 1;
                q[++r] = v;
            }
        }
    }
}

void dfs(int u) {
    int v;
    visited[u] = 1;
    for (v = 1; v <= n; v++) {
        if (a[u][v] == 1 && visited[v] == 0) {
            dfs(v);
        }
    }
}

int main() {
    int source;

    // ---------- Input ----------
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix of the graph:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);


    printf("\nEnter the source vertex for BFS:\n");
    scanf("%d", &source);

    for (i = 1; i <= n; i++)
        visited[i] = 0;


    f = 0;
    r = -1;
    bfs(source);

    printf("From vertex %d, the reachable vertices using BFS are:\n", source);
    for (i = 1; i <= n; i++) {
        if (visited[i] == 1)
            printf("%d is visited\n", i);
    }

    printf("\nChecking connectivity of the graph using DFS...\n");

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            visited[j] = 0;

        dfs(i);

        for (j = 1; j <= n; j++) {
            if (visited[j] != 1) {
                printf("%d is not reachable from %d\n", j, i);
                printf("So, the graph is not connected.\n");
                return 0;
            }
        }
    }

    printf("The graph is connected.\n");
    return 0;
}
