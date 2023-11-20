#include "sort.h"

/**
 * partition - divides the array into segments
 * for a divide and conquer approach
 * @array: the array to be partitioned
 * @low: the lowest index
 * @high: the highest index
 * Return: the index where the partition pivots
*/
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j, tmp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++; /*increment i before swap*/
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}

	tmp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = tmp;

	return (i + 1);
}

/**
 * quick_sort - this function sorts in the divide & conquer approach
 * @array: the array to be sorted
 * @size: the array's size
 * doesn't return
*/
void quick_sort(int *array, size_t size)
{
	int low, high, pivot;

	/*where array is empty*/
	if (!array || !size)
		return;

	low = 0;
	high = size - 1;

	if (low < high)
	{
		pivot = partition(array, low, high);
		quick_sort(array, pivot);
		quick_sort(&array[pivot + 1], high - pivot);
	}

	print_array(array, size);
}
