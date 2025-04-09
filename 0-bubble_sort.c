#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in 
 * ascending order using the Bubble sort algorithm
 *
 * @array: int array
 * @size: size_t
 */
void bubble_sort(int *array, size_t size)
{

	size_t pass, index;
	int temp, swap;

	if (array == NULL || size < 2)
		return;

	for (pass = 0; pass <size - 1; pass++)
	{
		swap = 0;
		for (index = 0; index < size - pass; index++)
		{
			if (array[index] > array[index + 1])
			{
				temp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temp;
				swap = 1;
				print_array(array, size);
			}
		if (!swap)
		break;
		}
	}
}

