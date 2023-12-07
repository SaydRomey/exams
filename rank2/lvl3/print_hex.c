
/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex(int nbr)
{
	char	*digits;

	digits = "0123456789abcdef";
	if (nbr >= 16)
		print_hex(nbr / 16);
	ft_putchar(digits[nbr % 15]);
}

int	main(int argc, char **argv)
{
	int	hex;

	if (argc == 2)
	{
		hex = ft_atoi(argv[1]);
		print_hex(hex);
	}
	ft_putchar('\n');
	return (0);
}
