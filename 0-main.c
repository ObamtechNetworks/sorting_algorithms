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
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
/*	int array_2[] = {57, 77, 7, 70, 97, 16, 61, 26, 71, 84, 28, 52, 88, 83, 25, 54, 99, 21, 13, 19, 72, 82, 47, 55, 11, 69, 60, 63, 31, 81};*/
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    bubble_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
