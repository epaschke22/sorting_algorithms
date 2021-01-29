#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - sorts int array with bubble sort method
 * @array: input array
 * @size: size of array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, temp, flag = 0;

	while (flag != 1)
	{
		flag = 1;
		for (i = 0; i < size; i++)
			if (i < size - 1)
				if (array[i] > array[i + 1])
				{
					flag = 0;
					temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
					print_array(array, size);
				}
	}
}
