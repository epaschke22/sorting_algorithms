#include "sort.h"
/**
* bubble_sort - sorts an array of integers in ascending
* order using the Bubble sort algorithm
* @array: doubly linked list head
* @size: The size of the array given
*/
void bubble_sort(int *array, size_t size)
{
	int swap = 0;
	int temp = 0;
	unsigned int idx = 0;

	while (swap != -1)
	{
		swap = 0;
		for (idx = 0; idx < size - 1; idx++)
			if (array[idx + 1] < array[idx])
			{
				/*swaps the elements*/
				temp = array[idx];
				array[idx] = array[idx + 1];
				array[idx + 1] = temp;
				/*adds one to swap to tell loop swap occured*/
				swap++;
				print_array(array, size);
			}
		/*breaks loop if no swaps are found*/
		if (swap == 0)
			break;
	}
}
