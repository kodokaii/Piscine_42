/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/19 01:40:17 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*new_tab;
	int	i;

	new_tab = malloc(length * sizeof(int));
	if (!new_tab)
		return (NULL);
	i = 0;
	while (i < length)
	{
		new_tab[i] = (*f)(tab[i]);
		i++;
	}
	return (new_tab);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	ft_double(int nb)
{
	return (nb * 2);
}

int	main(int argc, char *argv[])
{
	int	*tab;
	int	*new_tab;
	int	i;

	if (1 < argc)
	{
		argv++;
		argc--;
		tab = malloc(argc * sizeof(int));
		i = -1;
		while (++i < argc)
			tab[i] = atoi(argv[i]);
		new_tab = ft_map(tab, argc, &ft_double);
		i = -1;
		while (++i < argc)
			printf("%d\n", new_tab[i]);
	}
	else
		printf("required 'nb1' ...\n");
}
*/
