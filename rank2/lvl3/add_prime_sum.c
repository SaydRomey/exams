
/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <stdlib.h>
#include <unistd.h>

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
		write(1, &c, 1);
	}
}

int		ft_isprime(int nbr)
{
	int	check;

	check = 2;
	if (nbr <= 1)
		return (0);
	while (check < nbr)
	{
		if (nbr % check == 0)
			return (0);
		check++;
	}
	return (1);
}

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

int	add_prime_sum(char *str)
{
	int	nbr;
	int	sum;

	nbr = ft_atoi(str);
	sum = 0;
	while (nbr > 0)
	{
		if (ft_isprime(nbr))
			sum += nbr;
		nbr--;
	}
	return (sum);
}

int	main(int argc, char **argv)
{
	int	sum;

	sum = 0;
	if (argc == 2)
		sum = add_prime_sum(argv[1]);
	ft_putnbr(sum);
	write(1, "\n", 1);
	return (0);
}
