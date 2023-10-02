/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/11 14:48:05 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	base_ok(char *base)
{
	unsigned int	i;

	if (!base[0] || !base[1])
		return (0);
	while (*base)
	{
		i = 1;
		while (base[i])
		{
			if (*base == base[i])
				return (0);
			i++;
		}
		if (*base == '+' || *base == '-')
			return (0);
		base++;
	}
	return (1);
}

void	ft_putnbr_base_rec(unsigned int nbr, char *base, unsigned int base_sz)
{
	if (nbr / base_sz)
		ft_putnbr_base_rec(nbr / base_sz, base, base_sz);
	write(1, base + nbr % base_sz, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	nb;

	if (base_ok(base))
	{
		nb = 1;
		if (nbr < 0)
		{
			write(1, "-", 1);
			nb = -1;
		}
		nb *= nbr;
		ft_putnbr_base_rec(nb, base, ft_strlen(base));
	}
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (2 < argc)
	{
		ft_putnbr_base(atoi(argv[1]), argv[2]);
		printf("\n");
	}
	else
		printf("required 'nb' 'base'\n");
}
*/
