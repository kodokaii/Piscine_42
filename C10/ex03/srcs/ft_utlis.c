/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utlis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/08/28 21:28:51 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

t_putoc_buf	*get_putoc_buf(void)
{
	static t_putoc_buf	ocbuf;

	return (&ocbuf);
}

void	ft_putoc(t_oc c)
{
	t_putoc_buf	*ocbuf;

	ocbuf = get_putoc_buf();
	ocbuf->buf[ocbuf->size++] = c;
	if (BUF_SIZE <= ocbuf->size)
	{
		write(1, ocbuf->buf, ocbuf->size);
		ocbuf->size = 0;
	}
}

void	ft_cleanup(void)
{
	t_putoc_buf	*ocbuf;

	ocbuf = get_putoc_buf();
	write(1, ocbuf->buf, ocbuf->size);
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
