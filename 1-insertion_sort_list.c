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
 * insertion_sort_list - sorts a dbly linked list of int in asc using ins sort
 * @list: the linked list to sort
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *next = NULL, *temp = NULL;

	/*edge cases*/
	if (!list || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next; /*start from second node*/
	while (current)
	{
		next = current->next;
		while (current->prev && current->prev->n > current->n)
		{
			temp = current->prev; /*previous node*/

			if (temp->prev) /*if there's an element behind prev node*/
				/*set the elem behind to current*/
				temp->prev->next = current; /*do swapping*/
			else
				*list = current; /*else set to be the first node*/

			if (current->next != NULL)
				current->next->prev = temp;

			current->prev = temp->prev;
			temp->next = current->next;
			current->next = temp;
			temp->prev = current;
			/*print list at end of first move*/
			print_list(*list);
		}
		current = next;
	}
}
