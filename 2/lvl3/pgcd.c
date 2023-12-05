
/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$
*/

#include <stdio.h>
#include <stdlib.h>

void	pgcd(char *s1, char *s2)
{
	int	a;
	int	b;
	int	denominator;
	int	greatest_common;

	a = atoi(s1);
	b = atoi(s2);
	if (a <= 0 || b <= 0)
		return ;
	denominator = 1;
	while (denominator <= a || denominator <= b)
	{
		if ((a % denominator) == 0 && (b % denominator) == 0)
			greatest_common = denominator;
		denominator++;
	}
	printf("%d", greatest_common);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		pgcd(argv[1], argv[2]);
	printf("\n");
}
