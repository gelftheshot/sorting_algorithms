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
	int temp;
	size_t j = 0;

	for (; j < size; j++)
	{
		for (i = 0; i < size - j - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
	}
	}
}
