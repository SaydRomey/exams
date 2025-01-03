
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_putnbr(int nbr)
{
	char	*digits = "0123456789";

	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(digits[nbr % 10]);
}

void	ft_fizzbuzz(int nbr)
{
	int	i;

	i = 1;
	while (i <= nbr)
	{
		if (i % 15 == 0)
			ft_putstr("fizzbuzz");
		else if (i % 3 == 0)
			ft_putstr("fizz");
		else if (i % 5 == 0)
			ft_putstr("buzz");
		else
			ft_putnbr(i);
		ft_putchar('\n');
		i++;
	}
}

int	main(void)
{
	ft_fizzbuzz(100);
	return (0);
}
