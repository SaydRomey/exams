
#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

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
Prints the integer value of a node.
*/
void	print_node(void *data)
{
	printf("%d -> ", *(int *)data);
}

/*
Doubles the integer value of a node.
*/
void	double_value(void *data)
{
	*(int *)data *= 2;
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

/*
Create a linked list: 1 -> 2 -> 3 -> 4 -> NULL
Use ft_list_foreach with print_node to display the list.
Use ft_list_foreach with double_value to modify the data.
Use ft_list_foreach again with print_node to display the updated list.
*/
int	main(void)
{
	t_list	*list = create_node(1);
	list->next = create_node(2);
	list->next->next = create_node(3);
	list->next->next->next = create_node(4);

	printf("Original list:\n");
	ft_list_foreach(list, print_node);
	printf("NULL\n");

	printf("\nDoubling each value in the list...\n");
	ft_list_foreach(list, double_value);

	printf("Modified list:\n");
	ft_list_foreach(list, print_node);
	printf("NULL\n");

	free_list(list);
	return (0);
}

// gcc main.c ft_list_foreach.c -o test_list_foreach
// ./test_list_foreach

/* Expected output:
Original list:
1 -> 2 -> 3 -> 4 -> NULL

Doubling each value in the list...

Modified list:
2 -> 4 -> 6 -> 8 -> NULL

*/
