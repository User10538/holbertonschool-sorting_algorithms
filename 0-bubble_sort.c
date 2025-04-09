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

	size_t pass, index, k;
	int temp, swap;

	if (array == NULL || size < 2)
		return;

	for (pass = 0; pass < size - 1; pass++)
	{
		swap = 0;
		for (index = 0; index < size - pass - 1; index++)
		{
			if (array[index] > array[index + 1])
			{
				temp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temp;

				/*Print the array after the swap*/
				for (k = 0; k < size; k++)
				{
					printf("%d", array[k]);
					if (k < size - 1)
						printf(", ");
				}
				printf("\n");
				swap = 1;
			}
		}

		if (!swap)
			break;
	}
}

