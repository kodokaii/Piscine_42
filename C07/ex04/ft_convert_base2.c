/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:55:31 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/18 13:11:18 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

int	ft_strlen(char *str);
int	base_ok(char *base);
int	ft_atoi_base(char *str, char *base);

int	kdo_nblen_base(int nb, int base_sz)
{
	int	len;

	len = 1;
	while (nb / base_sz)
	{
		nb /= base_sz;
		len++;
	}
	return (len);
}

char	*kdo_fill_nb(unsigned int nbr, char *base, int base_sz, int dest_sz)
{
	char	*dest;

	dest = malloc((dest_sz + (INT_MAX < nbr) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	if (INT_MAX < nbr)
	{
		nbr *= -1;
		dest[0] = '-';
		dest_sz++;
	}
	dest[dest_sz] = 0;
	dest[--dest_sz] = base[nbr % base_sz];
	while (nbr / base_sz)
	{
		nbr /= base_sz;
		dest[--dest_sz] = base[nbr % base_sz];
	}
	return (dest);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				base_to_sz;
	int				dest_sz;
	int				nb;
	char			*dest;

	if (base_ok(base_from) && base_ok(base_to))
	{
		nb = ft_atoi_base(nbr, base_from);
		base_to_sz = ft_strlen(base_to);
		dest_sz = kdo_nblen_base(nb, base_to_sz);
		dest = kdo_fill_nb(nb, base_to, base_to_sz, dest_sz);
		return (dest);
	}
	else
		return (NULL);
}

/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*dest;

	if (3 < argc)
	{
		dest = ft_convert_base(argv[1], argv[2], argv[3]);
		printf("%s\n", dest);
	}
	else
		printf("required 'nb' 'base_from' 'base_to'\n");
}
*/
