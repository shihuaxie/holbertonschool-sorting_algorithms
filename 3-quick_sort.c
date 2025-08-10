#include "sort.h"

/**
 * swap_ints - Swap the values of two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
static void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Pointer to the array
 * @size: Total size of the array (used for printing)
 * @low: Starting index of the subarray to partition
 * @high: Ending index of the subarray to partition (pivot position)
 *
 * Description:
 * - Uses the last element as pivot.
 * - Moves all elements smaller than pivot to the left of pivot.
 * - Moves all elements greater than or equal to pivot to the right.
 * - Prints the array every time a swap occurs.
 *
 * Return: The index where the pivot is finally placed.
 */

static int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				if (array[i] != array[j])
					print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap_ints(&array[i + 1], &array[high]);
		if (array[i + 1] != array[high])
			print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursively applies Quick sort
 * @array: Pointer to the array
 * @size: Total size of the array (used for printing)
 * @low: Starting index of the current subarray
 * @high: Ending index of the current subarray
 *
 * Description:
 * - Recursively sorts elements before and after partition index.
 * - Stops recursion when subarray size is less than 2.
 */
static void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	int p;

	if (low < high)
	{
		/* Partition the array and get the pivot index */
		p = lomuto_partition(array, size, low, high);

		/* Sort left subarray */
		quick_sort_recursive(array, size, low, p - 1);

		/* Sort right subarray */
		quick_sort_recursive(array, size, p + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition scheme)
 * @array: Pointer to the array
 * @size: Number of elements in @array
 *
 * Description:
 * - Calls the recursive helper function.
 * - Returns immediately if array is NULL or has less than 2 elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, size, 0, (int)size - 1);
}

