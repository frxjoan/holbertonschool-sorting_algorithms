#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list using Insertion Sort
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		tmp = current;
		current = current->next;

		while (tmp->prev != NULL && tmp->prev->n > tmp->n)
		{
			listint_t *prev = tmp->prev;
			listint_t *next = tmp->next;

			if (prev->prev != NULL)
				prev->prev->next = tmp;
			tmp->prev = prev->prev;

			tmp->next = prev;
			prev->prev = tmp;

			prev->next = next;
			if (next != NULL)
				next->prev = prev;

			if (tmp->prev == NULL)
				*list = tmp;

			print_list(*list);
		}
	}
}
