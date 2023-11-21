
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

int	main(void)
{
	print_bits(2);
	return (0);
}
