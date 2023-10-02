/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/19 16:33:38 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	while (*tab)
	{
		if ((*f)(*tab))
			return (1);
		tab++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <stdlib.h>

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

int	main(int argc, char *argv[])
{
	if (1 < argc)
	{
		argv++;
		argc--;
		printf("ft_any = %d\n", ft_any(argv, &ft_str_is_alpha));
	}
	else
		printf("required 's1' ...\n");
}
*/
