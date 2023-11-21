#include "sort.h"

void swap_nodes(listint_t **list, listint_t **lower, listint_t **higher);

/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: the unsorted list
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (!list || !(*list) || !((*list)->next))
		return;

	while (swapped)
	{
		swapped = 0;
		current = *list;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &current, &(current->next));
				/*print_list(*list);*/
				swapped = 1;
			} else
				current = current->next;
		}

		if (!swapped)
			break;

		swapped = 0;
		current = current->prev;

		while (current != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, &(current->prev), &current);
				/*print_list(*list);*/
				swapped = 1;
			} else
				current = current->prev;
		}
	}
}

/**
 * swap_nodes - helper funtion to swap nodes
 * @list: original list
 * @lower: node to be swapped
 * @higher: seconed node to be swapped
*/
void swap_nodes(listint_t **list, listint_t **lower, listint_t **higher)
{
	listint_t *temp;

	if (!(*lower) || !(*higher))
		return;

	if ((*lower)->prev != NULL)
		(*lower)->prev->next = *higher;
	else
		*list = *higher;

	if ((*higher)->next != NULL)
		(*higher)->next->prev = *lower;

	temp = (*higher)->next;
	(*higher)->next = *lower;
	(*lower)->prev = (*higher)->prev;
	(*higher)->prev = *lower;
	(*lower)->next = temp;
}
