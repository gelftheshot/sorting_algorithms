#include "sort.h"

/**
 * counting_sort - sort postive number
 * @array: the array to be sorted
 * @size: size of the array
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int n = size;
	int i, j, max = 0;
	int *count_array;
	int *temp;
	size_t count_len;

	if (array == NULL || size < 2)
		return;

	
	for (i = 0; i < n; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count_array = malloc(sizeof(int) * (max + 1));
	if (count_array == NULL)
	{
		return;
	}
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
	{
		free(count_array);
		return;
	}

	count_len = max + 1;

	for (i = 0; i < n; i++)
	{
		temp[i] = array[i];
	}

	for (j = 0; j <= max; j++)
	{
		count_array[j] = 0;
	}

	for (i = 0; i < n; i++)
	{
		count_array[array[i]] = count_array[array[i]] + 1;
	}

	for (i = 1; i <= max; i++)
	{
		count_array[i] = count_array[i] + count_array[i - 1];
	}
	print_array(count_array, count_len);

	for (i = n - 1; i >= 0; i--)
	{
		array[count_array[temp[i]] - 1] = temp[i];
		count_array[temp[i]]--;
	}
	free(count_array);
	free(temp);
}
