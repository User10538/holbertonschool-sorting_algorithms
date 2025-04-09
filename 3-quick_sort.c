#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void quick_sort(int *array, size_t size)
{
    size_t low = 0, high = size - 1, i, j, temp, partition_index, k;
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
            }
        }

        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        partition_index = i + 1;

        for (k = 0; k < size; k++)
        {
            if (k != 0)
                printf(", ");
            printf("%d", array[k]);
        }
        printf("\n");

        if (partition_index > low)
            quick_sort(array, partition_index);
        if (partition_index + 1 < high)
            quick_sort(array + partition_index + 1, size - (partition_index + 1)); 
    }
}

