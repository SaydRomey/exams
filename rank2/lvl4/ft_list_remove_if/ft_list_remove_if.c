
/*
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>
*/

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;
	t_list	*tmp;

	if (begin_list == NULL || *begin_list == NULL)
		return ;

	// Handle the case where the first nodes match
	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}

	// Start traversing from the first valid node
	current = *begin_list;
	while (current && current->next)
	{
		if (cmp(current->next->data, data_ref) == 0)
		{
			tmp = current->next;
			current->next = tmp->next;
			free(tmp);
		}
		else
		{
			current = current->next;
		}
	}
}
