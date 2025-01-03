
static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* **************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;
	int	digit;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (ft_isdigit(str[i]))
	{
		digit = str[i] - '0';
		result = result * 10;
		result = result + digit;
		i++;
	}
	return (result * sign);
}

/* **************************************************************** */

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	int atoied = ft_atoi(argv[1]);
	printf("string input : %s\n", argv[1]);
	printf("atoi'd output: %d\n", atoied);
	return (0);
}
