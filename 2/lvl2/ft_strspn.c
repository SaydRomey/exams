
#include <stddef.h>

// size_t	ft_strspn(const char *s, const char *accept)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	while (s[i])
// 	{
// 		j = 0;
// 		while (accept[j])
// 		{
// 			if (s[i] == accept[j])
// 				break ;
// 			j++;
// 		}
// 		if (!accept[j])
// 			return (i);
// 		i++;
// 	}
// 	return (i);
// }

/* ************************************************************************** */

static char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (!ft_strchr(accept, s[i]))
			break ;
		i++;
	}
	return (i);
}

/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	char	*s;
	char	*accept;

	if (argc == 3)
	{
		s = argv[1];
		accept = argv[2];
		printf("%zu\n", ft_strspn(s, accept));
		printf("%zu\n", strspn(s, accept));
	}
	return (0);
}
