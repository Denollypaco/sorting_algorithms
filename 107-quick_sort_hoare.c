#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition - This is Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: This is the array of integers.
 * @size: This is the size of the array.
 * @left: This is the starting index of the subset to order.
 * @right: This is the ending index of the subset to order.
 *
 * Return: This is the final partition index.
 *
 * Description: This uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - This Implements the quicksort algorithm through recursion.
 * @array: This is an array of integers to sort.
 * @size: This is the size of the array.
 * @left: This is the starting index of the array partition to order.
 * @right: This is the ending index of the array partition to order.
 *
 * Description: This uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - This Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: This is an array of integers.
 * @size: This the size of the array.
 *
 * Description: This uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
