#include "sort.h"

/**
 *bitonic_merge - merge two bitonic sequance
 *@array: the array
 *@init: the init
 *@end: the end
 *@dir: the dir
 *@size: the size
 *Return: void
 */
void bitonic_merge(int *array, int init, int end, bool dir, size_t size)
{

	int mid = end / 2;
	int i;
	int temp;

	if (end > 1)
	{
		for (i = init; i < (mid + init); i++)
		{
			if (dir == (array[i] > array[mid + i]))
			{
				temp = array[i];
				array[i] = array[mid + i];
				array[mid + i] = temp;
			}
		}
		bitonic_merge(array, init, mid, dir, size);
		bitonic_merge(array, (init + mid), mid, dir, size);
	}
}

/**
 *bitonic - merge two bitonic sequance
 *@array: the array
 *@init: the init
 *@end: the end
 *@dir: the dir
 *@size: the size
 *Return: void
 */

void bitonic(int *array, int init, int end, bool dir, size_t size)
{
	int mid;
	char *str;

	if (dir == true)
		str = "UP";
	else
		str = "DOWN";

	if (end > 1)
	{
		printf("Merging [%d/%lu] (%s):\n", end, size, str);
		print_array(array + init, end);

		mid = end / 2;
		bitonic(array, init, mid, true, size);
		bitonic(array, (mid + init), mid, false, size);
		bitonic_merge(array, init, end, dir, size);

		printf("Result [%d/%lu] (%s):\n", end, size, str);
		print_array(array + init, end);
	}
}

/**
 *bitonic_sort - the ral function
 *@array: the array
 *@size: size of array
 */

void bitonic_sort(int *array, size_t size)
{
	int n = size;
	bool forward = true;

	bitonic(array, 0, n, forward, size);
}
