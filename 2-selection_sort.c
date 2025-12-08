#include "sort.h"
/**
 * selection_sort - Doubly linked list node
 *
 * @array: given array
 * @size: size
 */
void selection_sort(int *array, size_t size)
{
	unsigned long int i, j, tmp;
	int min;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		tmp = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				tmp = j;
			}
		}
		if (tmp != i)
		{
			array[tmp] = array[i];
			array[i] = min;
			print_array(array, size);
		}
	}
}
