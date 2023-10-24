#include "sort.h"

void real_merge(int *array, int init, int end);
void merge_sub(int *array, int m, int init, int end);

/**
 *merge_sort - sort arraying using merge sort
 *@array: the array
 *@size: the size of the array
 *Return: void
 */

void merge_sort(int *array, size_t size)
{
	int n = size;

	real_merge(array, 0, n - 1);
}

/**
 *real_merge - recurtion part of merge function
 *@array: the array
 *@init: the init part
 *@end: the end of the array
 *Return: void
 */

void real_merge(int *array, int init, int end)
{
	int m;

	if (end - init < 1)
		return;
	m = (init + end + 1) / 2;
	real_merge(array, init, m - 1);
	real_merge(array, m, end);
	merge_sub(array, m, init, end);
}

/**
 * merge_sub - merge two sorted sub-array
 * @array: the main array
 * @m: the middle of the arrays
 * @init: the init of the array
 * @end: the end of the array
 * Return: void
 */

void merge_sub(int *array, int m, int init, int end)
{
	const int len1 = m - init;
	const int len2 = end - m + 1;
	int a1[1024];
	int a2[1024];
	int i, j, k;

	printf("Merging...\n");
	for (i = 0; i < len1; i++)
	{
		a1[i] = array[init + i];
	}
	for (j = 0; j < len2; j++)
	{
		a2[j] = array[m + j];
	}

	for (i = 0, j = 0, k = init; k <= end; k++)
	{
		if ((i < len1) && ((j >= len2) || a1[i] <= a2[j]))
		{
			array[k] = a1[i];
			i++;
		}
		else
		{
			array[k] = a2[j];
			j++;
		}
	}
	printf("[left]: ");
	for (i = 0; i < len1; i++)
	{
		printf("%d", a1[i]);
		if (i != len1 - 1)
			printf(", ");
	}
	printf("\n");
	printf("[right]: ");
	for (i = 0; i < len2; i++)
	{
		printf("%d", a2[i]);
		if (i != len2 - 1)
			printf(", ");
	}
	printf("\n");
	printf("[Done]: ");
	for (k = init; k <= end; k++)
	{
		printf("%d", array[k]);
		if (k != end)
			printf(", ");
	}
	printf("\n");
}
