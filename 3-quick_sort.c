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

        size_t low = 0, high = size - 1, i, j, k, temp, partition_index;
        int pivot;

        if (!array || size < 2)
                return;

        if (low < high)
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
                                for (k = 0; k < size; k++)
                                {
                                        if (k !=0)
                                                printf(", ");
                                        printf("%d", array[k]);
                                }
                                printf("\n");
                        }
                }
                temp = array[i + 1];
                array[i + 1] = array[high];
                array[high] = temp;
                for (k = 0; k < size; k++)
                        printf("%d", array[k]);
                printf("\n");
                partition_index = i + 1;
                if (partition_index > low)
                        quick_sort(array, partition_index);
                else
                        low = partition_index + 1;
                if (partition_index + 1 < high)
                        quick_sort(array + partition_index + 1, size - (partition_index + 1));
                else
                        high = partition_index - 1;
        }
}
