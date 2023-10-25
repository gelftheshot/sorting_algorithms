#include "sort.h"

/**
 *
 *
 */
 void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}




void cocktail_sort_list(listint_t **list)
{

	listint_t *ptr = *list;
	listint_t *prev;
    listint_t *prev_prev;
    listint_t *next;
    listint_t *current;
	bool swap = true;
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (!(swap))
	{
		while(ptr->next)
		{
			if ((ptr->n) > (ptr->next->n))
			{
				swap_nodes(list, &ptr, (ptr->next));
				print_list(*list);
				swap = true;
			}
			ptr = ptr->next;
		}

	while(ptr->prev)
	{
		if (ptr && (ptr->n < ptr->prev->n))
		{

			current = ptr;
			prev = current->prev;
			prev_prev = prev->prev;
			next = current->next;
			if (prev_prev)
				prev_prev->next = current;
			else
				*list = ptr;
			current->prev = prev_prev;
			current->next = prev;
			prev->prev = current;
			prev->next = next;
			if (next)
				next->prev = prev;
			print_list(*list);
			swap = true;
		}
	}
}
}
