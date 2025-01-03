
/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/

#include <stdlib.h>

int	ft_isdelim(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	ft_word_count(char *str)
{
	int	i = 0;
	int	word_count = 0;

	while (str[i])
	{
		if (!ft_isdelim(str[i]) && (ft_isdelim(str[i + 1]) || str[i + 1] == '\0'))
			word_count++;
		i++;
	}
	return (word_count);
}

char	*get_word(char *str)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	while (str[i] && ft_isdelim(str[i]) == 0)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < i)
	{
		word[j] = str[j];
		j++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	int		word_count;
	int		i; // str index
	char	**split;
	int		j; // split index

	word_count = ft_word_count(str);
	split = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!ft_isdelim(str[i]))
		{
			split[j] = get_word(str + i);
   if (!split[j])
   {
    while (j >= 0)
    {
     free(split[j]);
     j--;
    }
    free(split);
    return (NULL);
   }
			j++;
			while (str[i] && !ft_isdelim(str[i]))
				i++;
		}
		else
			i++;
	}
	split[j] = NULL;
	return (split);
}

/* ************************************************************************** */

#include <stdio.h>

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	main(void)
{
	char	*tosplit = "this has a few words to split";
	char	**split = ft_split(tosplit);
	int		i = 0;

 if (!split)
  return (0);
	while (split[i])
	{
		printf("string %d -> %s\n", i, split[i]);
		i++;
	}
	free_split(split);
	return (0);
}
