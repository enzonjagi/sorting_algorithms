#include "sort.h"
/**
 * swap_items - function that swaps elements for bubble sort
 * @x: element one pointer
 * @y: element two pinter
 * Return: void
 */

void swap_items(int *x, int *y)
{
	int temp = 0;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * l_part - lomuto partitioning
 * @array: the array
 * @start: the start of the array
 * @end: the end of the array
 * @size: the size of the array
 * Return: int
 */
int l_part(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int part_index = (start - 1);
	int i;

	for (i = start; i <= (end - 1); i++)
	{
		if (array[i] <= pivot)
		{
			part_index++;
			swap_items(&array[part_index], &array[i]);
			print_array(array, size);
		}
	}
	swap_items(&array[part_index + 1], &array[end]);
	return (part_index + 1);
}
/**
 * actual_quick_sort - the quick sort operation function for recursion
 * @array: the array pointer
 * @start: the start index of the array
 * @end: the end index of the array
 * @size: size of array
 * Return: void
 */
void actual_quick_sort(int *array, int start, int end, size_t size)
{
	int part_index;

	if (start >= end)
		return;
	part_index = l_part(array, start, end, size);
	if (part_index - start > 1)
		actual_quick_sort(array, start, part_index - 1, size);
	if (end - part_index > 1)
		actual_quick_sort(array, part_index + 1, end, size);
}

/**
 * quick_sort - function that sorts an array of integers using Quicksort
 * @array: pointer to the array
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	actual_quick_sort(array, 0, (int)size - 1, size);
}
