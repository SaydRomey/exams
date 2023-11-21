
unsigned char reverse_bits(unsigned char octet)
{
	unsigned char	reversed;
	int				bit_count;

	reversed = 0;
	bit_count = 8;
	while (bit_count > 0)
	{
		reversed *= 2; //or <<= 1 (shift left by 1 bit)
		reversed += octet % 2; //add the last bit of 'octet' to 'reversed'
		octet /= 2; //or >>= 1 (shift right by 1 bit)
		bit_count--;
	}
	return (reversed);
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
			octet -= bit; //or %=
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
	print_bits(reverse_bits(2));
	return (0);
}
