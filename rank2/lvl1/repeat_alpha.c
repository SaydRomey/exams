
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	letter_count(char c)
{
	int	count;

	count = 0;
	if (c >= 'a' && c <= 'z')
		count = c - 'a';
	else if (c >= 'A' && c <= 'Z')
		count = c - 'A';
	return (count + 1);
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
