
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	last_word(char *str)
{
	int	len;
	int	start;
	int	end;
	int	i;

	len = ft_strlen(str);
	end = len - 1;
	while (end >= 0 && is_space(str[end]))
		end--;
	if (end < 0)
		return ;
	start = end;
	while (start >= 0 && !is_space(str[start]))
		start--;
	i = start + 1;
	while (i <= end)
	{
		ft_putchar(str[i]);
		i++;
	}	
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	ft_putchar('\n');
	return (0);
}
