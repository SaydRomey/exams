
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

/*
Comparison function for ascending order
*/
int	ascending(int a, int b)
{
	return (a <= b);
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

int	main(void)
{
	t_list	*list = create_node(3);
	list->next = create_node(1);
	list->next->next = create_node(4);
	list->next->next->next = create_node(2);

	printf("Original list:\n");
	print_list(list);

	list = sort_list(list, ascending);

	printf("Sorted list:\n");
	print_list(list);

	free_list(list);
	return (0);
}

// gcc main.c sort_list.c -o sort_list
// ./sort_list

/* Expected output:

Original list:
3 -> 1 -> 4 -> 2 -> NULL

Sorted list:
1 -> 2 -> 3 -> 4 -> NULL

*/
