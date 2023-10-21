#include "sort.h"

/**
 *
 */

void selection_sort(int *array, size_t size)
{
    int i;
    int j;
    int small;
    int temp;

    for (i = 0; i < size; i++)
    {
        small = i;
        for (j = i + 1; j < size; j++)
        {
            if( array[j] < array[small])
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
