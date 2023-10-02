/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/16 17:36:14 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	nbr;

	nbr = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nbr = -1;
	}
	nbr *= nb;
	if (nbr / 10)
		ft_putnbr(nbr / 10);
	ft_putchar('0' + nbr % 10);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		ft_putstr(par->str);
		ft_putchar('\n');
		ft_putnbr(par->size);
		ft_putchar('\n');
		ft_putstr(par->copy);
		ft_putchar('\n');
		par++;
	}
}

/*
struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

int	main(int argc, char *argv[])
{
	struct s_stock_str	*tab;

	tab = ft_strs_to_tab(argc--, argv++);
	ft_show_tab(tab);
	return (0);
}
*/
