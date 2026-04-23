#include "sort.h"

/**
 * selection_sort - sorts an array using selection sort
 * @array: the array to sort
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t min;
	int tmp;

	if (array == NULL || size < 2)
		return;

	i = 0;
	while (i < size - 1)
	{
		/* Find the minimum element in the unsorted part */
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min])
				min = j;
			j++;
		}

		/* Swap if minimum is not already in place */
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
