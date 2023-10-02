/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/01 14:03:35 by kodokai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
		(*f)(tab[i++]);
}

/*
#include <stdio.h>
#include <stdlib.h>

void	ft_putnbr(int nb)
{
	printf("%d\n", nb);
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
		ft_foreach(tab, argc, &ft_putnbr);
	}
	else
		printf("required 'nb1' ...\n");
}
*/
