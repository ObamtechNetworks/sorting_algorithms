#include "sort.h"

/**
 * bubble-sort - function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * void function, doesn't return
*/
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int tmp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                print_array(array, size);
            }
        }
    }
}