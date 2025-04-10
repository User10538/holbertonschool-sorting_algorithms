#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sort.h"
/**
 * quick_sort - function that sorts an array of integers in
 * ascending order using the Quick sort algo
 *
 * @array: int
 * @size: size_t
 */
void quick_sort(int *array, size_t size)
{

        size_t low = 0, high = (int)(size - 1), i, j, temp, partition_index;
	int pivot;

        if (array == NULL || size < 2)
                return;

        while (low < high)
        {
                pivot = array[high];
                i = low - 1;

                for (j = low; j < high; j++)
                {
                        if (array[j] < pivot)
                        {
                                i++;
                                temp = array[i];
                                array[i] = array[j];
                                array[j] = temp;
                                print_array(array, size);
                        }
                }
                temp = array[i + 1];
                array[i + 1] = array[high];
                array[high] = temp;
                print_array(array, size);

                partition_index = i + 1;
                if (partition_index - 1 > low)
                        high = partition_index - 1;
                else
                low = partition_index + 1;
        }

}

