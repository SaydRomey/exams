
#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

/*
Sample comparison function
Compares two integers.
Returns 0 if they are equal.
*/
int	cmp(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}

/*
Allocates memory for a node and assigns an integer value.
*/
t_list	*create_node(int value)
{
	t_list	*node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);

	node->data = malloc(sizeof(int));
	if (!node->data)
	{
		free(node);
		return (NULL);
	}
	*(int *)node->data = value;
	node->next = NULL;
	return (node);
}

/*
Prints the list in a readable format.
*/
void	print_list(T_list *list)
{
	while (list)
	{
		printf("%d -> ", *(int *)list->data);
		list = list->next;
	}
	printf("NULL\n");
}

/*
Frees all nodes and their data to prevent memory leaks.
*/
void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->data);
		free(tmp);
	}
}

/* Test case
A linked list is created with the values: 1 -> 2 -> 3 -> 2 -> 4 -> NULL
ft_list_remove_if is called with ref = 2 to remove all nodes containing 2.
*/
int	main(void)
{
	t_list	*list = create_node(1);
	list->next = create_node(2);
	list->next->next = create_node(3);
	list->next->next->next = create_node(2);
	list->next->next->next->next = create_node(4);

	printf("Original list:\n");
	print_list(list);

	int	ref = 2;
	ft_list_remove_if(&list, &ref, cmp);

	printf("List after removing %d:\n", ref);
	print_list(list);

	free_list(list);
	return (0);
}

// gcc main.c ft_list_remove_if.c -o test_list
// ./test_list

/* Expected output:

Original list:
1 -> 2 -> 3 -> 2 -> 4 -> NULL
List after removing 2:
1 -> 3 -> 4 -> NULL

*/
