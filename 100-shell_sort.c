#include "sort.h"

/**
 * shell_sort - a function that sorts an array of integers
 * in ascending order using the Shell sort algorithm,
 * using the Knuth sequence
 * @array: the unsorted array
 * @size: the sizeof(array)
*/
void shell_sort(int *array, size_t size)
{

	int i, j, space;
	int tmp;

	if (!array || !size)
		return;

	/*creating the knuth sequence*/
	space = 1;
	while (space < (int)size / 3)
		space = space * 3 + 1;

	/*sorting with decreasing spaces*/
	while (space > 0)
	{
		for (i = space; i < (int)size; i++)
		{
			tmp = array[i];

			/*shift elements in  the sorted part*/
			for (j = i; j >= space && array[j - space] > tmp;)
			{
				array[j] = array[j - space];
				j -= space;
			}

			/*current element is placed right*/
			array[j] = tmp;
		}
		/*unto the next space in knuth*/
		space = (space - 1) / 3;
		print_array(array, size);
	}
}
