/*
Assignment name  : ft_printf
Expected files   : ft_printf.c
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
--------------------------------------------------------------------------------

Write a function named `ft_printf` that will mimic the real printf but
it will manage only the following conversions: s,d and x.

Your function must be declared as follows:

int ft_printf(const char *, ... );

Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
To test your program compare your results with the true printf.

Exemples of the function output:

call: ft_printf("%s\n", "toto");
out: toto$

call: ft_printf("Magic %s is %d", "number", 42);
out: Magic number is 42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
out: Hexadecimal for 42 is 2a$
*/

#include <unistd.h> 
#include <stdarg.h> 

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int	ft_putcharlen(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstrlen(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putnbrlen(int nbr)
{
	char	*digits = "0123456789";
	int		len = 0;

	if (nbr == -2147483648)
		return (ft_putstrlen("-2147483648"));
	if (nbr < 0)
	{
		len += ft_putcharlen('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		len += ft_putnbrlen(nbr / 10);
	len += ft_putcharlen(digits[nbr % 10]);
	return (len);
}

int	ft_puthexlen(unsigned int nbr)
{
	char	*digits = "0123456789abcdef";
	int		len = 0;

	if (nbr >= 16)
		len += ft_puthexlen(nbr / 16);
	len += ft_putcharlen(digits[nbr % 16]);
	return (len);
}

int ft_printf(const char *str, ... )
{
	va_list	args;
	int		len = 0;
	int		i = 0;

	if (!str)
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if ((str[i + 1]) == 's' || str[i + 1] == 'd' || str[i + 1] == 'x')
			{
				if (str[i + 1] == 's')
					len += ft_putstrlen(va_arg(args, char *));
				if (str[i + 1] == 'd')
					len += ft_putnbrlen(va_arg(args, int));
				if (str[i + 1] == 'x')
					len += ft_puthexlen(va_arg(args, unsigned int));
			}
			i++;
		}
		else
			len += ft_putcharlen(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

/* alt version, just to make it pretty

int	is_valid_specifier(int c)
{
	if (c == 's' || c == 'd' || c == 'x')
		return (1);
	return (0);
}

int	check_format(va_list args, char *str, int i)
{
	int	len = 0;

	if (str[i] == 's')
		len = ft_putstrlen(va_arg(args, char *));
	if (str[i] == 'd')
		len = ft_putnbrlen(va_arg(args, int));
	if (str[i] == 'x')
		len = ft_puthexlen(va_arg(args, unsigned int));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i = 0;
	int		len = 0;
	va_list	args;

	if (!str)
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (is_valid_specifier(str[i + 1]))
				len += check_format(args, (char *)str, i + 1);
			i++;
		}
		else
			len += ft_putcharlen(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
*/

/* -------------------------------------------------------------------------- */

// #include <stdio.h>

// int	main(void)
// {
// 	int	nbr = -2147483648;
// 	int	len = 0;

// 	printf("\n\nprintf\n\n");
// 	len = printf("deci -> %d\n", nbr);
// 	printf("len = %d\n", len);
// 	len = printf("hexa -> %x\n", nbr);
// 	printf("len = %d\n", len);


// 	ft_printf("\n\nft_printf\n\n");
// 	len = ft_printf("deci -> %d\n", nbr);
// 	ft_printf("len = %d\n", len);
// 	len = ft_printf("hexa -> %x\n", nbr);
// 	ft_printf("len = %d\n", len);

// 	printf("\n\n");

// 	return (0);
// }
