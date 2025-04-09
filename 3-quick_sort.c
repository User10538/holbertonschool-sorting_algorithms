#include <stdio.h>
#include <stdlib.h>

void swap(int *array, int i, int j)
{
    int temp;
    size_t k;

    temp = array[i];
    array[i] = array[j];
    array[j] = temp;

    for (k = 0; k < 20; k++)
    {
        printf("%d", array[k]);
        if (k < 19)
            printf(", ");
    }
    printf("\n");
}

int partition(int *array, int low, int high)
{
    int pivot;
    int i;
    int j;

    pivot = array[high];
    i = low - 1;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(array, i, j);
        }
    }

    swap(array, i + 1, high);
    return (i + 1);
}

void quick_sort_recursive(int *array, int low, int high)
{
    int pivot_index;

    if (low < high)
    {
        pivot_index = partition(array, low, high);
        quick_sort_recursive(array, low, pivot_index - 1);
        quick_sort_recursive(array, pivot_index + 1, high);
    }
}

void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
    {
        return;
    }

    quick_sort_recursive(array, 0, size - 1);
}

