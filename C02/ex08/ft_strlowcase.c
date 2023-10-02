/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/08 22:18:05 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		if ('A' <= str[len] && str[len] <= 'Z')
			str[len] += 'a' - 'A';
		len++;
	}
	return (str);
}

/*
#include <stdio.h>

int main(void)
{
    char str[] = "je teste UN TRUC@[";

    printf("str = %s\n", str);
    printf("lowstr = %s\n", ft_strlowcase(str));
}
*/
