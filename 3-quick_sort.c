#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @a: pointer to first integer
 * @b: pointer to second integer
 * @array: the full array for printing
 * @size: size of the array
 */
void swap(int *a, int *b, int *array, size_t size)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	print_array(array, size);
}

/**
 * lomuto_partition - partitions array using Lomuto scheme
 * @array: the array to partition
 * @lo: left index
 * @hi: right index
 * @size: full size of array for printing
 *
 * Return: index of the pivot after partition
 */
int lomuto_partition(int *array, int lo, int hi, size_t size)
{
	int pivot;
	int i;
	int j;

	pivot = array[hi];
	i = lo - 1;
	j = lo;

	while (j < hi)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
				swap(&array[i], &array[j], array, size);
		}
		j++;
	}
	if (i + 1 != hi)
		swap(&array[i + 1], &array[hi], array, size);

	return (i + 1);
}

/**
 * quicksort - recursive helper for quick sort
 * @array: the array to sort
 * @lo: left index
 * @hi: right index
 * @size: full size of array for printing
 */
void quicksort(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = lomuto_partition(array, lo, hi, size);
		quicksort(array, lo, pivot - 1, size);
		quicksort(array, pivot + 1, hi, size);
	}
}

/**
 * quick_sort - sorts an array using quick sort with Lomuto partition
 * @array: the array to sort
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, (int)size - 1, size);
}
