
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	replace_letter(char *str, char to_replace, char new_char)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == to_replace)
			str[i] = new_char;
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		replace_letter(argv[1], argv[2][0], argv[3][0]);
	ft_putchar('\n');
	return (0);
}
