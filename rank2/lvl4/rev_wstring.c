
/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
 int i = 0;

 while (str[i])
 {
  ft_putchar(str[i]);
  i++;
 }
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	rev_wstr(char *str)
{
	int	i = ft_strlen(str) - 1; //find the last character
	int	j;
	int	word_end;

	while (i >= 0)
	{
  while (i >= 0 && ft_isspace(str[i])) //skip any trailing spaces
   {
    i--;
   }
   word_end = i; //find the end of the current word
   while (i >= 0 && !ft_isspace(str[i]))
   {
    i--;
   }
   j = i + 1;
   if (j <= word_end)
   {
    str[word_end + 1] = '\0'; //temporarily terminate the string
    ft_putstr(&str[j]);
    if (i >= 0)
     ft_putchar(' '); //print a space if not at the start
  }
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	ft_putchar('\n');
	return (0);
}
