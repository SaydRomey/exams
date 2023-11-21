
#include <stdio.h>

#define LCG_MULT	1103515245
#define LCG_INCR	12345
#define LCG_DIV		65536

int	ft_rand(int min, int max)
{
	static unsigned long	seed;
	int						var;
	int						range;
	int						random_int;

	if (seed == 0)
		seed = (unsigned long)&var;
	seed = seed * LCG_MULT + LCG_INCR;
	range = max - min + 1;
	random_int = ((seed / LCG_DIV) % range) + min;
	return (random_int);
}

char	*lvl1(int i)
{
	char	*lvl1[12];

	lvl1[0] = "first_word";
	lvl1[1] = "fizzbuzz";
	lvl1[2] = "ft_putstr";
	lvl1[3] = "ft_strcpy";
	lvl1[4] = "ft_strlen";
	lvl1[5] = "ft_swap";
	lvl1[6] = "repeat_alpha";
	lvl1[7] = "rev_print";
	lvl1[8] = "rot_13";
	lvl1[9] = "rotone";
	lvl1[10] = "search_and_replace";
	lvl1[11] = "ulstr";
	return (lvl1[i]);
}

char	*lvl2(int i)
{
	char	*lvl2[20];

	lvl2[0] = "alpha_mirror";
	lvl2[1] = "camel_to_snake";
	lvl2[2] = "do_op";
	lvl2[3] = "ft_atoi";
	lvl2[4] = "ft_strcmp";
	lvl2[5] = "ft_strcspn";
	lvl2[6] = "ft_strdup";
	lvl2[7] = "ft_strpbrk";
	lvl2[8] = "ft_strrev";
	lvl2[9] = "ft_strspn";
	lvl2[10] = "inter";
	lvl2[11] = "is_power_of_2";
	lvl2[12] = "last_word";
	lvl2[13] = "max";
	lvl2[14] = "print_bits";
	lvl2[15] = "reverse_bits";
	lvl2[16] = "snake_to_camel";
	lvl2[17] = "swap_bits";
	lvl2[18] = "union";
	lvl2[19] = "wdmatch";
	return (lvl2[i]);
}

int	main(void)
{
	int		lvl;
	char	*random_question;

	printf("Enter question level (1 or 2): ");
	scanf("%d", &lvl);
	if (lvl == 1)
	{
		random_question = lvl1(ft_rand(0, 11));
		printf("%s\n", random_question);
	}
	else if (lvl == 2)
	{
		random_question = lvl2(ft_rand(0, 19));
		printf("%s\n", random_question);
	}
	else
		printf("Invalid level\n");
	return (0);
}
