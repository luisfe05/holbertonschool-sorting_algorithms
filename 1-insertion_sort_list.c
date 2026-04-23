#include "sort.h"

/**
 * swap_nodes - swaps two adjacent nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @node: the node to move backward
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *prev;

	prev = node->prev;

	/* Update prev of prev node */
	if (prev->prev)
		prev->prev->next = node;
	else
		*list = node;

	/* Update next of next node */
	if (node->next)
		node->next->prev = prev;

	/* Swap the two nodes */
	node->prev = prev->prev;
	prev->next = node->next;
	node->next = prev;
	prev->prev = node;
}

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* Start from second node */
	current = (*list)->next;
	while (current != NULL)
	{
		/* Move current node backward while it's smaller than previous */
		while (current->prev != NULL && current->n < current->prev->n)
		{
			swap_nodes(list, current);
			print_list(*list);
		}
		current = current->next;
	}
}
