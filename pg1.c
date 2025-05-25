#include <stdio.h>
int BinarySearch(int array[], int start_index, int end_index, int element)
{
    if (end_index >= start_index)
    {
        int middle = start_index + (end_index - start_index) / 2;
        if (array[middle] == element)
            return middle;
        if (array[middle] > element)
            return BinarySearch(array, start_index, middle - 1, element);
        return BinarySearch(array, middle + 1, end_index, element);
    }
    return -1;
}
int main(void)
{
    int array[20], n, element, i = 0;
    printf("Enter the number of elements ");
    scanf("%d", &n);
    printf("Enter elements in sorted order");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Enter key value");
    scanf("%d", &element);
    int found = BinarySearch(array, 0, n, element);
    if (found == -1)
    {
        printf("Element not found in the array ");
    }
    else
    {
        printf("Element found at index : %d", found + 1);
    }
    return 0;
}