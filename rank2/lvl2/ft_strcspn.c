
#include <stddef.h>

/*
returns number of chars in the initial segment of 's' which are not in 'reject'
*/
// size_t	ft_strcspn(const char *s, const char *reject)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	while (s[i])
// 	{
// 		j = 0;
// 		while (reject[j])
// 		{
// 			if (s[i] == reject[j])
// 				return (i);
// 			j++;
// 		}
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

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (ft_strchr(reject, s[i]))
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
	char	*reject;

	if (argc == 3)
	{
		s = argv[1];
		reject = argv[2];
		printf("ft_strcspn: %zu\n", ft_strcspn(s, reject));
		printf("   strcspn: %zu\n", strcspn(s, reject));
	}
	else
		printf("Usage: %s <string> <reject>\n", argv[0]);
	return (0);
}
