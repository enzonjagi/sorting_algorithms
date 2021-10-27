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
 * bubble_sort - function that sorts elements using bubble sort
 * @array: the array to be sorted
 * @size: the size of the above array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int i, j, length = (int) size;

	if ((array == NULL) || (size < 2))/*NULL check*/
		exit(1);
	for (i = 0; i < length - 1; i++)
	{
		for (j = 0; j < length - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_items(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
