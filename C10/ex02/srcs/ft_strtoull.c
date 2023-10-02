/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/18 13:13:03 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

unsigned long long	ft_strtoull(char *str, char **end)
{
	unsigned long long	res;
	int					sign;

	res = 0;
	sign = 1;
	*end = str;
	while (('\t' <= **end && **end <= '\r') || **end == ' ')
		(*end)++;
	if (**end == '+' || **end == '-')
	{
		if (**end == '-')
			sign *= -1;
		(*end)++;
	}
	while ('0' <= **end && **end <= '9')
	{
		res = res * 10 + **end - '0';
		if (res * 10 + **end - '0' < res)
			errno = ERANGE;
		(*end)++;
	}
	return (res * sign);
}
