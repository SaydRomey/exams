
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_isupper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + ' ');
	return (c);
}

/* ************************************************************************** */

void	camel_to_snake(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isupper(str[i]))
			ft_putchar('_');
		ft_putchar(ft_tolower(str[i]));
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		camel_to_snake(argv[1]);
	ft_putchar('\n');
	return (0);
}
