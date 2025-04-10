#include <stdio.h>
#include <stdlib.h>

/**
 * swap - swaps two elements in an array
 * @array: The array of integers
 * @i: Index of the first element to swap
 * @j: Index of the second element to swap
 */
void swap(int *array, int i, int j)
{
    int temp;
    size_t k;

    temp = array[i];
    array[i] = array[j];
    array[j] = temp;

    for (k = 0; k < 10; k++)
    {
        printf("%d", array[k]);
        if (k < 9)
        {
            printf(", ");
        }
    }
    printf("\n");
}

/**
 * partition - Lomuto partition scheme for Quick Sort
 * @array: The array of integers
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * Return: The index where the pivot is placed
 */
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

/**
 * quick_sort_recursive - Recursively applies quick sort to array
 * @array: The array of integers
 * @low: The starting index of the array
 * @high: The ending index of the array
 */
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

/**
 * quick_sort - Sorts the array using quick sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
    {
        return;
    }

    quick_sort_recursive(array, 0, size - 1);
}

