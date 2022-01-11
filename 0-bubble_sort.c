#include "sort.h"

/**
 * bubble_sort - Sorts an array using bubble sort.
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t index;
	int swapped;

	swapped = check_sort(array, size);
	while (swapped == 0)
	{
		for (index = 1; index < size; ++index)
		{
			if (array[index - 1] > array[index])
			{
				array[index - 1] ^= array[index];
				array[index] ^= array[index - 1];
				array[index - 1] ^= array[index];
				print_array(array, size);
			}
			swapped = check_sort(array, size);
		}
	}
}

/**
 * check_sort - Checks if array is sorted.
 *
 * @array: The array to be checked.
 * @size: The size of the array.
 *
 * Return: 1 if sorted, otherwise, 0.
 */
int check_sort(int *array, size_t size)
{
	size_t index;
	int boolean = 0;

	for (index = 1; index < size; ++index)
	{
		if (array[index - 1] > array[index])
		{
			boolean = 0;
			break;
		}
		boolean = 1;
	}
	return (boolean);
}