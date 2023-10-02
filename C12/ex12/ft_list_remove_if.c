/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/26 17:55:31 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_remove_if_rec(t_list *current, void *data_ref, \
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*next;

	if (current->next)
		next = ft_list_remove_if_rec(current->next, data_ref, \
				cmp, free_fct);
	else
		next = NULL;
	if (!(*cmp)(current->data, data_ref))
	{
		(*free_fct)(current->data);
		free(current);
		return (next);
	}
	current->next = next;
	return (current);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, \
			int (*cmp)(), void (*free_fct)(void *))
{
	*begin_list = ft_list_remove_if_rec(*begin_list, data_ref, cmp, free_fct);
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

void	putvoid(void *str)
{
	printf("free '%s'\n", (char *)str);
}

#include <string.h>

int	main(int argc, char *argv[])
{
	t_list	*root;
	int		i;

	if (2 < argc)
	{
		i = 2;
		root = NULL;
		while (i < argc)
			ft_list_push_front(&root, argv[i++]);
		ft_list_remove_if(&root, argv[1], &strcmp, &putvoid);
		while (root)
		{
			printf("%s -> ", (char *)root->data);
			root = root->next;
		}
	}
	else
		printf("required 'find' 's1' ...\n");
}
*/
