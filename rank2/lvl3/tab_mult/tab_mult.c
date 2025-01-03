
/*
Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>
*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		ft_putchar(c);
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	digit;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		digit = str[i] - '0';
		result = result * 10;
		result = result + digit;
		i++;
	}
	return (result);
}

void	print_mult_line(int mult, int nbr, int result)
{
	ft_putnbr(mult);
	ft_putstr(" x ");
	ft_putnbr(nbr);
	ft_putstr(" = ");
	ft_putnbr(result);
	ft_putchar('\n');
}

void	tab_mult(int nbr)
{
	int	mult;
	int	result;

	mult = 1;
	while (mult < 10)
	{
		result = mult * nbr;
		print_mult_line(mult, nbr, result);
		mult++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (ft_putchar('\n'), 0);
	else
		tab_mult(ft_atoi(argv[1]));
	return (0);
}
