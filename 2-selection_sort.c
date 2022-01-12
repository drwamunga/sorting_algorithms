#include "sort.h"

/**
 * selection_sort - Sorts an array using selection sort.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t idx, j, t, min;

	for (idx = 0; idx < size - 1; ++idx)
	{
		min = idx;
		for (j = idx + 1; j < size; ++j)
			if (array[j] < array[min])
				min = j;
		if (min != idx)
		{
			t = array[min];
			array[min] = array[idx];
			array[idx] = t;
			print_array(array, size);
		}
	}

}