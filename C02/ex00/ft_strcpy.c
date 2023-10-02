/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/12 12:25:43 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	len;

	len = -1;
	while (src[++len])
		dest[len] = src[len];
	dest[len] = 0;
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	char	dest1[100];
	char	dest2[100];

	if (1 < argc)
	{
		memcpy(dest1, dest2, 100);
		printf("ft_strcpy = %s\n", argv[1], ft_strcpy(dest1, argv[1]));
		printf("strcpy = %s\n", argv[1], strcpy(dest2, argv[1]));
	}
	else
		printf("required 's1'\n");
}
*/
