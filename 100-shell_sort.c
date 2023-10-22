#include "sort.h"

/**
 *shell_sort - sort array
 *@array: the array to be sorted
 *@size: the size of thea array
 *Return: void
 */

void shell_sort(int *array, size_t size)
{
	int n = size;
	int h = 1;
	int i, j, k, temp;

	while (h < n)
	{
		h = h * 3 + 1;
	}

	h = (h - 1) / 3;

	while (h > 0)
	{
		i = h;
		while (i <= n - 1)
		{
			for (j = (i - h); j < n; j = j + h)
			{
				for (k = j + h; k < n; k = k + h)
				{
					if (array[j] > array[k])
					{
						temp = array[j];
						array[j] = array[k];
						array[k] = temp;
					}
				}
			}
			i++;
		}
	h = (h - 1) / 3;
	print_array(array, size);
	}
}
