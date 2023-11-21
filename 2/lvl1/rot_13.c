
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	rot_char_13(char c)
{
	if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
		return (c + 13);
	else if ((c >= 'N' && c <= 'Z') || (c >= 'n' && c <= 'z'))
		return (c - 13);
	else
		return (c);
}

void	rot_13(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		// ft_putchar(rot_char_13(str[i]));
		c = rot_char_13(str[i]);
		ft_putchar(c);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		rot_13(argv[1]);
	ft_putchar('\n');
	return (0);
}
