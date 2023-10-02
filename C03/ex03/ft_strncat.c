/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/09 18:35:12 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (j < nb && src[j])
		dest[i++] = src[j++];
	dest[i] = 0;
	return (dest);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		printf("strncat = '%s'\n", strncat(dest1, argv[2], n));
		printf("ft_strncat = '%s'\n", ft_strncat(dest2, argv[2], n));
	}
	else
		printf("required 's1' 's2' 'n'\n");
}
*/
