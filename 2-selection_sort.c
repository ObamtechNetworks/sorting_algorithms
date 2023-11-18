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
 * selection_sort - sorts an array of int in asc using the selection_sort algo.
 * @array: pointer to the first integer in the array
 * @size: the size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	/*initialize three variable*/
	size_t travs_idx, counter, min_idx;

	/*edge cases*/
	if (!array || !size)
		return;

	/*initialize 3 variables*/
	counter = 0; /*to keep track of which position we currently are*/
	min_idx = counter; /*an integer to store idx of cur min. value*/
	travs_idx = 1 + counter; /*needed for comp. index ahead of cur count idx*/

	while (counter < size - 1) /*for the unsorted part of the list*/
	{
		while (travs_idx < size) /*for comparing elem above vs cur min el*/
		{ /*if the val at trav.idx is less than cur min value, exchange*/
			if (array[travs_idx] < array[min_idx])
				min_idx = travs_idx;
			travs_idx++; /*keep exchanging thru the first pass of the array*/
		}
		/*swap and print only if cur elem is not already the smallest*/
		if (counter != min_idx)
		{
			swap(&array[counter], &array[min_idx]);
			print_array(array, size);
		}
		counter++; /*increase counter*/
		min_idx = counter;/*set min_idx to cur counter*/
		travs_idx = 1 + counter; /*set travs_idx 1 step ahead of counter*/
	}
}
