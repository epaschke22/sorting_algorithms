#include "sort.h"

/**
 * counting_sort - sorts int array with counting sort method
 * @array: input array
 * @size: size of array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int max = array[0], position, *count = NULL, *output = NULL;

	if (size == 0 || array == NULL)
		return;
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];
	print_array(count, (size_t)max + 1);

	for (i = 0; i < size; i++)
	{
		count[array[i]]--;
		position = count[array[i]];
		output[position] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
