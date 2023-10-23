#include "sort.h"

/**
 *
 *
 *
 */

void counting_sort(int *array, size_t size)
{
	int n = size;
	int i, j, max = 0;
	int *count_array;
	int *temp = malloc(sizeof(int) * size);

	for (i = 0; i < n; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	
	count_array = malloc(sizeof(int) * (max + 1));


	for (i = 0; i < n; i++)
	{
		temp[i] = array[i];
	}
	for (j = 0; j < max; j++)
	{
		count_array[j] = 0;
	}
	for (i = 0; i < n; i++)
	{
		count_array[array[i]] = count_array[array[i]] + 1;
	}

    for (i = 1; i <= max; i++)
        count_array[i] = count_array[i] + count_array[i - 1];
    for (int i = n - 1; i >= 0; i--)
 
    {
        array[count_array[temp[i]] - 1] = temp[i];
 
        count_array[temp[i]]--;
    }
	free(count_array);
	free(temp);

}
