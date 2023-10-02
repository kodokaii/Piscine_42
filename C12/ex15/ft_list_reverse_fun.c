/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/27 20:06:57 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_reverse_fun_rec(t_list *begin, t_list *current)
{
	void	*buf;

	if (current->next)
		begin = ft_list_reverse_fun_rec(begin, current->next);
	if (begin)
	{
		buf = current->data;
		current->data = begin->data;
		begin->data = buf;
		if (begin != current && begin->next != current)
			return (begin->next);
	}
	return (NULL);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	ft_list_reverse_fun_rec(begin_list, begin_list);
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
	t_list	*root;
	t_list	*current;
	int		i;

	if (1 < argc)
	{
		i = 1;
		root = NULL;
		while (i < argc)
			ft_list_push_front(&root, argv[i++]);
		printf("verse\n");
		current = root;
		while (current)
		{
			printf("%s -> ", (char *)current->data);
			current = current->next;
		}
		ft_list_reverse_fun(root);
		printf("\nreverse\n");
		while (root)
		{
			printf("%s -> ", (char *)root->data);
			root = root->next;
		}
	}
	else
		printf("required 's1' ...\n");
}
*/
