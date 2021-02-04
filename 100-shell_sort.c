#include "sort.h"

/**
 * shell_sort - sorts int array with shell sort method
 * @array: input array
 * @size: size of array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	unsigned int i, j, gap = 1;
	int temp;

	if (size == 0 || size == 1 || array == NULL)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
