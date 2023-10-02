/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/26 11:19:22 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new;

	new = ft_create_elem(data);
	new->next = *begin_list;
	*begin_list = new;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*root;
	int		i;

	i = 0;
	root = NULL;
	while (i < size)
		ft_list_push_front(&root, strs[i++]);
	return (root);
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

int	main(int argc, char *argv[])
{
	t_list	*root;
	int		i;

	if (1 < argc)
	{
		i = 1;
		root = ft_list_push_strs(--argc, ++argv);
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
