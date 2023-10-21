#include "sort.h"

/**
 *bubble_sort - sort an array in buble way
 *@size: size of the array
 *@array: is the array to be sorted
 *Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int temp;

	for (i = 0; i < size; ++i)
	{
		for (j = 1; j < size - i; ++j)
		{
			if (array[j] < array[j - 1])
			{
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
}
