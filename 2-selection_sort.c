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
    int small = 0, small_idx = 0, hold = 0;

    for (passes = 0; passes < size - 1; passes++)
    {
        small = array[passes];
        for (idx = passes; idx < size; idx++)
        {
            if (array[idx] < small)
            {
                small = array[idx];
                small_idx = idx;
            }
        }
        if (array[passes] != small)
        {
            hold = array[passes];
            array[passes] = small;
            array[small_idx] = hold;
            print_array(array, size);
        }
    }
}