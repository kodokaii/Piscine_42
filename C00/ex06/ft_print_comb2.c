/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/06 12:08:45 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	kdo_display_comb2(int nbr1, int nbr2)
{
	ft_putchar('0' + nbr1 / 10);
	ft_putchar('0' + nbr1 % 10);
	ft_putchar(' ');
	ft_putchar('0' + nbr2 / 10);
	ft_putchar('0' + nbr2 % 10);
	if (nbr1 != 98 || nbr2 != 99)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	nbr1;
	int	nbr2;

	nbr1 = 0;
	while (nbr1 <= 98)
	{
		nbr2 = nbr1 + 1;
		while (nbr2 <= 99)
		{
			kdo_display_comb2(nbr1, nbr2);
			nbr2++;
		}
		nbr1++;
	}
}

/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/
