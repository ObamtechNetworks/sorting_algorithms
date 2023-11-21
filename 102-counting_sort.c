#include "sort.h"

/**
 * counting_sort - function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @array: the array to be sorted
 * @size: the sizeof(array)
*/
void counting_sort(int *array, size_t size)
{
    int *count, *result, max, x;
    size_t i;

    if (!array || size < 2)
        return;

    /*Determine the max val in array*/
    max = array[0];
    for (i = 0; i < size; i++)
    {   if (array[i] > max)
            max = array[i];
    }

    /*create a count array to track element re-occurence*/
    count = malloc((max + 1) * sizeof(int));
    if (!count)
        return;
    for (x = 0; x <= max; x++) /*initialaize array with 0*/
        count[x] = 0;
    for (i = 0; i < size; i++) /*counting ele occurrence*/
        count[array[i]]++;
    for (x = 1; x <= max; x++) /*update count array cumulatively*/
        count[x] += count[x - 1];

    /*storing sorted array*/
    result = malloc(size * sizeof(int));
    if (!result)
    {   free(count);
        return;
    }
    for (x = size - 1; x >= 0; x--) /*building sorted array*/
    {   result[count[array[x]] - 1] = array[x];
        count[array[x]]--;
    }
    for (i = 0; i < size; i++) /*copy sorted to original array*/
        array[i] = result[i];
    free(count);
    free(result);
}
