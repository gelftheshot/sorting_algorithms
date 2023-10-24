#include "sort.h"

/**
 *
 *
 *
*/

void hipify(int *array, int size, int n)
{
	int count = (size -1) / 2;
	int temp;
	int a;
	int b;

	while (count >= 0)
	{
		a = 2 * count + 1;
		b = 2 * count + 2;
		if (a == size)
		{
			if (array[a] > array[count])
			{
				temp = array[a];
				array[a] = array[count];
				array[count] = temp;
				print_array(array, n);
			}
		}
		if ( b <= size && (array[a] > array[b]) && (array[a] > array[count]))
			{
				temp = array[a];
				array[a] = array[count];
				array[count] = temp;
				print_array(array, n);
			}

		if ( b <= size && (array[b] > array[a]) && (array[b] > array[count]))
			{
				temp = array[b];
				array[b] = array[count];
				array[count] = temp;
				print_array(array, n);
			}
		count--;	
	}
}

void delete_heap(int *array, int size)
{
	int temp;

	temp = array[0];
	array[0] = array[size];
	array[size] = temp;
}

void heap_sort(int *array, size_t size)
{
	int count = size - 1;
	int n = size;
	while (count > 1)
	{
		hipify(array, count, n);
		delete_heap(array, count);
		print_array(array, size);
		count--;
	}
}









