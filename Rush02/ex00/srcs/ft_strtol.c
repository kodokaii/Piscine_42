/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/23 15:13:40 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_strtol(char *str, char **end)
{
	long	res;
	int		sign;

	res = 0;
	*end = str;
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (*str < '0' || '9' < *str)
		return (0);
	while ('0' <= *str && *str <= '9')
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	*end = str;
	return (res * sign);
}
