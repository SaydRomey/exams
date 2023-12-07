
/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdlib.h>

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int     *ft_range(int start, int end)
{
	int	size;
	int	*array;
	int	i;

	size = ft_abs(start - end) + 1;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (start < end)
		{
			array[i] = start;
			start++;
			i++;
		}
		else
		{
			array[i] = start;
			start--;
			i++;
		}
	}
	return (array);
}

/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	start;
	int	end;
	int	*array;
	int	i;
	int	size;

	if (argc == 3)
	{
		start = atoi(argv[1]);
		end = atoi(argv[2]);
		array = ft_range(start, end);
		size = ft_abs(end - start);
		i = 0;
		while (i < size)
		{
			printf("%d, ", array[i]);
			i++;
		}
		if (i > 0)
			printf("and ");
		printf("%d.", array[i]);
		free(array);
	}
	printf("\n");
	return (0);
}
