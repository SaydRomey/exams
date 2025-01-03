
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linear Congruential Generator constants
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

// Returns the name of a question from the given index in lvl1
const char	*lvl1(int i)
{
	const char	*lvl1[] = {
		"first_word", "fizzbuzz", "ft_putstr", "ft_strcpy", "ft_strlen",
		"ft_swap", "repeat_alpha", "rev_print", "rot_13", "rotone",
		"search_and_replace", "ulstr"
	};
	return (lvl1[i]);
}

// Returns the name of a question from the given index in lvl2
const char	*lvl2(int i)
{
	const char	*lvl2[] = {
		"alpha_mirror", "camel_to_snake", "do_op", "ft_atoi", "ft_strcmp",
		"ft_strcspn", "ft_strdup", "ft_strpbrk", "ft_strrev", "ft_strspn",
		"inter", "is_power_of_2", "last_word", "max", "print_bits",
		"reverse_bits", "snake_to_camel", "swap_bits", "union", "wdmatch"
	};
	return (lvl2[i]);
}

// Returns the name of a question from the given index in lvl3
const char	*lvl3(int i)
{
	const char	*lvl3[] = {
		"add_prime_sum", "epur_str", "expand_str", "ft_atoi_base",
		"ft_list_size", "ft_range", "ft_rrange", "hidenp", "lcm",
		"paramsum", "pgcd", "print_hex", "rstr_capitalizer", "tab_mult"
	};
	return (lvl3[i]);
}

// Returns the name of a question from the given index in lvl4
const char	*lvl4(int i)
{
	const char	*lvl4[] = {
		"flood_fill", "fprime", "ft_itoa", "ft_list_foreach",
		"ft_list_remove_if", "ft_split", "rev_wstring", "rostring",
		"sort_int_tab", "sort_list"
	};
	return (lvl4[i]);
}


// Retrieves the name of a question based on the level and index
const char	*get_question_name(int level, int index)
{
	switch (level)
	{
		case 1:
			return (lvl1(index));
		case 2:
			return (lvl2(index));
		case 3:
			return (lvl3(index));
		case 4:
			return (lvl4(index));
		default:
			return (NULL);
	}
}

// Displays subject from subject.txt
void	display_subject(const char *folder)
{
	char	path[256];
	snprintf(path, sizeof(path), "%s/subject.txt", folder);
	
	FILE	*file = fopen(path, "r");
	if (!file)
	{
		perror("Could not open subject file");
		return ;
	}
	printf("\n--- Question Subject ---\n");
	char	buffer[512];
	while (fgets(buffer, sizeof(buffer), file))
	{
		printf("%s", buffer);
	}
	printf("-------------------------\n");
	fclose(file);
}

// Displays subject from multi-line comment at the top of .c file
// void	display_subject(const char *folder)
// {
// 	char	path[256];
// 	snprintf(path, sizeof(path), "%s/%s.c", folder, strrchr(folder, '/') + 1);

// 	FILE	*file = fopen(path, "r");
// 	if (!file)
// 	{
// 		perror("Could not open source file");
// 		return ;
// 	}
// 	printf("\n--- Question Subject ---\n");
// 	char	line[512];
// 	int		in_comment = 0;
// 	while (fgets(line, sizeof(line), file))
// 	{
// 		// Parse each line to find the comment block
// 		if (strstr(line, "/*"))
// 			in_comment = 1;

// 		if (in_comment)
// 			printf("%s", line);

// 		if (strstr(line, "*/"))
// 		{
// 			in_comment = 0;
// 			break ;
// 		}
// 	}
// 	if (!in_comment)
// 	{
// 		printf("No subject comment found in the source file.\n");
// 	}
// 	printf("-------------------------\n");
// 	fclose(file);
// }

int	main(void)
{
	int		lvl;
	char	path[256];

	printf("Enter question level (1, 2, 3, or 4): ");
	if (scanf("%d", &lvl) != 1 || lvl < 1 || lvl > 4)
	{
		printf("Invalid level\n");
		return (1);
	}

	// Define the number of questions per level
	int	max_questions[] = {12, 20, 14, 10};
	int	question_index = ft_rand(0, max_questions[lvl - 1] - 1);

	// Retrieve the question name
	const char	*question_name = get_question_name(lvl, question_index);
	if (!question_name)
	{
		printf("Failed to get question name.\n");
		return (1);
	}

	// Build the folder path
	snprintf(path, sizeof(path), "rank2/lvl%d/%s", lvl, question_name);

	// Display results
	printf("\nSelected Question: %s\n", question_name);
	printf("Path: %s\n", path);

	// Display the subject
	display_subject(path);

	return (0);
}

/* ************************************************************************** */

// char	*lvl1(int i)
// {
// 	char	*lvl1[12];

// 	lvl1[0] = "first_word";
// 	lvl1[1] = "fizzbuzz";
// 	lvl1[2] = "ft_putstr";
// 	lvl1[3] = "ft_strcpy";
// 	lvl1[4] = "ft_strlen";
// 	lvl1[5] = "ft_swap";
// 	lvl1[6] = "repeat_alpha";
// 	lvl1[7] = "rev_print";
// 	lvl1[8] = "rot_13";
// 	lvl1[9] = "rotone";
// 	lvl1[10] = "search_and_replace";
// 	lvl1[11] = "ulstr";
// 	return (lvl1[i]);
// }

// char	*lvl2(int i)
// {
// 	char	*lvl2[20];

// 	lvl2[0] = "alpha_mirror";
// 	lvl2[1] = "camel_to_snake";
// 	lvl2[2] = "do_op";
// 	lvl2[3] = "ft_atoi";
// 	lvl2[4] = "ft_strcmp";
// 	lvl2[5] = "ft_strcspn";
// 	lvl2[6] = "ft_strdup";
// 	lvl2[7] = "ft_strpbrk";
// 	lvl2[8] = "ft_strrev";
// 	lvl2[9] = "ft_strspn";
// 	lvl2[10] = "inter";
// 	lvl2[11] = "is_power_of_2";
// 	lvl2[12] = "last_word";
// 	lvl2[13] = "max";
// 	lvl2[14] = "print_bits";
// 	lvl2[15] = "reverse_bits";
// 	lvl2[16] = "snake_to_camel";
// 	lvl2[17] = "swap_bits";
// 	lvl2[18] = "union";
// 	lvl2[19] = "wdmatch";
// 	return (lvl2[i]);
// }

// char	*lvl3(int i)
// {
// 	char	*lvl3[14];

// 	lvl3[0] = "add_prime_sum";
// 	lvl3[1] = "epur_str";
// 	lvl3[2] = "expand_str";
// 	lvl3[3] = "ft_atoi_base";
// 	lvl3[4] = "ft_list_size";
// 	lvl3[5] = "ft_range";
// 	lvl3[6] = "ft_rrange";
// 	lvl3[7] = "hidenp";
// 	lvl3[8] = "lcm";
// 	lvl3[9] = "paramsum";
// 	lvl3[10] = "pgcd";
// 	lvl3[11] = "print_hex";
// 	lvl3[12] = "rstr_capitalizer";
// 	lvl3[13] = "tab_mult";
// 	return (lvl3[i]);
// }

// char	*lvl4(int i)
// {
// 	char	*lvl4[10];

// 	lvl4[0] = "flood_fill";
// 	lvl4[1] = "fprime";
// 	lvl4[2] = "ft_itoa";
// 	lvl4[3] = "ft_list_foreach";
// 	lvl4[4] = "ft_list_remove_if";
// 	lvl4[5] = "ft_split";
// 	lvl4[6] = "rev_wstring";
// 	lvl4[7] = "rostring";
// 	lvl4[8] = "sort_int_tab";
// 	lvl4[9] = "sort_list";
// 	return (lvl4[i]);
// }

/*
Only handled printing the question name
*/
// int	old_main(void)
// {
// 	int		lvl;
// 	char	*random_question;

// 	printf("Enter question level (1, 2, 3 or 4): ");
// 	scanf("%d", &lvl);
// 	if (lvl == 1)
// 		random_question = lvl1(ft_rand(0, 11));
// 	else if (lvl == 2)
// 		random_question = lvl2(ft_rand(0, 19));
// 	else if (lvl == 3)
// 		random_question = lvl3(ft_rand(0, 13));
// 	else if (lvl == 4)
// 		random_question = lvl4(ft_rand(0, 9));
// 	else
// 		return (printf("Invalid level\n"), 0);
// 	printf("%s\n", random_question);
// 	return (0);
// }
