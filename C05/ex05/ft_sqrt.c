/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/13 13:02:44 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	res;

	res = 1;
	if (2147395600 < nb)
		return (0);
	while (res * res < nb)
		res++;
	if (res * res == nb)
		return (res);
	return (0);
}

/*
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	nb;

	if (1 < argc)
	{
		nb = atoi(argv[1]);
		printf("√%d = %d\n", nb, ft_sqrt(nb));
	}
	else
		printf("required 'nb'\n");

	return (0);
}
*/
