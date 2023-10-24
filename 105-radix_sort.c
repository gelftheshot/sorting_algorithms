#include "sort.h"

/**
 *
 *
 */

void digit_count_sort(int *array, int size, int digit)
{

	int n = size;
	int i, j,m, max = 0;

	int *count_array;
	int *temp = malloc(sizeof(int) * size);

	for (i = 0; i < n; i++)
	{
		if (((array[i] / digit) % 10)  >  max)
			max = (array[i] / digit) % 10;
	}
	
	count_array = malloc(sizeof(int) * (max + 1));


	for (i = 0; i < n; i++)
	{
		temp[i] = array[i];
	}

	for (j = 0; j <= max; j++)
	{
		count_array[j] = 0;
	}

	for (i = 0; i < n; i++)
	{
		m = (array[i] / digit) % 10;
		count_array[m] = count_array[m] + 1;
	}
    for (i = 1; i <= max; i++)
        count_array[i] = count_array[i] + count_array[i - 1];
    for (i = n - 1; i >= 0; i--)
 
    {
    	array[count_array[(temp[i] / digit) % 10] - 1] = temp[i];
    	count_array[(temp[i] / digit ) % 10]--;
    }

	
}

void radix_sort(int *array, size_t size)
{
	int n = size;
	int i;
	int max = 0;
	int digit;

	for (i = 0; i < n; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	for (digit = 1; max/digit > 0; digit = digit * 10)
	{
		digit_count_sort(array, size, digit);
	}

}
