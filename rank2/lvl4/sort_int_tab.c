
/*
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
*/

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

/* ************************************************************************** */

#include <stdio.h>

void	print_array(int *array, unsigned int size)
{
	unsigned int	i = 0;

	while (i < size)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
}

int	main(void)
{
	int				array[] = {1, 3, 2, 4, 3, 6, 9, 7, 8};
	unsigned int	size = sizeof(array) / sizeof(array[0]);

	printf("Original array:\t");
	print_array(array, size);
	sort_int_tab(array, size);
	printf("Sorted array:\t");
	print_array(array, size);
	return (0);
}

