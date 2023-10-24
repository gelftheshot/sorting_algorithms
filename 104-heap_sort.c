#include "sort.h"

/**
 *hipify - convert array to heap form
 *@array: the array to be sorted
 *@size: size of the array
 *@init: the init of the sub tree
 *@end: the end of the sub tree
 *Return: void
*/

void hipify(int *array, size_t size, size_t init, size_t end)
{
	size_t a, b, large;
	int temp;

	a = 2 * end + 1;
	b = 2 * end + 2;
	large = end;

	if (a < init && array[a] > array[large])
		large = a;
	if (b < init && array[b] > array[large])
		large = b;

	if (large != end)
	{
		temp = array[end];
		array[end] = array[large];
		array[large] = temp;
		print_array(array, size);
		hipify(array, size, init, large);
	}
}

/**
 *delete_heap - delete the root of the heap
 *@array: the heap array
 *@size: the size of the array
 *Return: void
**/

void delete_heap(int *array, int size)
{
	int temp;

	temp = array[0];
	array[0] = array[size];
	array[size] = temp;
}

/**
 *heap_sort - the main heap sort
 *@array: the array to be sorted
 *@size: the size of the array
 *Return: void
*/

void heap_sort(int *array, size_t size)
{
	int count = (size / 2) - 1;
	size_t i = size - 1;

	if (array == NULL || size < 2)
		return;
	for (; count >= 0; count--)
	{
		hipify(array, size, size, count);
	}
	for (; i > 0; i--)
	{
		delete_heap(array, i);
		print_array(array, size);
		hipify(array, size, i, 0);
	}
}
