/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/09 20:19:35 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dst_sz;
	unsigned int	src_sz;

	dst_sz = 0;
	src_sz = 0;
	while (dst_sz < size && dest[dst_sz])
		dst_sz++;
	size -= dst_sz;
	while (src_sz + 1 < size && src[src_sz])
	{
		dest[dst_sz + src_sz] = src[src_sz];
		src_sz++;
	}
	if (size)
		dest[dst_sz + src_sz] = 0;
	while (src[src_sz])
		src_sz++;
	return (dst_sz + src_sz);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>

int	main(int argc, char *argv[])
{
	char			*dest1;
	char			*dest2;
	unsigned int	size;
	unsigned int	n;

	if (3 < argc)
	{
		n = atoi(argv[3]);
		size = strlen(argv[1]) + strlen(argv[2]) + 1;
		dest1 = malloc(size * sizeof(char));
		dest2 = malloc(size * sizeof(char));
		strcpy(dest1, argv[1]);
		strcpy(dest2, argv[1]);
		printf("src = '%s', dest = '%s', n = %d\n\\/\n", argv[2], argv[1], n);
		printf("strlcat = '%zu', dest = '%s'\n",strlcat(dest1, argv[2], n),dest1);
		printf("ft_strlcat = '%u', dest = '%s'\n",ft_strlcat(dest2, argv[2], n),dest2);
	}
	else
		printf("required 's1' 's2' 'n'\n");
}
*/
