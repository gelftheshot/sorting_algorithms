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

	if (init >= end)
		return;
	pos = Hoare_part(array, init, end, size);
	quick(array, init, pos - 1, size);
	quick(array, pos, end, size);
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
	int pivot, above, below, temp;

	pivot = array[end];
	for (above = init - 1, below = end + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			temp = array[above];
			array[above] = array[below];
			array[below] = temp;
			print_array(array, size);
		}
	}

	return (above);
}
