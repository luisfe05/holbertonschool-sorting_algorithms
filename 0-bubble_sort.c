#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using bubble sort
 * @array: the array to sort
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	/* Walk through the array repeatedly */
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			/* Swap if current element is greater than next */
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
			j++;
		}
		i++;
	}
}
