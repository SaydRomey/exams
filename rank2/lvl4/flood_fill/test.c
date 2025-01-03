
#include <stdlib.h>
#include <stdio.h>
#include "flood_fill.h"

char**	make_area(char** zone, t_point size)
{
	char**	new;
	int		i;
	int		j;

	new = malloc(sizeof(char*) * size.y);
	i = 0;
	while (i < size.y)
	{
		new[i] = malloc(size.x + 1);
		j = 0;
		while (j < size.x)
		{
			new[i][j] = zone[i][j];
			++j;
		}
		new[i][size.x] = '\0';
		++i;
	}

	return (new);
}

int	main(void)
{
	t_point	size = {8, 5};
	char	*zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char** 	area = make_area(zone, size);
	int		i = 0;
	while (i < size.y)
	{
		printf("%s\n", area[i]);
		++i;
	}
	printf("\n");

	t_point	begin = {7, 4};
	flood_fill(area, size, begin);
	i = 0;
	while (i < size.y)
	{
		printf("%s\n", area[i]);
		++i;
	}
	return (0);
}

/*
$> gcc flood_fill.c test.c -o test; ./test
11111111
10001001
10010001
10110001
11100001

FFFFFFFF
F000F00F
F00F000F
F0FF000F
FFF0000F
$>
*/
