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
