
/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	print_first_word(char *str, int start)
{
	while (str[start] && !is_space(str[start]))
	{
		ft_putchar(str[start]);
		start++;
	}
}

void	rostring(char *str)
{
	int	i;
	int	start;

	start = 0;
	while (str[start] && is_space(str[start]))
		start++;
	i = start;
	while (str[i] && !is_space(str[i]))
		i++;
	while (str[i])
	{
		if (str[i] && !is_space(str[i]) && is_space(str[i - 1]))
		{
			while (str[i] && !is_space(str[i]))
			{
				ft_putchar(str[i]);
				i++;
			}
			ft_putchar(' ');
		}
		i++;
	}
	print_first_word(str, start);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		rostring(argv[1]);
	ft_putchar('\n');
	return (0);
}
