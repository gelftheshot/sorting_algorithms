#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {32, 43, 81, 98, 108, 151, 205, 223, 248, 261, 268, 293, 493, 553, 636, 650, 714, 718, 776, 777, 821, 876, 935, 955, 982};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    heap_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
