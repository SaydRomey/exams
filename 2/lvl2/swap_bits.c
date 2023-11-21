
unsigned char swap_bits(unsigned char octet)
{
	unsigned char	high;
	unsigned char	low;

	high = octet / 16; //or >> 4 (shift right by 4 bits)
	low = octet % 16; //get the low 4 bits
	return ((low * 16) + high); //or << 4 (shift left by 4 bits) then add high 4 bits
}

/* ************************************************************************** */

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
			octet -= bit;
		}
		else
			ft_putchar('0');
		bit /= 2;
	}
}

int	main(void)
{
	print_bits(2);
	ft_putchar('\n');
	print_bits(swap_bits(2));
	return (0);
}
