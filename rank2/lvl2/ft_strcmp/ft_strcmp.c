
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else
			i++;
	return (0);
}

/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "Hell0";
	s2 = "Hello";
	printf("%d\n", ft_strcmp(s1, s2));
	return (0);
}
