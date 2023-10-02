/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/08 20:32:59 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if (*str < 'a' || 'z' < *str)
			return (0);
		str++;
	}
	return (1);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str;

	str = "abcdefghijklmnopqrstuvwxyz";
	printf("str = \"%s\", islowercase = %d\n", str, ft_str_is_lowercase(str));
	str = "`";
	printf("str = \"%s\", islowercase = %d\n", str, ft_str_is_lowercase(str));
	str = "{";
	printf("str = \"%s\", islowercase = %d\n", str, ft_str_is_lowercase(str));
	str = "";
	printf("str = \"%s\", islowercase = %d\n", str, ft_str_is_lowercase(str));
}
*/
