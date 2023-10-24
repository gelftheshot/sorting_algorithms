#include "sort.h"

/**
 *
 *
 *
 */
void bitonic_merge(int *array, int init, int end, bool dir, size_t size)
{
	int count = end - init - 1;

	int mid = init + ((end - init) / 2);
	int i; 
	int temp;
	if (count > 0)
	{
		for (i = 0; i < (mid - init); i++)
		{
			if (dir == (array[init] > array[mid + i]))
			{
				temp = array[init + i];
				array[init + i] = array[mid + i];
				array[mid + i] = temp;
				print_array(array, size);
			}
		}
		bitonic_merge(array, init, mid, true, size);
		bitonic_merge(array, mid, end, false, size);
	}
}
void bitonic(int *array, int init, int end, bool dir, size_t size)
{
	int count = end - init - 1;
	int mid = init + ((end - init) / 2);
	if (count > 0)
	{
		bitonic(array, init, mid, true, size);
		bitonic(array, mid, end, false, size);
		bitonic_merge(array, init, end, dir, size);
	}
}
void bitonic_sort(int *array, size_t size)
{	
	int n = size;
	bool forward = true;
	bitonic(array, 0, n, forward, size);
}
