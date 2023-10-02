/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/12 12:28:08 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	len;

	len = 0;
	while (len < n && src[len])
	{
		dest[len] = src[len];
		len++;
	}
	while (len < n)
		dest[len++] = 0;
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char    dest1[100];
    char    dest2[100];
	int		n;

    if (2 < argc)
    {
		n = atoi(argv[2]);
        memcpy(dest1, dest2, 100);
        printf("ft_strncpy = %s\n", argv[1], ft_strncpy(dest1, argv[1], n));
        printf("strncpy = %s\n", argv[1], strncpy(dest2, argv[1], n));
    }
    else
        printf("required 's1' 'n'\n");
}
*/
