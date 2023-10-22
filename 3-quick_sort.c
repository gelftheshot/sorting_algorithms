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
	int i = init - 1;
	int j;
	int temp;

	for (j = init; j < end; j++)
	{
		if (array[j] < array[end])
		{
			i++;
			if (i != j)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
	}
	if (end != i + 1)
	{
		temp = array[end];
		array[end] = array[i + 1];
		array[i + 1] = temp;
		print_array(array, size);
		return (i + 1);
	}
	return (i + 1);
}
