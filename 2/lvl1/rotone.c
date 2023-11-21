
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	rot_char_one(char c)
{
	if ((c >= 'A' && c <= 'Y') || (c >= 'a' && c <= 'y'))
		return (c + 1);
	else if (c == 'Z' || c == 'z')
		return (c - 25);
	else
		return (c);
}

void	rot_one(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = rot_char_one(str[i]);
		ft_putchar(c);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		rot_one(argv[1]);
	ft_putchar('\n');
	return (0);
}
