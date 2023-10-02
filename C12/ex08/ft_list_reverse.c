/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/26 18:47:34 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_reverse_rec(t_list *current, t_list *after)
{
	t_list	*next;

	next = current->next;
	current->next = after;
	if (next)
		return (ft_list_reverse_rec(next, current));
	return (current);
}

void	ft_list_reverse(t_list **begin_list)
{
	*begin_list = ft_list_reverse_rec(*begin_list, NULL);
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
		ft_list_reverse(&root);
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
