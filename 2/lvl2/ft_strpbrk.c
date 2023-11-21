
#include <stddef.h>

// char	*ft_strpbrk(const char *s1, const char *s2)
// {
// 	size_t	i;

// 	while (*s1)
// 	{
// 		i = 0;
// 		while (s2[i])
// 		{
// 			if (*s1 == s2[i])
// 				return ((char *)s1);
// 			i++;
// 		}
// 		s1++;
// 	}
// 	return (NULL);
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

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr(s2, s1[i]))
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	char	*s1;
	char	*s2;
	char	*ret;

	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];
		ret = ft_strpbrk(s1, s2);
		printf("s1: %s\n", s1);
		printf("s2: %s\n", s2);
		printf("ret: %s\n", ret);
	}
	printf("\n");
	return (0);
}
