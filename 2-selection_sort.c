#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 *
 * @array: int
 * @size: size_t
 */
void selection_sort(int *array, size_t size)
{

	size_t current_index, compare_index, smallest_index;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (current_index = 0; current_index < size - 1; current_index++)
	{
		smallest_index = current_index;

		for (compare_index = current_index + 1;
				compare_index < size; compare_index++)
		{
			if (array[compare_index] < array[smallest_index])
				smallest_index = compare_index;
		}
		if (smallest_index != current_index)
		{
			temp = array[current_index];
			array[current_index] = array[smallest_index];
			array[smallest_index] = temp;

			print_array(array, size);
		}
	}
}
