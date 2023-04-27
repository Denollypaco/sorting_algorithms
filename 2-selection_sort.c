#include "sort.h"

/**
 * swap_ints - This Swaps two integers in an array.
 * @a: This is the first integer to swap.
 * @b: This is the second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - This Sorts an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: This is an array of integers.
 * @size: This is the size of the array.
 *
 * Description: This Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
