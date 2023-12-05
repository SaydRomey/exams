
/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

char	ft_tolower(char c)
{
	if	(c >= 'A' && c <= 'Z')
		return (c + ' ');
	return (c);
}

int	get_digit(char c)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	result;
	int	sign;
	int	digit;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		digit = get_digit(ft_tolower(str[i]));
		if (digit == -1 || digit >= str_base)
			break ;
		result = result * str_base;
		result = result + digit;
		i++;
	}
	return (result * sign);
}

/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int		str_base;
	char	*str;
	int		result;

	if (argc == 3)
	{
		str = argv[1];
		str_base = atoi(argv[2]);
		result = ft_atoi_base(str, str_base);
		printf("%d", result);
	}
	printf("\n");
	return (0);
}
