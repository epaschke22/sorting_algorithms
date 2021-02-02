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
 * sort_forward - sorts our linked list by looping forward
 * @list: used to print the list after each node swap
 * @temp_head: Our current head to the unsorted portion of our linked list
 * Return: returns 1 if swapped and 0 if not
 */
int sort_forward(listint_t **list, listint_t *temp_head)
{
	int swap = 0;

	while (temp_head != NULL)
	{
		if (temp_head->next != NULL && temp_head->n > temp_head->next->n)
		{
			swap_nodes(&*list, temp_head, temp_head->next);
			temp_head = temp_head->prev;
			swap++;
		}
		temp_head = temp_head->next;
	}
	return (swap);
}
/**
 * sort_backward - sorts our linked list by looping backward
 * @list: used to print the list after each node swap
 * @temp_head: Our current head to the unsorted portion of our linked list
 * Return: returns 1 if swapped and 0 if not
 */
int sort_backward(listint_t **list, listint_t *temp_head)
{
	int swap = 0;

	while (temp_head != NULL)
	{
		if (temp_head->prev != NULL && temp_head->n < temp_head->prev->n)
		{
			swap_nodes(&*list, temp_head->prev, temp_head);
			swap++;
			temp_head = temp_head->next;
		}
		temp_head = temp_head->prev;
	}
	return (swap);
}
/**
* cocktail_sort_list - sorts an array of integers in ascending
* order backwards and forwards
* order using the cocktail sort algorithm
* @list: doubly linked list head
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *start_head, *end_head, *temp_head; /*where each loop will start*/
	int sorted_count = 0, i = 0; /*keeps track of sorted part of list*/
	int sorted = 0; /*0 when not sorted, 1 when sorted*/

	if (list == NULL)
		return;

	while (sorted != -1)
	{
		/*set our start and end heads to start of the unsorted ends of list*/
		start_head = *list;
		end_head = *list;
		while (end_head->next != NULL) /*makes end_head equal to tail*/
			end_head = end_head->next;
		for (i = 0; i < sorted_count; i++)
		{
			start_head = start_head->next;
			end_head = end_head->prev;
		}
		/*sorts the list forward*/
		sorted = 0;
		temp_head = start_head;
		sorted = sort_forward(&*list, temp_head);
		/*checks if the list is sorted*/
		if (sorted == 0)
			break;
		/*sorts the list backward*/
		sorted = 0;
		temp_head = end_head;
		sorted = sort_backward(&*list, temp_head);
		/*adds one to our end / start count varaible*/
		sorted_count++;
	}
}
