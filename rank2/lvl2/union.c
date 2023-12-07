
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_unique(char c, int printed[])
{
	if (printed[(int)c] == 0)
	{
		printed[(int)c] = 1;
		return (1);
	}
	return (0);
}

void	print_unique(char *str, int printed[])
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_unique(str[i], printed))
			ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	printed[128] = {0};

	if (argc == 3)
	{
		print_unique(argv[1], printed);
		print_unique(argv[2], printed);
	}
	ft_putchar('\n');
}
