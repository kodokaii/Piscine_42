/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/08 20:44:13 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	while (*str)
	{
		if (*str < 'A' || 'Z' < *str)
			return (0);
		str++;
	}
	return (1);
}

/*
#include <stdio.h>

int main(void)
{
    char    *str;

    str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("str = \"%s\", isuppercase = %d\n", str, ft_str_is_uppercase(str));
    str = "@";
    printf("str = \"%s\", isuppercase = %d\n", str, ft_str_is_uppercase(str));
    str = "[";
    printf("str = \"%s\", isuppercase = %d\n", str, ft_str_is_uppercase(str));
    str = "";
    printf("str = \"%s\", isuppercase = %d\n", str, ft_str_is_uppercase(str));
}
*/
