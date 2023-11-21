
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	letter_count(char c)
{
	int	count;

	count = 1;
	if (c >= 'a' && c <= 'z')
		count = c - 'a' + 1;
	else if (c >= 'A' && c <= 'Z')
		count = c - 'A' + 1;
	return (count);
}

void	repeat_alpha(char *str)
{
	int	i;
	int	count;

	i = 0;
	while (str[i])
	{
		count = letter_count(str[i]);
		while (count > 0)
		{
			ft_putchar(str[i]);
			count--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	ft_putchar('\n');
	return (0);
}
