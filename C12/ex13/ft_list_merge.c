/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/26 18:05:18 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	if (*begin_list1)
		ft_list_last(*begin_list1)->next = begin_list2;
	else
		*begin_list1 = begin_list2;
}

/*
t_list	*ft_create_elem(void *data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new;

	new = ft_create_elem(data);
	new->next = *begin_list;
	*begin_list = new;
}

int	main(int argc, char *argv[])
{
	t_list	*root1;
	t_list	*root2;
	int		i;

	if (1 < argc)
	{
		i = 1;
		root1 = NULL;
		root2 = NULL;
		while (i < argc)
		{
			ft_list_push_front(&root1, argv[i]);
			ft_list_push_front(&root2, argv[i]);
			i++;
		}
		ft_list_merge(&root1, root2);
		while (root1)
		{
			printf("%s -> ", (char *)root1->data);
			root1 = root1->next;
		}
	}
	else
		printf("required 's1' ...\n");
}
*/
