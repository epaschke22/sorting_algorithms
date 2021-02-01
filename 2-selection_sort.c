#include "sort.h"
/**
*selection_sort - sorts an array of integers in ascending
* order using the Selection sort algorithm
* @array: array of integers given
* @size: size of array given
*/
void selection_sort(int *array, size_t size)
{
	size_t idx = 0, passes = 0;
	int small_idx = 0, hold = 0;

	for (passes = 0; passes < size; passes++)
	{
		small_idx = passes;
		for (idx = passes; idx < size; idx++)
		{
			if (array[idx] < array[small_idx])
				small_idx = idx;
		}
		if (array[passes] != array[small_idx])
		{
			hold = array[passes];
			array[passes] = array[small_idx];
			array[small_idx] = hold;
			print_array(array, size);
		}
	}
}
