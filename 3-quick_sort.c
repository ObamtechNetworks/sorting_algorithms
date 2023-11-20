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
 * lomuto_arr_partition - partitions the array using lomuto partition scheme
 * @array: the array to partition
 * @low: the index of the lowest element in the list
 * @high: the index of the highest element in the list
 * @size: the size of the array
 * Return: returns the low_idx, which is actually the pivot
 */
int lomuto_arr_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high]; /*select the last el as computed in main func*/
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[j], &array[i]);
				print_array(array, size);
			}
		}

	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_helper - sorts an arr of int using lomuto partition scheme
 * @array: pointer to the first element of the array to sort
 * @low: the lower bound of the array
 * @high: the higher/upper bound of the array
 * @size: size of the array
 * Return: void
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_arr_partition(array, low, high, size);
		if (pivot > low)
		{
			quick_sort_helper(array, low, pivot - 1, size);
		}
		if (pivot + 1 < high)
		{
			quick_sort_helper(array, pivot + 1, high, size);
		}

	}

}
/**
 * quick_sort - sorts an arr of int in ascd.Order using the Quick sort algo.
 * @array: pointer to the first element of the array to sort
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array)
		return;

	quick_sort_helper(array, 0, size - 1, size);
	print_array(array, size);
}
