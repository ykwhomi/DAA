#include <stdio.h>
int parent[10];
void main()
{
    int mincost = 0, cost[10][10], n, i, j, ne, a, b, min, u, v;
    printf("Enter the number of vertices of the graph \n");
    scanf("%d", &n);
    printf("Enter the cost matrix\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    ne = 1;
    printf("\nThe edges of minimum spanning tree are: \n");
    while (ne < n)
    {
        for (min = 999, i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
        while (parent[u])
            u = parent[u];
        while (parent[v])
            v = parent[v];
        if (v != u)
        {
            printf("%d edge(%d,%d)=%d\n", ne++, a, b, min);
            mincost += min;
            parent[b] = a;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nThe minimum cost of spanning tree is %d\n", mincost);
}