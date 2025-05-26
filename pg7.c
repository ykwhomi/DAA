#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, capacity, i, j, w;
    int weight[20], value[20], included[20] = {0};
    int v[50][50];

    printf("Enter the no of items: ");
    scanf("%d", &n);

    printf("Enter the wt of %d item: ", n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
    }

    printf("Enter the values (profit): ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &value[i]);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    // Fill DP table
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (weight[i] <= j)
                v[i][j] = max(v[i - 1][j], v[i - 1][j - weight[i]] + value[i]);
            else
                v[i][j] = v[i - 1][j];

            // Print table value immediately
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }

    // Backtrack to find selected items
    w = capacity;
    for (i = n; i > 0; i--) {
        if (v[i][w] != v[i - 1][w]) {
            included[i] = 1;
            w -= weight[i];
        }
    }

    printf("The o.s is %d\n", v[n][capacity]);
    printf("The validity of items are:\n");
    printf("Item: Validity: Weight: Profit:\n");
    for (i = 1; i <= n; i++) {
        printf("[%d]:   %d     :   %d   :  %d :\n", i, included[i], weight[i], value[i]);
    }

    return 0;
}
