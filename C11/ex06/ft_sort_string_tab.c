/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/20 00:55:09 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_str(char **a, char **b)
{
	char	*buf;

	buf = *a;
	*a = *b;
	*b = buf;
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_strs(char **tab, int size)
{
	int	before;
	int	after;

	before = 0;
	after = 0;
	while (before + 1 + after < size)
	{
		if (ft_strcmp(tab[before + 1], tab[0]) <= 0)
			before++;
		else
		{
			ft_swap_str(&tab[before + 1], &tab[size - after - 1]);
			after++;
		}
	}
	ft_swap_str(&tab[0], &tab[before]);
	if (1 < before)
		ft_sort_strs(tab, before);
	if (1 < after)
		ft_sort_strs(tab + size - after, after);
}

void	ft_sort_string_tab(char **tab)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	ft_sort_strs(tab, size);
}

/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	i;

	ft_sort_string_tab(argv + 1);
	i = 1;
	while (i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}
}
*/
