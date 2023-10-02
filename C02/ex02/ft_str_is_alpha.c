/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/08 20:22:05 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (*str < 'A' || ('Z' < *str && *str < 'a') || 'z' < *str)
			return (0);
		str++;
	}
	return (1);
}

/*
#include <stdio.h>

int		main()
{
	char	*str;

	str = "abcdefghijklmnopqrstuvwxyz";
	printf("str = %s, isalpha = %d\n", str, ft_str_is_alpha(str));
	str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	printf("str = %s, isalpha = %d\n", str, ft_str_is_alpha(str));
	str = "@";
	printf("str = %s, isalpha = %d\n", str, ft_str_is_alpha(str));
	str = "[";
	printf("str = %s, isalpha = %d\n", str, ft_str_is_alpha(str));
	str = "{";
	printf("str = %s, isalpha = %d\n", str, ft_str_is_alpha(str));
}
*/
