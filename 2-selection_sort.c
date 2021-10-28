#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers using selection
 * sort
 * @array: pointer to the array
 * @size: size of the array
 * Return: void at all times
 */
void selection_sort(int *array, size_t size)
{
	int temp, index_min, i, j, len = (int)size;

	if (array == NULL || size == 0)
		return;
	for (i = 0; i < (len - 1); i++)
	{
		index_min = i;
		for (j = (i + 1); j < len; j++)
		{
			if (array[j] < array[index_min])
				index_min = j;
		}
		temp = array[i];
		array[i] = array[index_min];
		array[index_min] = temp;
		print_array(array, size);
	}
}
