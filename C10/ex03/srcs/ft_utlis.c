/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utlis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/26 12:59:59 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_putoc(t_oc c)
{
	write(1, &c, 1);
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	if (!src)
		return (NULL);
	while (n--)
		((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}

int	ft_memcmp(void *s1, void *s2, int n)
{
	int	i;

	if (!n)
		return (0);
	i = 0;
	while (i + 1 < n && ((char *) s1)[i] == ((char *) s2)[i])
		i++;
	return (((char *) s1)[i] - ((char *) s2)[i]);
}
