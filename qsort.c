#include "qsort.h"

// int main(int argc, char const *argv[])
// {
//     int arr[] = {10, 7, 8, 9, 1, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     quicksort(arr, 0, n - 1);

//     printf("Sorted Array\n");
//     for (int i = 0; i < n; i++)
//         printf("%d ", arr[i]);
//     return 0;
// }

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int temp_pivotindex = start - 1;

    for (int j = start; j <= end; j++)
    {
        if (arr[j] < pivot)
        {
            temp_pivotindex++;
            swap(&arr[j], &arr[temp_pivotindex]);
        }
    }
    swap(&arr[temp_pivotindex + 1], &arr[end]);
    return temp_pivotindex + 1;
}

void quicksort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pattion_index = partition(arr, start, end);

        quicksort(arr, start, pattion_index - 1);
        quicksort(arr, pattion_index + 1, end);
    }
}