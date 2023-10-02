/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/24 15:49:03 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_to_begin(char **tab, int begin, int index)
{
	char	*buf;

	while (begin < index)
	{
		buf = tab[index];
		tab[index] = tab[index - 1];
		tab[index - 1] = buf;
		index--;
	}
}

void	ft_swap_to_end(char **tab, int end, int index)
{
	char	*buf;

	while (index + 1 < end)
	{
		buf = tab[index];
		tab[index] = tab[index + 1];
		tab[index + 1] = buf;
		index++;
	}
}

void	ft_int_var(int *before, int *after, int *same)
{
	*before = 0;
	*after = 0;
	*same = 1;
}

void	ft_advanced_sort_strs(char **tab, int size, \
							int (*cmp)(char *, char *), int comp)
{
	int	before;
	int	after;
	int	same;

	ft_int_var(&before, &after, &same);
	while (before + same + after < size)
	{
		comp = (*cmp)(tab[before + same], tab[before + same - 1]);
		if (comp < 0)
		{
			ft_swap_to_begin(tab, before, before + same);
			before++;
		}
		else if (0 < comp)
		{
			ft_swap_to_end(tab, size, before + same);
			after++;
		}
		else
			same++;
	}
	if (1 < before)
		ft_advanced_sort_strs(tab, before, cmp, 0);
	if (1 < after)
		ft_advanced_sort_strs(tab + size - after, after, cmp, 0);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	ft_advanced_sort_strs(tab, size, cmp, 0);
}

/*
#include <stdio.h>

int	ft_strcmplen(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	return (i - j);
}

int	main(int argc, char *argv[])
{
	int	i;

	ft_advanced_sort_string_tab(argv + 1, &ft_strcmplen);
	i = 1;
	while (i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}
}
*/
