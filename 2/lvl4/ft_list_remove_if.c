
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;
	t_list	*temp;

	current = *begin_list;
	while (current != NULL && cmp(current->data, data_ref) == 0)
	{
		temp = current;
		*begin_list = current->next;
		free(temp);
		current = *begin_list;
	}
	while (current != NULL && current->next != NULL)
	{
		if (cmp(current->next->data, data_ref) == 0)
		{
			temp = current->next;
			current->next = temp->next;
			free(temp);
		}
		else
		{
			current = current->next;
		}
	}
}
