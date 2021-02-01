#include "sort.h"
/**
*insertion_sort_list - sorts a linked list using insertion sort
*@list: head to to be sorted list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *temp_head = NULL, *check_head = NULL;
	listint_t *next_hold = NULL, *swap_head = NULL, *prev_hold;

	if (list == NULL)
		return;
	temp_head = (*list)->next;
	while (temp_head != NULL)
	{
		swap_head = temp_head;
		check_head = temp_head;
		while (check_head != NULL)
		{
			if (check_head->n > temp_head->n)/*check19, swap12*/
			{
				next_hold = swap_head->next;
				prev_hold = check_head->prev;
				check_head->prev = swap_head;
				check_head->next = next_hold;
				swap_head->prev = prev_hold;
				swap_head->next = check_head;
				if (next_hold != NULL)
					next_hold->prev = check_head;
				if (prev_hold != NULL)
					prev_hold->next = swap_head;
				if (prev_hold == NULL)
					*list = swap_head;
				print_list(*list);
			}
			check_head = check_head->prev;
		}
		temp_head = temp_head->next;
	}
}
