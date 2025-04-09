#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 *
 * @list: listint_t
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *left, *right;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current;
		while (temp->prev && temp->n < temp->prev->n)
		{
			left = temp->prev;
			right = temp;
			left->next = right->next;
			if (right->next)
				right->next->prev = left;
			right->prev = left->prev;
			right->next = left;
			if (left->prev)
				left->prev->next = right;
			else
				*list = right;
			left->prev = right;
			print_list(*list);
		}
		current = current->next;
	}
}
