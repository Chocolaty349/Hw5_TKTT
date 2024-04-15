#include <stdio.h>
#include <stdlib.h>

void merge(int[], int, int, int);
void mergeSort(int[], int, int);

int main(int argc, char const *argv[])
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    for(int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void merge(int arr[], int start, int middle, int end)
{
    int i, j, k;
    int n1 = middle - start + 1;
    int n2 = end - middle;

    // Create temp arrays
    int left_part[n1], right_part[n2];

    // Copy data to temp arrays
    for (i = 0; i < n1; i++)
        left_part[i] = arr[start + i];
    for (j = 0; j < n2; j++)
        right_part[j] = arr[middle + 1 + j];

    // Merge the temp arrays back into arr
    i = 0;
    j = 0;
    k = start;
    while (i < n1 && j < n2)
    {
        if (left_part[i] <= right_part[j])
        {
            arr[k] = left_part[i];
            i++;
        }
        else
        {
            arr[k] = right_part[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left_part[], if there are any
    while (i < n1)
    {
        arr[k] = left_part[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right_part[], if there are any
    while (j < n2)
    {
        arr[k] = right_part[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int m = start + (end - start) / 2;

        mergeSort(arr, start, m);
        mergeSort(arr, m + 1, end);

        merge(arr, start, m, end);
    }
}