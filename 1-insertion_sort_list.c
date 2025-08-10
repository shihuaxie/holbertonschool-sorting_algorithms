#include "sort.h"

static void swap_adjacent(listint_t **list, listint_t *left, listint_t *right);

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *cur;
	listint_t *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	cur = (*list)->next;
	while (cur != NULL)
	{
		next = cur->next;

		while (cur->prev != NULL && cur->n < cur->prev->n)
		{
			swap_adjacent(list, cur->prev, cur);
			print_list(*list);
		}
		cur = next;
	}
}

/**
 * swap_adjacent - Swaps two adjacent nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @left: Left node
 * @right: Right node (must be left->next)
 */
static void swap_adjacent(listint_t **list, listint_t *left, listint_t *right)
{
	listint_t *a_prev;
	listint_t *b_next;

	a_prev = left->prev;
	b_next = right->next;

	if (a_prev != NULL)
		a_prev->next = right;
	right->prev = a_prev;

	right->next = left;
	left->prev = right;

	left->next = b_next;
	if (b_next != NULL)
		b_next->prev = left;

	if (a_prev == NULL)
		*list = right;
}
