
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= ' ';
	return (c);
}

void	snake_to_camel(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '_')
		{
			i++;
			str[i] = ft_toupper(str[i]);
		}
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		snake_to_camel(argv[1]);
	ft_putchar('\n');
	return (0);
}
