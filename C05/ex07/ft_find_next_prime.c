/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/12 23:21:43 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 5;
	if (nb == 2 || nb == 3)
		return (1);
	if (nb <= 1 || nb % 2 == 0 || nb % 3 == 0)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (nb == 3)
		return (3);
	if (nb % 6 == 0)
		nb++;
	if ((nb - 1) % 6 == 0 && ft_is_prime(nb))
		return (nb);
	while ((nb + 1) % 6 != 0)
		nb++;
	while (0 < nb)
	{
		if (ft_is_prime(nb))
			return (nb);
		if (ft_is_prime(nb + 2))
			return (nb + 2);
		nb += 6;
	}
	return (2);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	nb;

	if (1 < argc)
	{
		nb = atoi(argv[1]);
		printf("ft_find_next_prime(%d) = %d\n", nb, ft_find_next_prime(nb));
	}
	else
		printf("required 'nb'\n");
}
*/
