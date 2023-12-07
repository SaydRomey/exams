
#include <stdlib.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dupped;

	len = ft_strlen(src);
	dupped = malloc(len + 1);
	if (!dupped)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dupped[i] = src[i];
		i++;
	}
	dupped[i] = '\0';
	return (dupped);
}

/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*dupped;

	if (argc == 2)
	{
		dupped = ft_strdup(argv[1]);
		printf("dupped: %s", dupped);
		free(dupped);
	}
	printf("\n");
	return (0);
}