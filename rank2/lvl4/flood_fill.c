
#include "flood_fill.h"

void    actual_flood_fill(char **tab, t_point size, int x, int y, char to_fill)
{
	// If we're out of bounds, or the point is not of the color we're looking to fill, return.
	if (x < 0 || x >= size.x || y < 0 || y >= size.y || tab[y][x] != to_fill)
		return;

	// Fill the point
	tab[y][x] = 'F';

	// Recursive calls for the adjacent points
	actual_flood_fill(tab, size, x + 1, y, to_fill); // Right
	actual_flood_fill(tab, size, x - 1, y, to_fill); // Left
	actual_flood_fill(tab, size, x, y + 1, to_fill); // Down
	actual_flood_fill(tab, size, x, y - 1, to_fill); // Up
}

void    flood_fill(char **tab, t_point size, t_point begin)
{
	// Begin the flood fill from the starting point with the initial color
	actual_flood_fill(tab, size, begin.x, begin.y, tab[begin.y][begin.x]);
}
