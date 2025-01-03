
int		max(int* tab, unsigned int len)
{
	unsigned int	i;
	int				max;

	if (len <= 0 || !tab)
		return (0);
	i = 0;
	max = tab[0];
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	tab[] = {1, 2, 3, 12, 5, 6, 7, 8, 9};
	printf("%d\n", max(tab, 9));
	return (0);
}
