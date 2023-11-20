#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: the list to be sorted
 * doesn't return
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		node = current;
		while (node->prev != NULL && node->n < node->prev->n)
		{	/*swapping prev node with next node*/
			node->prev->next = node->next;
			if (node->next != NULL)
				node->next->prev = node->prev;

			node->next = node->prev;
			node->prev = node->prev->prev;
			if (node->prev != NULL)
				node->prev->next = node;

			node->next->prev = node;
			if (node->prev == NULL)
				*list = node;

			print_list(*list);
		}
		current = current->next;
	}

<<<<<<< HEAD
}
=======
}
>>>>>>> 183a793c3e7c13db8101feac176bc7b588bf04e5
