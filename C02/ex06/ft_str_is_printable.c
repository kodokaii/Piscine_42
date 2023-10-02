/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/08 22:09:55 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (*str < ' ' || 127 <= *str)
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
	char	c[2];
	
	c[1] = 0;
	c[0] = 127;
	str = "abcdefghijklmnopqrstuvwxyz";
	printf("str = \"%s\", isprintable = %d\n", str, ft_str_is_printable(str));
	str = " ";
	printf("str = \"%s\", isprintable = %d\n", str, ft_str_is_printable(str));
	str = c;
	printf("str = \"[Del]\", isprintable = %d\n", ft_str_is_printable(str));
	c[0] = 31;
	printf("str = \"[UNIT SEP]\", isprintable = %d\n", ft_str_is_printable(str));
	str = "";
	printf("str = \"%s\", isprintable = %d\n", str, ft_str_is_printable(str));
}
*/
