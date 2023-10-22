#include "sort.h"


int Lomuto_part(int *array, int init, int end, size_t size);
void quick(int *array, int init, int end, size_t size);

/**
 *quick_sort - sort an array in quick sort
 *@array: is the array to be sorted
 *@size: the size of an array
 *Return: is void.
**/

void quick_sort(int *array, size_t size)
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
	pos = Lomuto_part(array, init, end, size);
	quick(array, init, pos - 1, size);
	quick(array, pos + 1, end, size);
}

/**
 *Lomuto_part - finding pivot
 *@array: the array
 *@init: the start when dividing and concuring
 *@end: the end of the array
 *@size: the size of the array
 *Return: the pivot
*/

int Lomuto_part(int *array, int init, int end, size_t size)
{
	int i = init;
	int j;
	int temp;

	for (j = init; j < end; j++)
	{
		if (array[j] < array[end])
		{
			if (j > i)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[end] < array[i])
	{
		temp = array[end];
		array[end] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
	return (i);
}
