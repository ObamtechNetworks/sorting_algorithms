#include "sort.h"
<<<<<<< HEAD
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
 * bubble_sort - sorts an array of int in asc using the bubble_sort algo.
 * @array: pointer to the first integer in the array
 * @size: the size of the array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	/*initialize two variable*/
	int isswapped; /*like a flag or boolean to detect if val isswaped*/
	size_t cur_index; /*the current index of the array while traversing*/

	/*edge cases*/
	if (!array || !size)
		return;

	/*set isswapped = true and enter a while loop */
	isswapped = 1;

	while (isswapped)
	{
		/*set swapped value to false, a way to break out of the loop*/
		isswapped = 0;
		cur_index = 0;
		/*start traverssing*/
		while (cur_index < size - 1)
		{
			if (array[cur_index] > array[cur_index + 1])
			{
				swap(&array[cur_index], &array[cur_index + 1]);
				isswapped = 1;
				print_array(array, size);
			}
			cur_index++;
		}
	}
}
=======

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
>>>>>>> 183a793c3e7c13db8101feac176bc7b588bf04e5
