#include <stdio.h>
int x[10];
void nqueens(int, int);
void main()
{
    int n, i, j;
    printf("\nEnter the no of queens\n");
    scanf("%d", &n);
    if (n == 0 || n == 2 || n == 3)
    {
        printf("No solutions");
    }
    else
        nqueens(1, n);
}
int place(int k, int i)
{
    int j;
    for (j = 1; j < k; j++)
        if (x[j] == i || (abs(x[j] - i) == abs(j - k)))
            return 0;
    return 1;
}
void nqueens(int k, int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
        if (place(k, i))
        {
            x[k] = i;
            if (k == n)
            {
                printf("\n");
                printf("Solution is:");
                for (j = 1; j <= n; j++)
                    printf("%2d", x[j]);
                printf("\n");
                for (i = 1; i <= n; i++)
                {
                    for (j = 1; j <= n; j++)
                    {
                        if (x[i] == j)
                            printf("Q%d\t", i);
                        else
                            printf("*\t");
                    }
                    printf("\n");
                    printf("\n");
                }
            }
            else
                nqueens(k + 1, n);
        }
}