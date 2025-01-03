
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}

void	put_first_word(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] && (ft_isspace(str[i]) == 0))
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		put_first_word(argv[1]);
	ft_putchar('\n');
	return (0);
}

