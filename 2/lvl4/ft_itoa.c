
/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

#include <stdlib.h>

int	int_len(int n)
{
	int len;
	
	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*itoa_min(char *str)
{
	int		i;
	char	*min_str;

	i = 0;
	min_str = "-2147483648";
	while (min_str[i] != '\0')
	{
		str[i] = min_str[i];
		i++;
	}
	return (str);
}

char *ft_itoa(int nbr) 
{
	int		len;
	char	*str;

	len = int_len(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (nbr == -2147483648)
		return (itoa_min(str));
	str[len] = '\0';
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		len--;
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

/* ************************************************************************** */

#include <stdio.h>

int main(int argc, char **argv)
{
	int		nbr;
	char	*result;

	if (argc == 2)
	{
		nbr = atoi(argv[1]);
		result = ft_itoa(nbr);
		if (result)
		{
			printf("%s", result);
			free(result);
		}
	}
	printf("\n");
	return (0);
}
