/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/22 23:57:04 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strndup(char *src, int n)
{
	char	*dest;
	int		src_sz;

	src_sz = ft_strlen(src);
	if (n < src_sz)
		src_sz = n;
	dest = malloc((src_sz + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[src_sz] = 0;
	while (src_sz--)
		dest[src_sz] = src[src_sz];
	return (dest);
}
