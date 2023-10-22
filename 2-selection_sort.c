#include "sort.h"

/**
 *selection_sort - sort an array with selection sort
 *@array: is the array to be sorted
 *@size: is the size of an array
 *Return: is a void function
 */

void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t small;
	int temp;

	for (i = 0; i < size; i++)
	{
		small = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[small])
			{
				small = j;
			}
		}
		if (i != small)
		{
			temp = array[i];
			array[i] = array[small];
			array[small] = temp;
			print_array(array, size);
		}
	}
}
