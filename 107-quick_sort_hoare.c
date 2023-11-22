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
 * hoare_partition - partitions the array using hoare partition scheme
 * @array: the array to partition
 * @low: the index of the lowest element in the list
 * @high: the index of the highest element in the list
 * @size: the size of the array
 * Return: returns the low_idx, which is actually the pivot
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high]; /*select the last el as computed in main func*/
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);

		if (i > j)
		{
			return (j);
		}
		if (i != j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	return (-1);
}

/**
 * quick_sort_helper - sorts an arr of int using hoare partition scheme
 * @array: pointer to the first element of the array to sort
 * @low: the lower bound of the array
 * @high: the higher/upper bound of the array
 * @size: size of the array
 * Return: void
 */
void quick_sort_util(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high, size);
		quick_sort_util(array, low, pivot, size);
		quick_sort_util(array, pivot + 1, high, size);

	}

}
/**
 * quick_sort_hoare - sorts arr of int in ascd.Order using the Quick sort algo
 * @array: pointer to the first element of the array to sort
 * @size: size of the array
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array)
		return;

	quick_sort_util(array, 0, size - 1, size);
}
