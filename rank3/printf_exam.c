
/*
Printf exam version

Write a function named ft_printf 
that will mimic the real printf 
but it will manage only the following conversions:

s (string)
d (decimal) 
x (lowercase hexademical)
*/

#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
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

int	ft_intlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

/*
string
*/
int	ft_putstrlen(char *str)
{
	int	len = 0;

	if (!str)
	{
		len = write(1, "(null)", 6);
		return (len);
	}
	len = write(1, str, ft_strlen(str));
	return (len);
}

/*
decimal
*/
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
	// return (ft_intlen(nbr));
	return (len);
}

/*
lower hex
*/
int	ft_puthexlen(int nbr)
{
	char	*digits = "0123456789abcdef";
	int		len = 0;

	if (nbr >= 16)
		len += ft_puthexlen(nbr / 16);
	len += ft_putcharlen(digits[nbr % 16]);
	return (len);
}

/*
or BOTH !!
*/
int	ft_put_nbr_baselen(int nbr, int base)
{
	char	*digits = "0123456789abcdef";
	int		len = 0;

	if (nbr == -2147483648)
		return (ft_putstrlen("-2147483648"));
	if (nbr < 0)
	{
		len += ft_putcharlen('-');
		nbr = -nbr;
	}
	if (nbr >= base)
		len += ft_put_nbr_baselen((nbr / base), base);
	len += ft_putcharlen(digits[nbr % base]);
	return (ft_intlen(nbr));
}

// 

static int	check_format(va_list args, char *str, int i)
{
	int	len = 0;

	if (str[i] == 's')
		len = ft_putstrlen(va_arg(args, char *));
	if (str[i] == 'd')
		len = ft_putnbrlen(va_arg(args, int));
		// len = ft_put_nbr_baselen(va_arg(args, int), 10);
	if (str[i] == 'x')
		len = ft_puthexlen(va_arg(args, unsigned int));
		// len = ft_put_nbr_baselen(va_arg(args, unsigned int), 16);
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
		if (str[i] == '%' && str[i + 1])
		{
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

/* -------------------------------------------------------------------------- */

#include <stdio.h>

int	main(void)
{
	int		len = 0;
	int		nbr = 42;
	char	*str;

	str = "four";
	// str = NULL;
	// str = "";


	len = ft_printf("%s", str);
	ft_printf("\tlen is %d\n", len);

	len = ft_printf("%d", nbr);
	ft_printf("\tlen is %d\n", len);
	len = ft_printf("%d", -nbr);
	ft_printf("\tlen is %d\n", len);

	len = ft_printf("%x", nbr);
	ft_printf("\tlen is %d\n", len);
	// 
	printf("\n");
	// 
	len = printf("%s", str);
	printf("\tlen is %d\n", len);

	len =printf("%d", nbr);
	printf("\tlen is %d\n", len);
	len =printf("%d", -nbr);
	printf("\tlen is %d\n", len);

	len = printf("%x", nbr);
	printf("\tlen is %d\n", len);
	// 
	return (0);
}
