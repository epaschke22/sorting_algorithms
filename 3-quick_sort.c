#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * partition - swaps values and changes positions
 * @arr: input array
 * @lo: begning of array
 * @hi: end of array
 * @size: size of array for printing
 * Return: void
 */
int partition(int *arr, int lo, int hi, size_t size)
{
	int i, j, temp, pivot;
	
	pivot = arr[hi];
	i = lo - 1;
	for (j = lo; j <= hi - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			if (arr[i] != arr[j])
				print_array(arr, size);
		}
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[hi];
	arr[hi] = temp;
	if (arr[i + 1] != arr[hi])
		print_array(arr, size);
	return (i + 1);
}

/**
 * sort - recursive calls to sort the array
 * @arr: input array
 * @lo: begning of array
 * @hi: end of array
 * @size: size of array for printing
 * Return: void
 */
void sort(int *arr, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(arr, lo, hi, size);
		sort(arr, lo, p - 1, size);
		sort(arr, p + 1, hi, size);
	}
}

/**
 * quick_sort - sorts int array with quick sort method
 * @array: input array
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	sort(array, 0, size - 1, size);
}
