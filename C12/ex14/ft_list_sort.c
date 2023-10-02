/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/26 20:33:07 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	len;

	len = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		len++;
	}
	return (len);
}

void	ft_list_move(t_list **dest, t_list **src)
{
	t_list	*current;

	current = *src;
	*src = (*src)->next;
	current->next = *dest;
	*dest = current;
}

void	ft_list_sort_rec(t_list	**begin, int (*cmp)(), int size)
{
	t_list	*pivot;
	t_list	*current;
	int		after;
	int		before;

	after = 0;
	before = 0;
	pivot = *begin;
	current = pivot;
	while (after + 1 + before < size)
	{
		if (0 <= (*cmp)(current->next->data, pivot->data))
		{
			current = current->next;
			after++;
		}
		else if (++before)
			ft_list_move(begin, &current->next);
	}
	if (1 < after)
		ft_list_sort_rec(&(pivot->next), cmp, after);
	if (1 < before)
		ft_list_sort_rec(begin, cmp, before);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int	size;

	size = ft_list_size(*begin_list);
	if (1 < size)
		ft_list_sort_rec(begin_list, cmp, size);
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

#include <string.h>

int	main(int argc, char *argv[])
{
	t_list	*root;
	int		i;

	if (1 < argc)
	{
		i = 1;
		root = NULL;
		while (i < argc)
			ft_list_push_front(&root, argv[i++]);
		ft_list_sort(&root, &strcmp);
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
