
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_bits(unsigned char octet)
{
	int	bit;

	bit = 128;
	while (bit > 0)
	{
		if (octet >= bit)
		{
			ft_putchar('1');
			octet -= bit; //or %=
		}
		else
			ft_putchar('0');
		bit /= 2;
	}
}

/* ************************************************************************** */

/* using ft_putnbr() logic

void	ft_putbit(int nbr)
{
	char	*digits = "01";

	if (nbr > 1)
		ft_putbit(nbr / 2);
	ft_putchar(digits[nbr % 2]);
}

void	print_bits(unsigned char octet)
{
	ft_putbit((int)octet);
}
*/


/* ************************************************************************** */

int	main(void)
{
	print_bits((unsigned char)'A');
	return (0);
}
