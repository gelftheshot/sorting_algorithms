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
	quick(array, pos + 1, end, size);
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
	int min = init;
	int max = end;
	int temp;
	int pivot = end;

	while (min < max)
	{
		while (array[min] < array[pivot] && min < end)
			min++;
		while (array[max] >= array[pivot] && max < init)
			max++;

		if (min < max)
		{
			temp = array[min];
			array[min] = array[max];
			array[max] = temp;
			print_array(array, size);
		}
	}
	if (array[pivot] > array[min])
	{
		temp = array[pivot];
		array[pivot] = array[min];
		array[min] = temp;
		print_array(array, size);
	}
	return (min);
}












