#include "sort.h"
/**
* swap_nodes -swaps two given nodes
* @head: doubly linked list head for printing
* @swap1: node in first postion (1, 2) would be 1
* @swap2: node in second position (1, 2) would be 2
*/
void swap_nodes(listint_t **head, listint_t *swap1, listint_t *swap2)
{
	listint_t *next_hold, *prev_hold;

	next_hold = swap2->next;
	prev_hold = swap1->prev;
	swap1->prev = swap2;
	swap1->next = next_hold;
	swap2->prev = prev_hold;
	swap2->next = swap1;
	if (next_hold != NULL)
		next_hold->prev = swap1;
	if (prev_hold != NULL)
		prev_hold->next = swap2;
	if (prev_hold == NULL)
		*head = swap2;
	print_list(*head);
}
/**
* cocktail_sort_list - sorts an array of integers in ascending
* order backwards and forwards
* order using the cocktail sort algorithm
* @list: doubly linked list head
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *start_head, *end_head, *temp_head;
	int count = 0, i = 0;
	int sorted = 0; /*0 when not sorted, 1 when sorted*/

	if (list == NULL)
		return;

	while (sorted != -1)
	{
		start_head = *list;
		end_head = *list;
		while (end_head->next != NULL)
			end_head = end_head->next;
		for (i = 0; i < count; i++)
		{
			start_head = start_head->next;
			end_head = end_head->prev;
		}
		temp_head = start_head;
		sorted = 0;
		while (temp_head != NULL)
		{
			if (temp_head->next != NULL && temp_head->n > temp_head->next->n)
			{
				swap_nodes(&*list, temp_head, temp_head->next);
				temp_head = temp_head->prev;
				sorted++;
			}
			temp_head = temp_head->next;
		}

		if (sorted == 0)
			break;
		sorted = 0;
		temp_head = end_head;
		while (temp_head != NULL)
		{
			if (temp_head->prev != NULL && temp_head->n < temp_head->prev->n)
			{
				swap_nodes(&*list, temp_head->prev, temp_head);
				sorted++;
				temp_head = temp_head->next;
			}
			temp_head = temp_head->prev;
		}
		count++;
	}
}
