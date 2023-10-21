#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main() {
    int array1[] = {5, 3, 8, 2, 1};
    int length1 = sizeof(array1) / sizeof(array1[0]);

    int array3[] = {9};
    int length3 = sizeof(array3) / sizeof(array3[0]);

    int array4[] = {1, 2, 3, 4, 5};
    int length4 = sizeof(array4) / sizeof(array4[0]);

    int array5[] = {7, 6, 5, 4, 3};
    int length5 = sizeof(array5) / sizeof(array5[0]);

    int array6[] = {2, 4, 1, 2, 3, 4};
    int length6 = sizeof(array6) / sizeof(array6[0]);

    bubble_sort(array1, length1);
    print_array(array1, length1);


    bubble_sort(array3, length3);
    print_array(array3, length3);

    bubble_sort(array4, length4);
    print_array(array4, length4);

    bubble_sort(array5, length5);
    print_array(array5, length5);

    bubble_sort(array6, length6);
    print_array(array6, length6);

    return 0;
}
