
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_islower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_isupper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

/* ************************************************************************** */

/* simple array solution

static char	find_mirror(char c)
{
	char	lower_alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	char	upper_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char	lower_mirror[] = "zyxwvutsrqponmlkjihgfedcba";
	char	upper_mirror[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
	int		i;

	i = 0;
	while (i < 26)
	{
		if (c == lower_alphabet[i])
			return (lower_mirror[i]);
		if (c == upper_alphabet[i])
			return (upper_mirror[i]);
		i++;
	}
	return (c);
}
*/

/* ************************************************************************** */

/* also works with ('m' - (str[i] - 'n')

static char	find_mirror(char c)
{
	if (ft_islower(c))
		return ('z' - (c - 'a'));
	if (ft_isupper(c))
		return ('Z' - (c - 'A'));
	return (c);
}
*/

static char	find_mirror(char c)
{
	char	a;
	char	z;
	int		distance_from_a;
	char	mirrored_char;

	if (ft_islower(c))
	{
		a = 'a';
		z = 'z';
	}
	else if (ft_isupper(c))
	{
		a = 'A';
		z = 'Z';
	}
	else
		return (c);
	distance_from_a = c - a;
	mirrored_char = z - distance_from_a;
	return (mirrored_char);
}

static void	alpha_mirror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(find_mirror(str[i]));
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		alpha_mirror(argv[1]);
	ft_putchar('\n');
	return (0);
}
