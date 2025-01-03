
#include <stdio.h>
#include <stdlib.h>

int	do_op(char *n1, char op, char *n2)
{
	int	a;
	int	b;
	int	r;

	a = atoi(n1);
	b = atoi(n2);
	r = 0;
	if (op == '+')
		r = a + b;
	else if (op == '-')
		r = a - b;
	else if (op == '*')
		r = a * b;
	else if (op == '/')
		r = a / b;
	else if (op == '%')
		r = a % b;
	return (r);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		printf("%d", do_op(argv[1], argv[2][0], argv[3]));
	printf("\n");
	return (0);
}
