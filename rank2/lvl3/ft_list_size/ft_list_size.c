
/*
Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

*/

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*node;
	t_list	*node1;
	t_list	*node2;

	node = NULL;
	node1 = NULL;
	node2 = NULL;
	node = (t_list *)malloc(sizeof(t_list));
	node1 = (t_list *)malloc(sizeof(t_list));
	node2 = (t_list *)malloc(sizeof(t_list));
	node->next = node1;
	node1->next = node2;
	node2->next = NULL;
	printf("%d\n", ft_list_size(node));
	free(node);
	free(node1);
	free(node2);
	return (0);
}
