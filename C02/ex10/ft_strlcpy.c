/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 22:56:14 by event             #+#    #+#             */
/*   Updated: 2023/07/10 12:02:29 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;

	len = 0;
	if (size)
	{
		while (len < size - 1 && src[len])
		{
			dest[len] = src[len];
			len++;
		}
		dest[len] = 0;
	}
	while (src[len])
		len++;
	return (len);
}

/*
#include <stdio.h>

int main(void)
{
	char dest[] = "Failed";
	char src[] = "Gooded";

	printf("return = %d\n", ft_strlcpy(dest, src, 5));
	printf("src = %s, dest = %s\n", src, dest);
}
*/
