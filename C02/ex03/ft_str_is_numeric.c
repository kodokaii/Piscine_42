/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/09 15:05:16 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (*str < '0' || '9' < *str)
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

	str = "0123456789";
	printf("str = \"%s\", isnumeric = %d\n", str, ft_str_is_numeric(str));
	str = "/";
	printf("str = \"%s\", isnumeric = %d\n", str, ft_str_is_numeric(str));
	str = ":";
	printf("str = \"%s\", isnumeric = %d\n", str, ft_str_is_numeric(str));
	str = "";
	printf("str = \"%s\", isnumeric = %d\n", str, ft_str_is_numeric(str));
}
*/
