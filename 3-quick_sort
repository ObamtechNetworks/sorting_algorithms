#include "sort.h"
/**
 * swap - a function that swaps two elements
 * @a: address of the first element
 * @b: address of the second element
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int temp; /*a temporary variable for helping the swapping*/

	temp = *b;
	*b = *a;
	*a = temp;
}
/**
 * partition_array - partitions the array to sort
 * @array: the array to partition
 * @low: the index of the lowest element in the list
 * @high: the index of the highest element in the list
 * Return: returns the low_idx, which is actually the pivot
 */
int partition_array(int *array, int low, int high)
{
	int pivot = array[high]; /*select the last elment as computed in main func*/
	int lowidx = low;
	int highidx = high - 1;
	int isswaped = 0;

	while (1)
	{
		while (array[lowidx] < pivot && lowidx < high)
		{
			lowidx++;
		}
		while (array[highidx] > pivot && highidx >= lowidx)
		{
			highidx--;
		}
		if (lowidx >= highidx)
			break;
		else
		{
			swap(&array[lowidx], &array[highidx]);
			isswaped = 1;
		}
	}
	swap(&array[lowidx], &array[high]);
	if (isswaped)
	{
		print_array(array, high + 1);
	}
	return (lowidx);
}

/**
 * quick_sort - sorts an arr of int in ascd.Order using the Quick sort algo.
 * @array: pointer to the first element of the array to sort
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	int low, high, pivot;
	/*edge cases*/
	if (!array || !size)
		return;

	low = 0;
	high = size - 1;

	/*recursive call*/
	if (low < high) /*base case*/
	{
		pivot = partition_array(array, low, high);
		quick_sort(array, pivot);
		/*high - pivot gets size of sublist*/
		quick_sort(&array[pivot + 1], high - pivot);
	}
}
