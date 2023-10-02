/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/09 18:39:52 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
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
	char		*dest1;
	char		*dest2;
	unsigned int size;

	if (2 < argc)
	{
		size = strlen(argv[1]) + strlen(argv[2]) + 1;
		dest1 = malloc(size * sizeof(char));
		dest2 = malloc(size * sizeof(char));
		strcpy(dest1, argv[1]);
		strcpy(dest2, argv[1]);
		printf("src = '%s', dest = '%s'\n\\/\n", argv[2], argv[1]);
		printf("strcat = '%s'\n", strcat(dest1, argv[2]));
		printf("ft_strcat = '%s'\n", ft_strcat(dest2, argv[2]));
	}
	else
		printf("required 's1' 's2'\n");
}
*/
