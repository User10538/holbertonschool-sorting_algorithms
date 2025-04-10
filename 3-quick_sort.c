#include "sort.h"
#include <stdlib.h>
#include <string.h>  /* For memcpy */

/**
 * swap - swaps two elements in an array
 * @a: first int
 * @b: second int
 */
void swap(int *a, int *b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for quicksort
 * @array: array of integers
 * @low: starting index
 * @high: ending index
 * @size: size of the array (for print_array)
 * Return: index of the pivot after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;
	int *last_printed_array;  /* Pointer for storing the last printed state */
	int array_changed;
       	/* Dynamically allocate memory for last_printed_array */
	last_printed_array = (int *)malloc(size * sizeof(int));
	
	if (last_printed_array == NULL)
	{
		return -1;
	}
	
	pivot = array[high];
       	i = low - 1;
	
	/* Copy the initial state of the array */
	memcpy(last_printed_array, array, size * sizeof(int));
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				array_changed = memcmp(last_printed_array,
						array, size * sizeof(int)); /* Check if array changed */
				if (array_changed != 0) /* If the array has changed, print it */
				{
					memcpy(last_printed_array, array, size * sizeof(int)); /* Update last printed state */
					print_array(array, size);
				}
			}
		}
	}
	if (i + 1 != high)
    	{
		swap(&array[i + 1], &array[high]);
		array_changed = memcmp(last_printed_array, array, size * sizeof(int)); /* Check if array changed */
        	
		if (array_changed != 0) /* If the array has changed, print it */
		{
			memcpy(last_printed_array, array, size * sizeof(int)); /* Update last printed state */
			print_array(array, size);
	   	}
	}

    /* Free the dynamically allocated memory */
    free(last_printed_array);

    return (i + 1);
}

/**
 * quick_sort_recursive - recursively applies quicksort
 * @array: array to sort
 * @low: start index
 * @high: end index
 * @size: total size of array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = lomuto_partition(array, low, high, size);
        quick_sort_recursive(array, low, pivot - 1, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort - main function to call quicksort on array
 * @array: array of integers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_recursive(array, 0, (int)(size - 1), size);
}

