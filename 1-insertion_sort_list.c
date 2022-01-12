#include "sort.h"

/**
 * swap - Swaps the nodes.
 *
 * @left: Node on the left.
 * @right: Node on the right.
 * @head: The head of the doubly linked list.
 */
void swap(listint_t *left, listint_t *right, listint_t **head)
{
	listint_t *temp;

	temp = left->prev;
	if (temp)
		temp->next = right;
	right->prev = temp;
	left->prev = right;
	left->next = right->next;
	right->next = left;
	if (right->prev == NULL)
		*head = right;
	if (left->next)
		left->next->prev = left;
	print_list(*head);
}

/**
 * insertion_sort_list - Sorts a linked list using insertion sort.
 *
 * @list: The doubly linked list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *nextnode, *prevnode, *temp;

	if (list == NULL)
		return;

	node = nextnode = *list;
	while (node)
	{
		while (node->prev)
		{
			prevnode = node->prev;
			temp = prevnode;
			if (prevnode->n > node->n)
				swap(prevnode, node, list);
			node = temp;
		}
		node = nextnode->next;
		nextnode = node;
	}
}