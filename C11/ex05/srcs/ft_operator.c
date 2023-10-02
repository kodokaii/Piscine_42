/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/20 00:10:29 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_doop.h"

int	ft_add(int nb1, int nb2)
{
	ft_putnbr(nb1 + nb2);
	ft_putchar('\n');
	return (0);
}

int	ft_sub(int nb1, int nb2)
{
	ft_putnbr(nb1 - nb2);
	ft_putchar('\n');
	return (0);
}

int	ft_mul(int nb1, int nb2)
{
	ft_putnbr(nb1 * nb2);
	ft_putchar('\n');
	return (0);
}

int	ft_div(int nb1, int nb2)
{
	if (nb2)
	{
		ft_putnbr(nb1 / nb2);
		ft_putchar('\n');
		return (0);
	}
	else
	{
		write(2, "Stop : division by zero\n", 24);
		return (1);
	}
}

int	ft_mod(int nb1, int nb2)
{
	if (nb2)
	{
		ft_putnbr(nb1 % nb2);
		ft_putchar('\n');
		return (0);
	}
	else
	{
		write(2, "Stop : modulo by zero\n", 22);
		return (1);
	}
}
