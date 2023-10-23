#include "sort.h"

void real_merge(int *array, int init, int end);
void merge_sub(int *array, int m, int init, int end);
/**
 *
 *
 *
 */

void merge_sort(int *array, size_t size)
{
	int n = size;
	real_merge(array, 0, n - 1);
}

void real_merge(int *array, int init, int end)
{
	int m;
	if (end - init < 1)
		return;
	m = (init + end + 1) / 2;
	real_merge(array, init, m-1);
	real_merge(array, m, end);
	merge_sub(array, m, init, end);
}

void merge_sub(int *array, int m, int init, int end)
{
	const size_t len1 = m - init;
	const size_t len2 = end - m + 1;
	int a1[len1];
	int a2[len2];
	int i, j, k;
	
	printf("merging...\n");
	for (i = 0; i < len1; i++)
	{
		a1[i] = array[init + i];
	}
	for (j = 0; j < len2; j++)
	{
		a2[j] = array[m + j];
	}

	for(i = 0, j = 0, k = init; k <= end; k++)
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
	for(i = 0; i < len1; i++)
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
	printf("[done]: ");
	for (k = init; k <= end; k++)
	{
		printf("%d", array[k]);
		if (k != end)
			printf(", ");
	}
	printf("\n");
}
