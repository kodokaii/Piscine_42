/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/12 17:26:05 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{	
	while (*str)
		write(1, str++, 1);
}

void	ft_swap_params(char **a, char **b)
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

void	ft_sort_params(char *tab[], int size)
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
			ft_swap_params(&tab[before + 1], &tab[size - after - 1]);
			after++;
		}
	}
	ft_swap_params(&tab[0], &tab[before]);
	if (1 < before)
		ft_sort_params(tab, before);
	if (1 < after)
		ft_sort_params(tab + size - after, after);
}

int	main(int argc, char *argv[])
{
	int	i;

	ft_sort_params(argv + 1, argc - 1);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}
