#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 30000
#define NTIMES 5000

void merge(int a[], int low, int mid, int high) {
    int i, j, k;
    int b[MAXSIZE];

    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    while (i <= mid)
        b[k++] = a[i++];
    
    while (j <= high)
        b[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = b[i];
}

void merge_sort_custom(int a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        merge_sort_custom(a, low, mid);
        merge_sort_custom(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int a[MAXSIZE], i, n, k;
    double runtime = 0;
    clock_t start, end;

    printf("Enter the value of n (<= %d):\n", MAXSIZE - 1);
    scanf("%d", &n);

    if (n >= MAXSIZE) {
        printf("Value too large!\n");
        return 1;
    }

    srand(1);  // Moved outside the loop to prevent same numbers each time

    for (k = 1; k <= NTIMES; k++) {
        for (i = 1; i <= n; i++)
            a[i] = rand();

        start = clock();
        merge_sort_custom(a, 1, n);  // Use 1-based indexing as in original
        end = clock();

        runtime += ((double)(end - start)) / CLOCKS_PER_SEC;
    }

    runtime /= NTIMES;

    printf("\nSorted elements are:\n");
    for (i = 1; i <= n; i++)
        printf("%d\n", a[i]);

    printf("Average time taken for sorting: %lf seconds\n", runtime);

    return 0;
}