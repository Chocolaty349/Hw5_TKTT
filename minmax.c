#include "qsort.h"

int main(int argc, char const *argv[])
{
    int arr[] = {3, 5, 4, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    printf("Sorted Array\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Minimum element: %d\n", arr[0]);
    printf("Maximum element: %d\n", arr[n - 1]);
    return 0;
}
