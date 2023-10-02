/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/10 22:42:02 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(char *str, char to_find)
{
	while (*str)
	{
		if (*str == to_find)
			return (str);
		str++;
	}
	if (!to_find)
		return (str);
	return (0);
}

unsigned int	find_pos(char *str, char to_find)
{
	unsigned int	pos;

	pos = 0;
	while (str[pos])
	{
		if (str[pos] == to_find)
			return (pos);
		pos++;
	}
	return (-1);
}

int	base_ok(char *base)
{
	unsigned int	i;

	if (!base[0] || !base[1])
		return (0);
	while (*base)
	{
		i = 1;
		while (base[i])
		{
			if (*base == base[i])
				return (0);
			i++;
		}
		if (*base == '+' || *base == '-')
			return (0);
		if (('\t' <= *base && *base <= '\r') || *base == ' ')
			return (0);
		base++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	base_sz;
	int				res;
	int				sign;

	res = 0;
	sign = 1;
	if (base_ok(base))
	{
		base_sz = ft_strlen(base);
		while (('\t' <= *str && *str <= '\r') || *str == ' ')
			str++;
		while (*str == '+' || *str == '-')
		{
			if (*str == '-')
				sign *= -1;
			str++;
		}
		while (*str && ft_strchr(base, *str))
		{
			res *= base_sz;
			res += find_pos(base, *str);
			str++;
		}
	}
	return (res * sign);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (1 < argc)
	{
		printf("ft_atoi_base = '%d'\n", ft_atoi_base(argv[1], argv[2]));
	}
	else
		printf("required 'nb' 'base'\n");
}
*/
