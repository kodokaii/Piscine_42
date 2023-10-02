/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/24 00:42:43 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	sort;
	int	current_sort;

	i = 0;
	sort = 0;
	while (i + 1 < length)
	{
		current_sort = (*f)(tab[i], tab[i + 1]);
		if (!sort && current_sort)
			sort = current_sort;
		if (current_sort && (sort < 0) != (current_sort < 0))
			return (0);
		i++;
	}
	return (1);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	ft_comp(int nb1, int nb2)
{
	return (nb1 - nb2);
}

int	main(int argc, char *argv[])
{
	int	*tab;
	int	i;

	if (1 < argc)
	{
		argv++;
		argc--;
		tab = malloc(argc * sizeof(int));
		i = -1;
		while (++i < argc)
			tab[i] = atoi(argv[i]);
		printf("ft_is_sort = %d\n", ft_is_sort(tab, argc, &ft_comp));
	}
	else
		printf("required 'nb1' ...\n");
}
*/
