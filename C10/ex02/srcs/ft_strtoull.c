/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/08/20 11:25:22 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <limits.h>

unsigned long long	ft_strtoull(char *str, char **end)
{
	unsigned long long	res;

	res = 0;
	*end = str;
	while (('\t' <= **end && **end <= '\r') || **end == ' ')
		(*end)++;
	if (**end == '+')
		(*end)++;
	while ('0' <= **end && **end <= '9')
	{
		if (res * 10 + **end - '0' < res)
			errno = ERANGE;
		res = res * 10 + **end - '0';
		(*end)++;
	}
	return (res);
}
