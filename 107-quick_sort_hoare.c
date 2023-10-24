#include "sort.h"


int Hoare_part(int *array, int init, int end, size_t size);
void quick(int *array, int init, int end, size_t size);

/**
 *quick_sort_hoare - sort an array in quick sort
 *@array: is the array to be sorted
 *@size: the size of an array
 *Return: is void.
**/

void quick_sort_hoare(int *array, size_t size)
{
	int init = 0;
	int end = size - 1;

	if (array == NULL || size < 2)
		return;
	quick(array, init, end, size);
}

/**
 *quick - the real quick sort
 *@array: the array
 *@init: the start when dividing and concuring
 *@end: the end of the array
 *@size: the size of the array
 *Return: void
*/

void quick(int *array, int init, int end, size_t size)
{
	int pos;

	if (end - init > 0)
	{
		pos = Hoare_part(array, init, end, size);
		quick(array, init, pos - 1, size);
		quick(array, pos + 1, end, size);
	}
}

/**
 *Hoare_part - finding pivot
 *@array: the array
 *@init: the start when dividing and concuring
 *@end: the end of the array
 *@size: the size of the array
 *Return: the pivot
*/

int Hoare_part(int *array, int init, int end, size_t size)
{
	int min = init - 1;
	int max = end;
	int temp;
	int pivot = end;

	while (min < max)
	{
		while (array[min] < array[pivot])
			min++;
		while (array[max] > array[pivot])
			max--;

		if (min > max)
		{
			temp = array[min];
			array[min] = array[max];
			array[max] = temp;
			print_array(array, size);
		}
	}
	return (max);
}
