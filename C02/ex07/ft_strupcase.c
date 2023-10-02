/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/08 22:16:19 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		if ('a' <= str[len] && str[len] <= 'z')
			str[len] -= 'a' - 'A';
		len++;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char str[] = "je teste UN TRUC`{";

	printf("str = %s\n", str);
	printf("upstr = %s\n", ft_strupcase(str));
}
*/
